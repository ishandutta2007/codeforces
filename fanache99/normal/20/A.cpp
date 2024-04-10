#include <stdio.h>
#include<cstring>
using namespace std;
char s[101];
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int n,i;
    scanf("%s",&s);
    n=strlen(s);
    while(s[n-1]=='/'&&n>1)
        n--;
    for(i=0;i<=n-1;i++)
        if(s[i]!='/'||s[i-1]!='/')
            printf("%c",s[i]);
    return 0;
}