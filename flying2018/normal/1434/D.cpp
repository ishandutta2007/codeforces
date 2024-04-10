#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1000010
#define inf 1e8
using namespace std;
int nxt[N<<1],to[N<<1],head[N],cnt=1;
int w[N<<1];
void add(int u,int v,int w1)
{
    nxt[++cnt]=head[u];
    to[cnt]=v;
    w[cnt]=w1;
    head[u]=cnt;
}
int id[N],lid[N],rid[N],idx;
int dep[N],pos[N],wd[N];
namespace segment{
    int val[N<<2][2],maxn[N<<2],vl[N<<2][2],vr[N<<2][2],ml[N<<2][2],tag[N<<2];
    void update(int u)
    {
        maxn[u]=max(maxn[u<<1],maxn[u<<1|1]);
        for(int _=0;_<=1;_++) val[u][_]=max(val[u<<1][_],val[u<<1|1][_]) ,vl[u][_]=max(vl[u<<1][_],vl[u<<1|1][_]) ,vr[u][_]=max(vr[u<<1][_],vr[u<<1|1][_]) ,ml[u][_]=max(ml[u<<1][_],ml[u<<1|1][_]) ,vl[u][_]=max(vl[u][_],val[u<<1][_]+maxn[u<<1|1]) ,vr[u][_]=max(vr[u][_],maxn[u<<1]+val[u<<1|1][_]);
        for(int l=0;l<=1;l++)
            for(int r=0;r<=1;r++) ml[u][l^r]=max(ml[u][l^r],max(vl[u<<1][l]+val[u<<1|1][r],val[u<<1][l]+vr[u<<1|1][r]));
    }
    void set_tag(int u){swap(val[u][0],val[u][1]),swap(vl[u][0],vl[u][1]),swap(vr[u][0],vr[u][1]);tag[u]^=1;}
    void push_down(int u){if(!tag[u]) return;set_tag(u<<1),set_tag(u<<1|1);tag[u]=0;}
    void build(int u,int l,int r)
    {
        if(l==r){int x=id[l],i=wd[x]&1;val[u][i]=dep[x],maxn[u]=-2*dep[x];vl[u][i]=vr[u][i]=-dep[x];return;}
        int mid=(l+r)>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        update(u);
    }
    void insert(int u,int l,int r,int L,int R)
    {
        if(L<=l && r<=R){set_tag(u);return;}
        int mid=(l+r)>>1;push_down(u);
        if(L<=mid) insert(u<<1,l,mid,L,R);
        if(R>mid) insert(u<<1|1,mid+1,r,L,R);
        update(u);
    }
}
void dfs(int u,int p)
{
    dep[u]=dep[p]+1;
    id[lid[u]=++idx]=u;
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if(v==p) continue;
        pos[i>>1]=v;wd[v]=wd[u]+w[i];
        dfs(v,u);id[++idx]=u;
    }
    rid[u]=idx;
}
int main()
{
    memset(segment::val,0xcf,sizeof(segment::val));
    memset(segment::vl,0xcf,sizeof(segment::vl));
    memset(segment::vr,0xcf,sizeof(segment::vr));
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w),add(v,u,w);
    }
    dep[0]=-1;
    dfs(1,0);segment::build(1,1,idx);
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int x;
        scanf("%d",&x);
        segment::insert(1,1,idx,lid[pos[x]],rid[pos[x]]);
		printf("%d\n",segment::ml[1][0]);
    }
    return 0;
}