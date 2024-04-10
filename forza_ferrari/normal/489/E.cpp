#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,x[1001],val[1001],pre[1001];
double dp[1001];
inline bool check(double mid)
{
    for(int i=0;i<=n;++i)
    {
        dp[i]=1e9;
        pre[i]=0;
    }
    dp[0]=0.0000;
    for(int i=1;i<=n;++i)
        for(int j=0;j<i;++j)
        {
            double w=dp[j]+sqrt(abs(m-x[i]+x[j]))-val[i]*mid;
            if(w<dp[i])
            {
                dp[i]=w;
                pre[i]=j;
            }
        }
    return dp[n]<=0.000;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>x[i]>>val[i];
    double l=1e-6,r=1e6,mid;
    for(int i=1;i<=50;++i)
    {
        mid=(l+r)/2;
        if(check(mid))
            r=mid;
        else
            l=mid;
    }
    check(l);
    vector<int> v;
    for(int i=n;i;i=pre[i])
        v.emplace_back(i);
    reverse(v.begin(),v.end());
    for(auto i:v)
        cout<<i<<" ";
    cout<<'\n';
    return 0;
}