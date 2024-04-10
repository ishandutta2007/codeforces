#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,m,val[1001],a[1001],b[1001];
long long dp[2001],ans;
pair<int,int> w[1001];
inline bool cmp(pair<int,int> x,pair<int,int> y)
{
    return 1.0*x.first/x.second>1.0*y.first/y.second;
}
int main()
{
    cin>>t;
    val[1]=0;
    for(int i=2;i<=1000;++i)
        val[i]=1e9;
    for(int i=1;i<=1000;++i)
        for(int x=1;x<=i;++x)
            if(i+i/x<=1000)
                val[i+i/x]=min(val[i+i/x],val[i]+1);
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<=2000;++i)
            dp[i]=0;
        ans=0;
        long long sum=0;
        int tot=m;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        for(int i=1;i<=n;++i)
        {
            cin>>b[i];
            if(!val[a[i]])
            {
                sum+=b[i];
                w[i]={0,1e9};
            }
            else
                w[i]={b[i],val[a[i]]};
        }
        sort(w+1,w+n+1,cmp);
        for(int i=1;i<=n;++i)
            if(tot-w[i].second>=1000)
            {
                tot-=w[i].second;
                sum+=w[i].first;
            }
            else
                for(int j=2000;j>=w[i].second;--j)
                    dp[j]=max(dp[j],dp[j-w[i].second]+w[i].first);
        for(int i=0;i<=min(2000,tot);++i)
            ans=max(ans,dp[i]);
        cout<<ans+sum<<'\n';
    }
    return 0;
}