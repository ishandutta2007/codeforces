#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long
int n,m,ans,dp[1<<19][21];
bool e[21][21];
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int x,y;
        cin>>x>>y;
        e[x][y]=e[y][x]=1;
    }
    for(int i=1;i<=n;++i)
        dp[1<<(i-1)][i]=1;
    for(int s=0;s<1<<n;++s)
        for(int i=1;i<=n;++i)
            if(dp[s][i])
            {
                ans+=e[i][__builtin_ctz(s)+1]*dp[s][i];
                for(int j=__builtin_ctz(s)+2;j<=n;++j)
                    if(!(s>>(j-1)&1))
                        dp[s|(1<<(j-1))][j]+=e[i][j]*dp[s][i];
            }
    cout<<((ans-m)>>1)<<'\n';
    return 0;
}