#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int mod=1000000007;
int n,m,dp[3001][3005],x[3005],y[3005];
vector<int> v[3001];
inline int pw(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)
            res=1ll*res*a%mod;
        b>>=1;
        a=1ll*a*a%mod;
    }
    return res;
}
inline int calc()
{
    int res=0;
    for(int i=1;i<=n+1;++i)
    {
        int sum=1;
        for(int j=1;j<=n+1;++j)
            if(i^j)
                sum=1ll*(m-x[j]+mod)%mod*pw((x[i]-x[j]+mod)%mod,mod-2)%mod*sum%mod;
        res=(res+1ll*y[i]*sum%mod)%mod;
    }
    return res;
}
inline void dfs(int k)
{
    for(int i=1;i<=n+1;++i)
        dp[k][i]=1;
    for(int i:v[k])
    {
        dfs(i);
        for(int j=1;j<=n+1;++j)
            dp[k][j]=1ll*dp[k][j]*dp[i][j]%mod;
    }
    for(int i=2;i<=n+1;++i)
        dp[k][i]=(dp[k][i]+dp[k][i-1])%mod;
}
int main()
{
    cin>>n>>m;
    for(int i=2;i<=n;++i)
    {
        int f;
        cin>>f;
        v[f].emplace_back(i);
    }
    dfs(1);
    for(int i=1;i<=n+1;++i)
        x[i]=i,y[i]=dp[1][i];
    cout<<calc()<<'\n';
    return 0;
}