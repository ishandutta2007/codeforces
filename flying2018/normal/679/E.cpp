#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#define N 400010
#define ll long long
using namespace std;
ll val[N],tag[N],add[N],a[N];
set<ll>s;
void set_tag(int u,ll v)
{
    add[u]=0;tag[u]=v;
    val[u]=*s.lower_bound(v)-v;
}
void add_tag(int u,ll v)
{
    val[u]-=v;
    if(tag[u]) tag[u]+=v;
    else add[u]+=v;
}
void push_down(int u)
{
    if(tag[u]){set_tag(u<<1,tag[u]),set_tag(u<<1|1,tag[u]),tag[u]=0;return;}
    else if(add[u]){add_tag(u<<1,add[u]);add_tag(u<<1|1,add[u]);add[u]=0;return;}
}
void update(int u){val[u]=min(val[u<<1],val[u<<1|1]);}
void build(int u,int l,int r)
{
    if(l==r){set_tag(u,a[l]);return;}
    int mid=(l+r)>>1;
    build(u<<1,l,mid),build(u<<1|1,mid+1,r);
    update(u);
}
void insert(int u,int l,int r,int L,int R,ll v)
{
    if(L<=l && r<=R){set_tag(u,v);return;}
    int mid=(l+r)>>1;
    push_down(u);
    if(L<=mid) insert(u<<1,l,mid,L,R,v);
    if(R>mid) insert(u<<1|1,mid+1,r,L,R,v);
    update(u);
}
void change(int u,int l,int r,int L,int R,ll v)
{
    if(L<=l && r<=R)
    {
        // printf("-- %d %d %d %d %d\n",u,l,r,tag[u],val[u]);
        if(val[u]>=v){add_tag(u,v);return;}
        if(tag[u]){set_tag(u,tag[u]+v);return;}
    }
    int mid=(l+r)>>1;
    push_down(u);
    if(L<=mid) change(u<<1,l,mid,L,R,v);
    if(R>mid) change(u<<1|1,mid+1,r,L,R,v);
    update(u);
}
ll answer(int u,int l,int r,int p)
{
    if(l==r) return tag[u];
    int mid=(l+r)>>1;
    push_down(u);
    if(p<=mid) return answer(u<<1,l,mid,p);
    else return answer(u<<1|1,mid+1,r,p);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(ll v=1;v<=1e16;v=v*42) s.insert(v);
    build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        int op,l,r,v;
        scanf("%d%d",&op,&l);
        if(op==1){printf("%lld\n",answer(1,1,n,l));continue;}
        scanf("%d%d",&r,&v);
        if(op==2) insert(1,1,n,l,r,v);
        else do change(1,1,n,l,r,v);while(val[1]==0);
    }
    return 0;
}