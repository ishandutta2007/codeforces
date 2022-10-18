#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
struct edge
{
    int nxt,to;
}e[100001<<1];
int t,n,tot,h[100001],d[100001];
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
inline void dfs(int k,int f,int deep)
{
    if(deep&1)
        d[k]*=-1;
    for(int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs(e[i].to,k,deep+1);
    }
}
signed main()
{
    cin>>t;
    while(t--)
    {
        tot=0;
        cin>>n;
        for(int i=1;i<=n;++i)
            d[i]=h[i]=0;
        for(int i=1;i<n;++i)
        {
            int x,y;
            cin>>x>>y;
            ++d[x],++d[y];
            add(x,y);
            add(y,x);
        }
        dfs(1,0,0);
        for(int i=1;i<=n;++i)
            cout<<d[i]<<" ";
        cout<<'\n';
    }
    return 0;
}