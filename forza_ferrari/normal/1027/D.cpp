#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int n,a[200001],c[200001],s[200001],d[200001],minn,ans;
bool vis[200001];
inline void topo()
{
    queue<int> q;
    for(int i=1;i<=n;++i)
        if(!d[i])
            q.push(i);
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
        vis[k]=1;
        if(!--d[a[k]])
            q.push(a[k]);
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>c[i];
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        ++d[a[i]];
    }
    topo();
    for(int i=1;i<=n;++i)
        if(!vis[i])
        {
            minn=1e9;
            for(int j=i;!vis[j];j=a[j])
            {
                minn=min(minn,c[j]);
                vis[j]=1;
            }
            ans+=minn;
        }
    cout<<ans<<'\n';
    return 0;
}