#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long
int t,n,l[200001],r[200001],sum[200001],ans;
vector<int> v[200001];
inline void dfs(int k)
{
    for(auto i:v[k])
    {
        dfs(i);
        sum[k]+=sum[i];
    }
    if(sum[k]<l[k])
    {
        ++ans;
        sum[k]=r[k];
    }
    sum[k]=min(sum[k],r[k]);
}
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=0;
        for(int i=1;i<=n;++i)
        {
            sum[i]=l[i]=r[i]=0;
            v[i].clear();
        }
        for(int i=2;i<=n;++i)
        {
            int f;
            cin>>f;
            v[f].emplace_back(i);
        }
        for(int i=1;i<=n;++i)
            cin>>l[i]>>r[i];
        dfs(1);
        cout<<ans<<'\n';
    }
    return 0;
}