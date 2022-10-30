#include<stdio.h>
#include<string.h>
char s[128];
char t[128];
int main(){
    scanf("%s%s",s,t);
    bool ok=true;
    int p=strlen(s);
    for(int i=0;i<p;i++){
        if(s[i]!=t[p-i-1])ok=false;
    }
    printf(ok?"YES\n":"NO\n");
}