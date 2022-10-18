#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define int long long
struct edge
{
    int nxt,to;
}e[200001<<1];
int n,m,tot,h[200001],s[200001],d[200001],dep[200001],ans,fa[200001];
priority_queue<pair<int,int> > q;
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
void dfs(int k,int f,int deep)
{
    s[k]=1;
    dep[k]=deep;
    fa[k]=f;
    for(int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        ++d[k];
        dfs(e[i].to,k,deep+1);
        s[k]+=s[e[i].to];
    }
}
signed main()
{
    n=read(),m=read();
    for(int i=1;i<n;++i)
    {
        int x=read(),y=read();
        add(x,y);
        add(y,x);
    }
    dfs(1,0,1);
    for(int i=1;i<=n;++i)
        if(!d[i])
            q.push({dep[i]-1,i});
    for(int i=1;i<=m;++i)
    {
        pair<int,int> k=q.top();
        ans+=k.first;
        q.pop();
        if(!--d[fa[k.second]])
            q.push({dep[fa[k.second]]-s[fa[k.second]],fa[k.second]});
    }
    printf("%lld\n",ans);
    return 0;
}