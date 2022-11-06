#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200010
#define ll long long
using namespace std;
int nxt[N<<1],to[N<<1],head[N],cnt=1;
ll w[N<<1],wval[N<<1];
void add(int u,int v,ll w1)
{
    nxt[++cnt]=head[u];
    to[cnt]=v;
    w[cnt]=w1;
    head[u]=cnt;
}
int id[N],lid[N],rid[N],tid;
ll wd[N],pos[N];
void dfs(int u,int p)
{
    id[lid[u]=++tid]=u;
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if(v==p) continue;
        pos[i>>1]=v;
        wd[v]=wd[u]+w[i];
        dfs(v,u);
        id[++tid]=u;
    }
    rid[u]=tid;
}
namespace segment
{
    #define M N<<2
    ll mx[M],mn[M],vl[M],vr[M],val[M],tag[M];
    void update(int u)
    {
        mx[u]=max(mx[u<<1],mx[u<<1|1]);
        mn[u]=max(mn[u<<1],mn[u<<1|1]);
        vl[u]=max(vl[u<<1],vl[u<<1|1]);vl[u]=max(vl[u],mx[u<<1]+mn[u<<1|1]);
        vr[u]=max(vr[u<<1],vr[u<<1|1]);vr[u]=max(vr[u],mn[u<<1]+mx[u<<1|1]);
	    val[u]=max(max(val[u<<1],val[u<<1|1]),max(vl[u<<1]+mx[u<<1|1],mx[u<<1]+vr[u<<1|1]));
    }
    void set_tag(int u,ll v)
    {
        mx[u]+=v,mn[u]-=2*v;
        vl[u]-=v,vr[u]-=v;
        tag[u]+=v;
    }
    void push_down(int u)
    {
        if(!tag[u]) return;
        set_tag(u<<1,tag[u]),set_tag(u<<1|1,tag[u]);tag[u]=0;
    }
    void build(int u,int l,int r)
    {
        if(l==r){set_tag(u,wd[id[l]]);tag[u]=val[u]=0;return;}
        int mid=(l+r)>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
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
}
int main()
{
    int n,m;
    ll k;
    scanf("%d%d%lld",&n,&m,&k);
    for(int i=1;i<n;i++)
    {
        int u,v;
        ll w;
        scanf("%d%d%lld",&u,&v,&w);wval[i]=w;
        add(u,v,w),add(v,u,w);
    }
    dfs(1,0);
    segment::build(1,1,tid);
    ll las=0;
    while(m --> 0)
    {
		int u;ll v;
        scanf("%d%lld",&u,&v);
        u=(u+las)%(n-1)+1;v=(v+las)%k;
        v=v-wval[u];
        segment::insert(1,1,tid,lid[pos[u]],rid[pos[u]],v);
		wval[u]+=v;
        printf("%lld\n",las=segment::val[1]);
    }
    return 0;
}