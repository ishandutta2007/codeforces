#include<bits/stdc++.h>
#define maxn 2005
#define mod 998244353

using namespace std;
typedef long long ll;
int n,m,p,q,a[maxn],b[maxn],c[maxn],g[maxn][maxn][11],h[maxn][maxn][11],r,query,t,ans,fc[maxn],fi[maxn];

int pow_(int x,int y)
{
    int rt=1;
    while (y){
        if (y&1) rt=1ll*rt*x%mod;
        x=1ll*x*x%mod;
        y>>=1;
    }
    return rt;
}

int f(int x,int y)
{
    if (x==0) return (y==0);
    return 1ll*fc[x+y-1]*fi[x-1]%mod;
}

int main()
{
    scanf("%d",&query);
    fc[0]=1; for (int i=1;i<maxn;i++) fc[i]=1ll*fc[i-1]*i%mod;
    for (int i=0;i<maxn;i++) fi[i]=pow_(fc[i],mod-2);
    while (query--)
    {
        for (int i=0;i<=n+m;i++) for (int j=0;j<=n+m;j++) for (int k=0;k<11;k++) g[i][j][k]=h[i][j][k]=0;
        scanf("%d",&p); n=0;m=0;
        while (p--)
        {
            scanf("%d",&q); r=0; t=q%11;
            while (q) q/=10,r++;
            if (r&1) a[++n]=t; else b[++m]=t;
        }
        g[0][0][0]=1;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<=i;j++)
                for (int k=0;k<11;k++)
                {
                    (g[i+1][j+1][(k+a[i+1])%11]+=g[i][j][k])%=mod,
                    (g[i+1][j][(k+11-a[i+1])%11]+=g[i][j][k])%=mod;
                }
        }
        h[0][0][0]=1;
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<=i;j++)
                for (int k=0;k<11;k++)
                    (h[i+1][j+1][(k+b[i+1])%11]+=h[i][j][k])%=mod,
                    (h[i+1][j][(k+11-b[i+1])%11]+=h[i][j][k])%=mod;
        }
        ans=0; p=(n+1)/2;
        for (int i=0;i<=m;i++)
            for (int k=0;k<11;k++)
            {
                t=1ll*g[n][p][k]*h[m][i][(11-k)%11]%mod;
                t=1ll*t*f(p,i)%mod;
                t=1ll*t*f(n-p+1,m-i)%mod;
                (ans+=t)%=mod;
            }
        ans=1ll*ans*fc[p]%mod;
        ans=1ll*ans*fc[n-p]%mod;
        cout << ans << endl;
    }
}