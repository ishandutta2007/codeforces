#include<bits/stdc++.h>
#define mod 1000000007
#define maxn 5001

using namespace std;
typedef long long ll;

ll a[maxn][maxn],n,k,ans,o;
ll pow(ll x,ll y)
{
    ll tmp=1;
    while (y){
        if (y&1) tmp=tmp*x%mod;
        x=x*x%mod; y>>=1;
    }
    return tmp;
}

int main()
{
    scanf("%d%d",&n,&k);
    a[1][1]=1; o=1;
    for (int i=2;i<=k;i++)
        for (int j=1;j<=i;j++)
            a[i][j]=(a[i-1][j-1]+a[i-1][j]*j)%mod;
    for (int i=1;i<=min(n,k);i++)
        o=o*(n-i+1)%mod,ans=(ans+a[k][i]*pow(2ll,n-i)%mod *o%mod)%mod;
    printf("%d\n",ans);
    return 0;
}