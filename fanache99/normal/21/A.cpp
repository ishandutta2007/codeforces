#include<stdio.h>
#include<cstring>
using namespace std;
char s[1001];
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int n,i=0,pp=0,l;
    gets(s);
    n=strlen(s);
    while(s[i]!='@'&&i<=n-1&&pp==0){
        if((s[i]<'0'||s[i]>'9')&&(s[i]<'a'||s[i]>'z')&&(s[i]>'Z'||s[i]<'A')&&s[i]!='_')
            pp=1;
        i++;
    }
    if(pp==1)
        printf("NO");
    else
        if(i==n||i==0)
            printf("NO");
        else{
            i++;
            l=0;
            while(pp==0&&i<=n-1&&s[i]!='/'){
                if((s[i]<'0'||s[i]>'9')&&(s[i]<'a'||s[i]>'z')&&(s[i]>'Z'||s[i]<'A')&&s[i]!='_'&&s[i]!='.')
                    pp=1;
                if(s[i]=='.')
                    if(l==0)
                        pp=1;
                    else
                        l=0;
                else
                    l++;
                i++;
            }
            if(pp==1||s[i-1]=='@'||l==0)
                printf("NO");
            else
                if(i<=n-1&&s[i]=='/'){
                    i++;
                    while(pp==0&&i<=n-1){
                        if((s[i]<'0'||s[i]>'9')&&(s[i]<'a'||s[i]>'z')&&(s[i]>'Z'||s[i]<'A')&&s[i]!='_')
                            pp=1;
                        i++;
                    }
                    if(pp==1||s[i-1]=='/')
                        printf("NO");
                    else
                        printf("YES");
                }
                else
                    printf("YES");
        }
    return 0;
}