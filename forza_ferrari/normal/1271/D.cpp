#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,m,s,a[5001],b[5001],c[5001],maxn[5001],dp[5001][5001];
vector<int> v[5001];
int main()
{
    cin>>n>>m>>s;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i]>>b[i]>>c[i];
        maxn[i]=i;
    }
    for(int i=1;i<=m;++i)
    {
        int x,y;
        cin>>x>>y;
        maxn[y]=max(maxn[y],x);
    }
    for(int i=1;i<=n;++i)
        v[maxn[i]].emplace_back(i);
    for(int i=0;i<=n;++i)
        for(int j=0;j<=5000;++j)
            dp[i][j]=-1e9;
    dp[0][s]=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=a[i];j<=5000-b[i];++j)
            dp[i][j+b[i]]=dp[i-1][j];
        for(int j:v[i])
            for(int k=1;k<=5000;++k)
                dp[i][k-1]=max(dp[i][k-1],dp[i][k]+c[j]);
    }
    int ans=-1e9;
    for(int i=0;i<=5000;++i)
        ans=max(ans,dp[n][i]);
    if(ans<0)
        puts("-1");
    else
        cout<<ans<<'\n';
    return 0;
}