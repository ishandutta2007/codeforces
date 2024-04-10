#include<stdio.h>
char t[128];
char h[10]="hello";
int main(){
    scanf("%s",t);
    int now=0;
    for(int i=0;t[i];i++){
        if(t[i]==h[now])now++;
    }
    if(now>4)printf("YES\n");
    else printf("NO\n");
}