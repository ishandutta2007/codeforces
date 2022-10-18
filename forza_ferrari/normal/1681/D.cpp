#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
#define int long long
int n,m;
map<int,int> mp;
inline int dfs(int x)
{
    if(mp.count(x))
        return mp[x];
    int val=x,maxn=0,cnt=0;
    bool vis[10]={0};
    while(val)
    {
        maxn=max(maxn,val%10);
        vis[val%10]=1;
        val/=10;
        ++cnt;
    }
    if(cnt>=n)
        return mp[x]=0;
    if(maxn<=1)
        return mp[x]=1e9;
    val=1e9;
    for(int i=maxn;i>=2;--i)
        if(vis[i])
            val=min(val,dfs(x*i)+1);
    return mp[x]=val;
}
signed main()
{
    cin>>n>>m;
    int ans=dfs(m);
    cout<<(ans==1e9? -1:ans)<<'\n';
    return 0;
}