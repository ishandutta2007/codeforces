//by yjz
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
const ll mod=1e9+7;
int n,m;
char g[511][511];
ll dp[2][511][511];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",g[i]+1);
    }
    if(g[1][1]!=g[n][m])
    {
        puts("0");
        return 0;
    }
    dp[0][1][n]=1;
    for(int sum=2;sum<(n+m+2)/2;sum++)
    {
        int p=sum&1;
        for(int i=1;i<=n&&i<sum;i++)
        {
            int j=sum-i;
            if(j>m)continue;
            for(int ri=1;ri<=n;ri++)
            {
                int rj=m-(sum-(n-ri+1))+1;
                if(rj>m||rj<1||dp[p][i][ri]==0)continue;
                if(j<m&&ri>1&&g[i][j+1]==g[ri-1][rj])dp[!p][i][ri-1]=(dp[!p][i][ri-1]+dp[p][i][ri])%mod;
                if(j<m&&rj>1&&g[i][j+1]==g[ri][rj-1])dp[!p][i][ri]=(dp[!p][i][ri]+dp[p][i][ri])%mod;
                if(i<n&&ri>1&&g[i+1][j]==g[ri-1][rj])dp[!p][i+1][ri-1]=(dp[!p][i+1][ri-1]+dp[p][i][ri])%mod;
                if(i<n&&rj>1&&g[i+1][j]==g[ri][rj-1])dp[!p][i+1][ri]=(dp[!p][i+1][ri]+dp[p][i][ri])%mod;
            }
        }
        for(int i=0;i<510;i++)for(int j=0;j<510;j++)dp[p][i][j]=0;
    }
    ll ans=0;
    if((n+m)&1)
    {
        for(int i=1;i<=n;i++)
        {
            int j=(n+m+2)/2-i,p=((n+m+2)/2)&1;
            if(j<1||j>m)continue;
            ans=(ans+dp[p][i][i]+dp[p][i][i+1]%mod)%mod;
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            int j=(n+m+2)/2-i;
            if(j<1||j>m)continue;
            ans=(ans+dp[((n+m+2)/2)&1][i][i])%mod;
        }
    }
    printf("%I64d\n",ans);
    return 0;
}