#include <cstdio>
#include <algorithm>
#define lson rt<<1
#define rson rt<<1|1

const int N=1e5+5,M=2e5+5,logN=17+1;
int n,m,root,idx,a[N],f[N][logN],dfn[N],seq[N],sz[N],dep[N];
int tot,lnk[N],ter[M],nxt[M];
long long seg[N<<2],tag[N<<2];

void pushup(int rt) {
    seg[rt]=seg[lson]+seg[rson];
}
void build(int rt,int l,int r) {
    if(l==r) {
        seg[rt]=a[seq[l]];
        return;
    }
    int mid=(l+r)>>1;
    build(lson,l,mid);
    build(rson,mid+1,r);
    pushup(rt);
}
void update(int rt,int l,int r,long long k) {
    seg[rt]+=1LL*(r-l+1)*k;
    tag[rt]+=k;
}
void pushdown(int rt,int l,int r) {
    if(!tag[rt]) return;
    int mid=(l+r)>>1;
    update(lson,l,mid,tag[rt]);
    update(rson,mid+1,r,tag[rt]);
    tag[rt]=0;
}
void modify(int x,int y,int rt,int l,int r,int k) {
    if(x<=l&&r<=y) {
        update(rt,l,r,k);
        return;
    }
    pushdown(rt,l,r);
    int mid=(l+r)>>1;
    if(x<=mid) modify(x,y,lson,l,mid,k);
    if(mid<y) modify(x,y,rson,mid+1,r,k);
    pushup(rt);
}
long long query(int x,int y,int rt,int l,int r) {
    if(x<=l&&r<=y) return seg[rt];
    pushdown(rt,l,r);
    int mid=(l+r)>>1;
    long long ret=0;
    if(x<=mid) ret+=query(x,y,lson,l,mid);
    if(mid<y) ret+=query(x,y,rson,mid+1,r);
    return ret;
}
void add(int u,int v) {
    ter[++tot]=v,nxt[tot]=lnk[u],lnk[u]=tot;
}
void dfs(int u,int fa) {
    dep[u]=dep[fa]+1,f[u][0]=fa,dfn[u]=++idx,seq[idx]=u,sz[u]=1;
    for(int i=1;(1<<i)<=dep[u];++i) f[u][i]=f[f[u][i-1]][i-1];
    for(int i=lnk[u];i;i=nxt[i]) {
        int v=ter[i];
        if(v==fa) continue;
        dfs(v,u),sz[u]+=sz[v];
    }
}
int lca(int u,int v) {
    if(dep[u]>dep[v]) u^=v^=u^=v;
    for(int i=17;~i;--i) if(dep[f[v][i]]>=dep[u]) v=f[v][i];
    if(u==v) return u;
    for(int i=17;~i;--i) if(f[u][i]^f[v][i]) u=f[u][i],v=f[v][i];
    return f[u][0];
}
int getlca(int u,int v,int p) {
    int x=lca(u,v),y=lca(u,p),z=lca(v,p);
    if(dep[y]>dep[x]) x=y;
    if(dep[z]>dep[x]) x=z;
    return x;
}
int jump(int u,int d) {
    for(int i=17;~i;--i) if(d&(1<<i)) u=f[u][i];
    return u;
}
void treeModify(int u,int k) {
    int l=dfn[u],r=dfn[u]+sz[u]-1;
    if(u==root) modify(1,n,1,1,n,k);
    else if(dfn[root]<l||dfn[root]>r) modify(l,r,1,1,n,k);
    else {
        int son=jump(root,dep[root]-dep[u]-1);
        modify(1,n,1,1,n,k),modify(dfn[son],dfn[son]+sz[son]-1,1,1,n,-k);
    }
}
long long treeQuery(int u) {
    int l=dfn[u],r=dfn[u]+sz[u]-1;
    if(u==root) return query(1,n,1,1,n);
    else if(dfn[root]<l||dfn[root]>r) return query(l,r,1,1,n);
    else {
        int son=jump(root,dep[root]-dep[u]-1);
        return query(1,n,1,1,n)-query(dfn[son],dfn[son]+sz[son]-1,1,1,n);
    }
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    for(int i=1;i<n;++i) {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v),add(v,u);
    }
    dfs(1,0);
    build(1,1,n);
    root=1;
    while(m--) {
        int opt;
        scanf("%d",&opt);
        if(opt==1) {
            scanf("%d",&root);
        } else if(opt==2) {
            int u,v,x;
            scanf("%d%d%d",&u,&v,&x);
            treeModify(getlca(u,v,root),x);
        } else {
            int x;
            scanf("%d",&x);
            printf("%lld\n",treeQuery(x));
        }
    }
    return 0;
}