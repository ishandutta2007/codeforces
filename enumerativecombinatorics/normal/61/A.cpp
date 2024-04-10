#include<stdio.h>
char t[101];
char s[101];
int main(){
    scanf("%s%s",t,s);
    for(int i=0;t[i];i++)printf((t[i]-s[i])?"1":"0");
    printf("\n");
}