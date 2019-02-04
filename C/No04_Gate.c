#include <stdio.h>
#include <stdlib.h>

void parse(char *str, int *h, int *w, int *n){
    char *temp;
    temp=str;
    while(*str!=' '){
        str++;
    }
    *str++=0;
    *h=atoi(temp);
    
    temp=str;
    while(*str!=' '){
        str++;
    }
    *str++=0;
    *w=atoi(temp);

    *n=atoi(str);
}

void move(char m, int *px, int *py){
    switch(m){
        case 'U': (*py)++; break;
        case 'D': (*py)--; break;
        case 'L': (*px)--; break;
        case 'R': (*px)++; break;
        default: break;
    }
}

int main(void){
    // 自分の得意な言語で
    // Let's チャレンジ！！

    char str[1000];
    fgets(str, sizeof(str), stdin);
    int h, w, n;
    
    parse(str, &h, &w, &n);
    int px=0, py=0;
    bool isinvalid = true;
    for(int i=0; i<n; i++){
        fgets(str, sizeof(str), stdin);
        move(str[0], &px, &py);
        //printf("%c %d %d\n", str[0], px, py);
        if(px<0 || w<=px || py<0 || h<=py){
            isinvalid = false;
        }
    }
    if(isinvalid){
       printf("valid\n");
    }else{
       printf("invalid\n");
    }
    return 0;
}
