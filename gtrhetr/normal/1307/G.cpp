#include<bits/stdc++.h>
using namespace std;
#define inf 2333333333333333333LL
#define ll long long
#define pll pair<ll,ll>
 
struct node { ll s,t,v,c,op,next; }a[10010];
 
queue<ll> q;

pll h[10010];

double ans[100010];
ll head[210],dis[210],n,m,p,vs,vt,tot,flow,cost;
bool inq[210],vis[210];
 
inline ll rd()
{
    ll x=0;char ch=getchar();
    for (;ch<'0'||ch>'9';ch=getchar());
    for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
    return x;
}
 
inline void add(ll x,ll y,ll z,ll c)
{
    a[++tot].s=x;a[tot].t=y;a[tot].v=z;a[tot].c=c;
    a[tot].op=tot+1;a[tot].next=head[x];head[x]=tot;
    a[++tot].s=y;a[tot].t=x;a[tot].v=0;a[tot].c=-c;
    a[tot].op=tot-1;a[tot].next=head[y];head[y]=tot;
}
 
inline bool spfa()
{
    while (!q.empty()) q.pop();
    for (int i=1;i<=n;i++) dis[i]=inf;
    memset(inq,false,sizeof(inq));
    q.push(vt);dis[vt]=0;inq[vt]=true;
    while (!q.empty())
    {
        ll x=q.front();q.pop();
        for (ll i=head[x];i;i=a[i].next) if (a[a[i].op].v)
        {
            ll t=a[i].t;
            if (dis[t]>dis[x]-a[i].c)
            {
                dis[t]=dis[x]-a[i].c;
                if (!inq[t]) q.push(t),inq[t]=true;
            }
        }
        inq[x]=false;
    }
    return (dis[vs]!=inf);
}
 
inline ll dfs(ll x,ll y)
{
    if (x==vt||!y) return y;
    ll res=0;vis[x]=true;
    for (ll i=head[x];i;i=a[i].next)
    {
        ll t=a[i].t;
        if (vis[t]||!a[i].v||dis[t]!=dis[x]-a[i].c) continue;
        ll hh=dfs(t,min(y,a[i].v));
        if (!hh) continue;
        res+=hh;y-=hh;cost+=hh*a[i].c;
        a[i].v-=hh;a[a[i].op].v+=hh;
        if (!y) break;
    }
    return res;
}
 
int main()
{
    n=rd();m=rd();vs=1;vt=n;tot=0;
    for (ll i=1;i<=m;i++)
    {
        ll x=rd(),y=rd(),c=rd(),v=1;
        add(x,y,v,c);
    }
    ll tt=0;
    while (spfa())
    {
        do
        {
            memset(vis,false,sizeof(vis));
            flow+=dfs(vs,inf);
            h[++tt]=pll(flow,cost);
        }while (vis[vt]);
    }
    ll now=1;
    for (ll i=0;i<=100000;i++)
    {
    	while (now<tt&&(h[now+1].second+i)*h[now].first<=(h[now].second+i)*h[now+1].first) now++;
    	ans[i]=(double)(h[now].second+i)/h[now].first;
	}
    ll Q=rd();
    while (Q--) printf("%.10lf\n",ans[rd()]);
    return 0;
}