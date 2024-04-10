#include<bits/stdc++.h>
#define maxn 105
#define mod 1000000007
using namespace std;
typedef long long ll;
char s[maxn];
ll dp[maxn][maxn][maxn],n,k,f[maxn],p[maxn],d,r;

ll pow_(ll x,ll y)
{
    ll rt=1;
    while (y){
        if (y&1) rt=rt*x%mod;
        x=x*x%mod; y>>=1;
    }
    return rt;
}

int main()
{
    f[0]=1; f[1]=1;
    for (int i=2;i<maxn;i++) f[i]=(f[i-1]+f[i-2])%(mod-1);
    for (int i=0;i<maxn;i++) p[i]=pow_(2ll,f[i]);
    scanf("%d%d",&n,&k); scanf("%s",s);
    for (int i=0;i<n;i++) if (s[i]=='0') dp[0][i][i+1]=1; else dp[1][i][i+1]=1;
    for (int i=0;i<=n;i++) dp[0][i][i]=1;
    for (int i=2;i<=k;i++)
    {
        for (int j=0;j<=n;j++) dp[i][j][j]=1;
        for (int d=1;d<=n;d++)
        {
            for (int l=0;l+d<=n;l++)
            {
                r=l+d;
                for (int k=l+1;k<r;k++) dp[i][l][r]=(dp[i][l][r]+dp[i-1][l][k]*dp[i-2][k][r])%mod;
                if (l==0) dp[i][l][r]=(dp[i][l][r]+dp[i-2][l][r]*p[i-1])%mod;
                else dp[i][l][r]=(dp[i][l][r]+dp[i-2][l][r])%mod;
                if (r==n) dp[i][l][r]=(dp[i][l][r]+dp[i-1][l][r]*p[i-2])%mod;
                else dp[i][l][r]=(dp[i][l][r]+dp[i-1][l][r])%mod;
            }
        }
    }
    cout << dp[k][0][n] << endl;
}