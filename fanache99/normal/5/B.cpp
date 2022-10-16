#include<stdio.h>
using namespace std;
int l[1001];
char a[1001][1001];
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int max=-1,n=1,i,pp=1,d,j,s;
    char c;
    while(scanf("%c",&c)!=EOF)
        if(c!='\n'){
            l[n]++;
            a[n][l[n]]=c;
        }
        else{
            if(l[n]>max)
                max=l[n];
            n++;
        }
    n--;
    for(i=0;i<=max+1;i++)
        printf("*");
    printf("\n");
    for(j=1;j<=n;j++){
        printf("*");
        if(l[j]==0)
            for(i=1;i<=max;i++)
                printf(" ");
        else{
            d=max-l[j];
            if(d%2==0){
                for(i=1;i<=d/2;i++)
                    printf(" ");
                for(i=1;i<=l[j];i++)
                    printf("%c",a[j][i]);
                for(i=1;i<=d/2;i++)
                    printf(" ");
            }
            else{
                if(pp%2==0){
                    d/=2;
                    s=d+1;
                }
                else{
                    s=d/2;
                    d=s+1;
                }
                for(i=1;i<=s;i++)
                    printf(" ");
                for(i=1;i<=l[j];i++)
                    printf("%c",a[j][i]);
                for(i=1;i<=d;i++)
                    printf(" ");
                pp++;
            }
        }
        printf("*\n");
    }
    for(i=0;i<=max+1;i++)
        printf("*");
    return 0;
}