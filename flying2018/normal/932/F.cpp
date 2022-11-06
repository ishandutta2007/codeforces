#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200010
#define M N*40
#define ll long long
#define inf ((ll)1e16)
using namespace std;
const int mx=100000;
int a[N],b[N],nxt[N<<1],to[N<<1],head[N],cnt;
void add(int u,int v){nxt[++cnt]=head[u];to[cnt]=v;head[u]=cnt;}
struct line{
    ll k,b;//kx+b
    line(ll K=0,ll B=0):k(K),b(B){}
    ll calc(int x){return k*x+b;}
}t[M];
bool cmp(line a,line b,int x){return a.calc(x)>b.calc(x);}
int ls[M],rs[M],tot;
void insert(int &u,line v,int l=-mx,int r=mx)
{
    if(!u){t[u=++tot]=v;return;}
    int mid=(l+r)>>1;
    if(cmp(t[u],v,mid)) swap(t[u],v);
    if(!cmp(t[u],v,l) && !cmp(t[u],v,r)) return;
	if(cmp(t[u],v,l)) insert(ls[u],v,l,mid);
    else insert(rs[u],v,mid+1,r);
}
ll answer(int u,int x,int l=-mx,int r=mx)
{
    if(!u) return inf;
    int mid=(l+r)>>1;
    if(x<=mid) return min(t[u].calc(x),answer(ls[u],x,l,mid));
    else return min(t[u].calc(x),answer(rs[u],x,mid+1,r));
}
int merge(int x,int y,int l=-mx,int r=mx)
{
    if(!x || !y) return x+y;
    int mid=(l+r)>>1;
    ls[x]=merge(ls[x],ls[y],l,mid),rs[x]=merge(rs[x],rs[y],mid+1,r);
    insert(x,t[y],l,r);
    return x;
}
int root[N];ll f[N];
void solve(int u,int p=0)
{
    bool lv=true;
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if(v==p) continue;
        solve(v,u);
        root[u]=merge(root[u],root[v]);
        lv=false;
    }
    f[u]=lv?0:answer(root[u],a[u]);
    insert(root[u],line(b[u],f[u]));
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v),add(v,u);
    }
    solve(1);
    for(int i=1;i<=n;i++) printf("%lld ",f[i]);
    return 0;
}