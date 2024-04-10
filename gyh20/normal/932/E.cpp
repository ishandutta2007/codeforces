#include<iostream>
#include<cstdio>
using namespace std;
#define M 1000000007
#define inv2 500000004
int fpow(int a,int b){int s=1;while(b){if(b&1)s=1ll*s*a%M;a=1ll*a*a%M;b>>=1;}return s;}
int n,k,s[5002][5002],ans;
int main()
{
    scanf("%d%d",&n,&k);s[0][0]=1;
    for(int i=1;i<=k;++i)
        for(int j=1;j<=k;++j)
            s[i][j]=(s[i-1][j-1]+1ll*s[i-1][j]*j)%M;
    for(int j=0,pw=fpow(2,n),nw=1;j<=min(n,k);pw=1ll*pw*inv2%M,nw=1ll*nw*(n-j)%M,++j)
        ans=(ans+1ll*s[k][j]*nw%M*pw%M)%M;
    printf("%d\n",ans);
    return 0;
}