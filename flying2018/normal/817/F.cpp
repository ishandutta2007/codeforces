#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define N 400010
using namespace std;
ll p[N*4];
struct ques{
    int opt;
    ll l,r;
}q[N];
int tt;
int val[N<<2][2],tag[N<<2];
void update(int u){val[u][0]=min(val[u<<1][0],val[u<<1|1][0]);val[u][1]=min(val[u<<1][1],val[u<<1|1][1]);}
void build(int u,int l,int r)
{
    tag[u]=-2;
    if(l==r){val[u][0]=l;val[u][1]=tt+1;return;}
    int mid=(l+r)>>1;
    build(u<<1,l,mid),build(u<<1|1,mid+1,r);update(u);
}
void set_tag(int u,int v,int l,int r)
{
    if(v==-1) swap(val[u][0],val[u][1]),tag[u]^=1;
    else tag[u]=v,val[u][v]=l,val[u][!v]=tt+1;
}
void push_down(int u,int l,int r)
{
    if(tag[u]==-2) return;
    int mid=(l+r)>>1;
    set_tag(u<<1,tag[u],l,mid),set_tag(u<<1|1,tag[u],mid+1,r);tag[u]=-2;
}
void assign(int u,int l,int r,int L,int R,int v)
{
    if(L<=l && r<=R){set_tag(u,v,l,r);return;}
    int mid=(l+r)>>1;
    push_down(u,l,r);
    if(L<=mid) assign(u<<1,l,mid,L,R,v);
    if(R>mid) assign(u<<1|1,mid+1,r,L,R,v);
    update(u);
}
int main()
{
    int n;
    scanf("%d",&n);
    p[++tt]=1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%lld%lld",&q[i].opt,&q[i].l,&q[i].r);
        p[++tt]=q[i].l;
        p[++tt]=q[i].r;
        p[++tt]=q[i].r+1;
    }
    sort(p+1,p+tt+1);
    tt=unique(p+1,p+tt+1)-p-1;
    p[tt+1]=1e18+5;
    for(int i=1;i<=n;i++) q[i].l=lower_bound(p+1,p+tt+1,q[i].l)-p,q[i].r=lower_bound(p+1,p+tt+1,q[i].r)-p;
    for(int i=1;i<=n;i++)
    {
        if(q[i].opt==1) assign(1,1,tt,q[i].l,q[i].r,1);
        else if(q[i].opt==2) assign(1,1,tt,q[i].l,q[i].r,0);
        else assign(1,1,tt,q[i].l,q[i].r,-1);
        printf("%lld\n",p[val[1][0]]);
    }
    return 0;
}