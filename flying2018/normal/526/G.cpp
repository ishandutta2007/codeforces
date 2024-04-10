#include<iostream>
#include<cstring>
#include<cstdio>
#define N 100010
using namespace std;
int nxt[N<<1],to[N<<1],head[N],w[N<<1],cnt;
void add(int u,int v,int c)
{
    nxt[++cnt]=head[u];
    to[cnt]=v;
    w[cnt]=c;
    head[u]=cnt;
}
int maxn,r,n;
void dfs(int x,int p,int d)
{
    if(d>maxn)  maxn=d,r=x;
    for(int i=head[x];i;i=nxt[i])
    {
        int v=to[i];
        if(to[i]==p)  continue;
        dfs(to[i],x,d+w[i]);
    }
}
int ax,bx;
void get_lin(){maxn=r=0;dfs(1,0,0);ax=r;maxn=r=0;dfs(ax,0,0);bx=r;}
struct For_node{
    #define D 20
    int dep[N],fa[N][D],siz[N],df[N],fi[N],id[N],nid[N],maxn[N],ans[N],cnt;
    int tag[N<<2],vx[N<<2],vy[N<<2];
    void dfs(int u,int p)
    {
        fa[u][0]=p;
        id[u]=++cnt;
        nid[cnt]=u;
        maxn[u]=dep[u];
        siz[u]=1;
        for(int i=1;fa[u][i-1];i++) fa[u][i]=fa[fa[u][i-1]][i-1];
        for(int i=head[u];i;i=nxt[i])
        {
            int v=to[i];
            if(v==p) continue;
            dep[v]=dep[u]+w[i];
            df[v]=w[i];
            dfs(v,u);
            maxn[u]=max(maxn[u],maxn[v]);
            siz[u]+=siz[v];
        }
    }
    void build(int u,int l,int r)
    {
        if(l==r){vx[u]=dep[vy[u]=nid[l]];return;}
        int mid=(l+r)>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        if(vx[u<<1]>vx[u<<1|1]) vx[u]=vx[u<<1],vy[u]=vy[u<<1];
        else vx[u]=vx[u<<1|1],vy[u]=vy[u<<1|1];
    }
    inline void set_tag(int u,int v){tag[u]+=v;vx[u]+=v;}
    void push_down(int u)
    {
        if(!tag[u]) return;
        set_tag(u<<1,tag[u]);set_tag(u<<1|1,tag[u]);
        tag[u]=0;
    }
    void change(int u,int l,int r,int L,int R,int v)
    {
        if(L<=l && r<=R){set_tag(u,v);return;}
        int mid=(l+r)>>1;
        push_down(u);
        if(L<=mid) change(u<<1,l,mid,L,R,v);
        if(R>mid) change(u<<1|1,mid+1,r,L,R,v);
        if(vx[u<<1]>vx[u<<1|1]) vx[u]=vx[u<<1],vy[u]=vy[u<<1];
        else vx[u]=vx[u<<1|1],vy[u]=vy[u<<1|1];
    }
    void init(int x)
    {
        dfs(x,0);
        build(1,1,n);
        for(int i=1;i<=n;i++)
        {
            ans[i]=ans[i-1]+vx[1];
            for(int u=vy[1];u && !fi[u];u=fa[u][0]) change(1,1,n,id[u],id[u]+siz[u]-1,-df[u]),fi[u]=i;
        }
    }
    int k_fa(int x,int y)
    {
        for(int i=D-1;i>=0;i--)
        if(fi[fa[x][i]]>=y) x=fa[x][i];
        return fa[x][0];
    }
    int answer(int x,int y)
    {
        y=min(y,n);
        if(fi[x]<=y) return ans[y];
        int u=k_fa(x,y),v=k_fa(x,y+1);
        return max(maxn[x]-dep[u]+ans[y-1],maxn[x]-maxn[v]+ans[y]);
    }
}t[2];
int main()
{
    int m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    get_lin();
    t[0].init(ax);t[1].init(bx);
    int las=0;
    while(m --> 0)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x=(x+las-1)%n+1,y=(y+las-1)%n+1;
        printf("%d\n",las=max(t[0].answer(x,2*y-1),t[1].answer(x,2*y-1)));
    }
    return 0;
}