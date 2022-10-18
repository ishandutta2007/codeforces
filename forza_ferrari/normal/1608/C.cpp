#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;
struct element
{
    int a,b,id;
}q[100001];
struct edge
{
    int nxt,to;
}e[100001<<2];
int T,n,h[100001],tot,dfn[100001],low[100001],cnt,col[100001],d[100001];
bool vis[100001];
stack<int> t;
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
void tarjan(int k)
{
    dfn[k]=++cnt;
    low[k]=cnt;
    vis[k]=1;
    t.push(k);
    for(register int i=h[k];i;i=e[i].nxt)
    {
        if(!dfn[e[i].to])
        {
            tarjan(e[i].to);
            low[k]=min(low[k],low[e[i].to]);
        }
        else
            if(vis[e[i].to])
                low[k]=min(low[k],dfn[e[i].to]);
    }
    if(dfn[k]==low[k])
    {
        vis[k]=0;
        col[k]=k;
        while(!t.empty()&&t.top()!=k)
        {
            col[t.top()]=k;
            vis[t.top()]=0;
            t.pop();
        }
        if(!t.empty())
            t.pop();
    }
}
inline bool cmp1(element a,element b)
{
    return a.a<b.a;
}
inline bool cmp2(element a,element b)
{
    return a.b<b.b;
}
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>q[i].a;
            q[i].id=i;
        }
        for(int i=1;i<=n;++i)
            cin>>q[i].b;
        tot=0;
        for(int i=1;i<=n;++i)
            d[i]=dfn[i]=low[i]=vis[i]=col[i]=h[i]=0;
        cnt=0;
        while(!t.empty())
            t.pop();
        sort(q+1,q+n+1,cmp1);
        for(int i=2;i<=n;++i)
            add(q[i].id,q[i-1].id);
        sort(q+1,q+n+1,cmp2);
        for(int i=2;i<=n;++i)
            add(q[i].id,q[i-1].id);
        for(int i=1;i<=n;++i)
            if(!dfn[i])
                tarjan(i);
        for(int k=1;k<=n;++k)
            for(int i=h[k];i;i=e[i].nxt)
                if(col[k]^col[e[i].to])
                    ++d[col[e[i].to]];
        for(int i=1;i<=n;++i)
            putchar(d[col[i]]? '0':'1');
        puts("");
    }
    return 0;
}