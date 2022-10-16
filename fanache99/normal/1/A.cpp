#include<stdio.h>
using namespace std;
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int n,m,a;
    long long l,c;
    scanf("%d%d%d",&n,&m,&a);
    l=n/a;
    c=m/a;
    if(n%a!=0)
        l++;
    if(m%a!=0)
        c++;
    printf("%I64d",l*c);
    return 0;
}