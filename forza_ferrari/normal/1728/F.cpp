#include<iostream>
#include<cstdio>
#include<unordered_map>
using namespace std;
int n,m,a[1001];
long long ans;
unordered_map<int,int> pre,nxt,match;
unordered_map<int,bool> vis;
inline int dfs(int k)
{
    vis[k]=1;
    int minn=1e9;
    for(int i=k;;i+=k)
    {
        if(!match.count(i))
        {
            pre[i]=k;
            minn=min(minn,i);
            break;
        }
        if(!vis.count(match[i]))
        {
            pre[i]=k;
            nxt[match[i]]=i;
            minn=min(minn,dfs(match[i]));
        }
    }
    return minn;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        pre.clear();
        nxt.clear();
        vis.clear();
        int res;
        ans+=res=dfs(a[i]);
        while(res)
        {
            match[res]=pre[res];
            res=nxt[pre[res]];
        }
    }
    cout<<ans<<'\n';
    return 0;
}