#include <stdio.h>
using namespace std;
int vc[1000001];
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    long long n,d,m,l,p=0,pp=0;
    scanf("%I64d%I64d%I64d%I64d",&n,&d,&m,&l);
    while(pp==0){
        p+=d;
        if(p>m*(n-1)+l){
            pp=1;
            printf("%I64d",p);
        }
        else
            if(p%m>l){
                printf("%I64d",p);
                pp=1;
            }
            else
                if(vc[p%m]==1)
                    pp=1;
                else
                    vc[p%m]=1;
    }
    if(p<m*(n-1)+l&&p%m<=l)
        printf("%I64d",((m*(n-1)+l)/d+1)*d);
    return 0;
}