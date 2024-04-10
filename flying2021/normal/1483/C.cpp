#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#define N 300010
#define inf 10000000000000000ll
#define ll long long
using namespace std;
int pre[N],h[N],ph[N],b[N];
set<int>s;
void init(int n)
{
    for(int i=1;i<=n;i++) scanf("%d",&h[i]),ph[h[i]]=i;
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    s.insert(0);
    for(int i=1;i<=n;i++)
    {
        auto p=s.upper_bound(ph[i]);--p;
        pre[ph[i]]=*p;
        s.insert(ph[i]);
    }
}
ll vl[N<<2],ad[N<<2],tg[N<<2];
void build(int u,int l,int r)
{
    vl[u]=ad[u]=tg[u]=-inf;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
}
void set_tag(int u,ll v){ad[u]=vl[u]+v;tg[u]=v;}
void update(int u)
{
    vl[u]=max(vl[u<<1],vl[u<<1|1]);
    ad[u]=max(ad[u<<1],ad[u<<1|1]);
}
void push_down(int u){if(tg[u]!=-inf) set_tag(u<<1,tg[u]),set_tag(u<<1|1,tg[u]);tg[u]=-inf;}
void insert(int u,int l,int r,int L,int R,ll v)
{
    if(L<=l && r<=R){set_tag(u,v);return;}
    int mid=(l+r)>>1;push_down(u);
    if(L<=mid) insert(u<<1,l,mid,L,R,v);
    if(R>mid) insert(u<<1|1,mid+1,r,L,R,v);
    update(u);
}
void change(int u,int l,int r,int p,ll v)
{
    if(l==r){vl[u]=ad[u]=v;return;}
    int mid=(l+r)>>1;push_down(u);
    if(p<=mid) change(u<<1,l,mid,p,v);
    else change(u<<1|1,mid+1,r,p,v);
    update(u);
}
ll f[N];
int main()
{
    int n;
    scanf("%d",&n);
    init(n);
    build(1,1,n);
    ll mn=-inf,mv=n+1;
    for(int i=1;i<=n;i++)
    {
        f[i]=max(ad[1],mn);
        if(h[i]<mv) mv=h[i],mn=b[i];
        change(1,1,n,i,f[i]);
        insert(1,1,n,pre[i]+1,i,b[i]);
    }
    printf("%lld\n",max(ad[1],mn));
    return 0;
}