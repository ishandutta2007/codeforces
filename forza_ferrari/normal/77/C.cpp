#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
struct edge
{
    int nxt,to;
}e[100001<<1];
int n,root,tot,h[100001],dp[100001],a[100001],val[100001];
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
inline void dfs(int k,int f)
{
    dp[k]=1;
    int sum=0;
    vector<int> tmp;
    for(int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs(e[i].to,k);
        sum+=val[e[i].to];
        tmp.emplace_back(dp[e[i].to]);
    }
    sort(tmp.begin(),tmp.end(),greater<int>());
    val[k]=a[k]-1;
    for(int i=0;i<min((int)tmp.size(),a[k]-1);++i)
    {
        dp[k]+=tmp[i]+1;
        --val[k];
    }
    dp[k]+=min(sum,val[k])<<1;
    val[k]-=min(sum,val[k]);
}
signed main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<n;++i)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    cin>>root;
    ++a[root];
    dfs(root,0);
    cout<<dp[root]-1<<'\n';
    return 0;
}