#include<stdio.h>
#include<string.h>
char t[524288];
int main(){
    int a;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        scanf("%s",t);
        int size=strlen(t);
        if(size>10){
            printf("%c%d%c\n",t[0],size-2,t[size-1]);
        }else printf("%s\n",t);
    }
}