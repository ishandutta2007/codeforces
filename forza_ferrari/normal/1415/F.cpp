#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int n,t[5001],a[5001],minn[5001];
bool dp[5001][5001];
signed main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>t[i]>>a[i];
    for(int i=1;i<=n;++i)
        minn[i]=1e18;
    for(int i=0;i<n;++i)
        if(minn[i]<=t[i])
        {
            minn[i+1]=min(minn[i+1],max(t[i],minn[i]+abs(a[i+1]-a[i])));
            for(int j=i+2;j<=n;++j)
            {
                if(max(t[i],minn[i]+abs(a[j]-a[i]))+abs(a[i+1]-a[j])<=t[i+1])
                    dp[i+1][j]=1;
                if(abs(a[i+1]-a[i])<=t[i+1]-t[i])
                    dp[i+1][j]|=dp[i][j];
            }
            if(i+2>n)
                continue;
            if(dp[i][i+1])
            {
                minn[i+2]=min(minn[i+2],max(t[i+1],t[i]+abs(a[i+2]-a[i])));
                for(int j=i+3;j<=n;++j)
                    if(max(t[i+1],t[i]+abs(a[j]-a[i]))+abs(a[i+2]-a[j])<=t[i+2])
                        dp[i+2][j]=1;
            }
        }
    cout<<(minn[n]<=t[n]||dp[n-1][n]? "YES":"NO")<<'\n';
    return 0;
}