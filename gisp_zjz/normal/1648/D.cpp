#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const int maxn=1e6+10;
const ll INF=1e16;
int n,q,s,t;
bool vis[maxn];
ll a[maxn],b[maxn],c[maxn],x[maxn],y[maxn],dis[maxn],ans,hl[maxn],hr[maxn];
vector<pi> G[maxn];
struct edge{
    int x,y;
    ll v;
};
void add_edge(int x,int y,ll v){
    G[x].pb((pi){y,v});
}
void dij(){
    priority_queue<pi,vector<pi>,greater<pi> >Q;
    Q.push((pi){0,s});
    while (!Q.empty()){
        pi tmp=Q.top(); Q.pop();
        int u=tmp.S;
        if (vis[u]) continue;
        vis[u]=1;
        for (auto e:G[u]){
            int v=e.F;
            if (dis[v]==-1||dis[v]>dis[u]+e.S){
                dis[v]=dis[u]+e.S;
                Q.push((pi){dis[v],v});
            }
        }
    }
}
void solve(int l,int r,vector<edge> &E){
    if (l==r) return;
    int mid=(l+r)>>1;
    for (int i=l;i<=r;i++) vis[i]=0,G[i].clear(),dis[i]=-1;
    G[s].clear(); G[t].clear();
    dis[s]=0; dis[t]=-1; vis[s]=vis[t]=0;
    for (int i=l;i<=mid;i++) add_edge(s,i,INF-x[i]);
    for (int i=mid+1;i<=r;i++) add_edge(i,t,INF-y[i]);
    for (int i=l;i<r;i++) add_edge(i+1,i,0);
    for (auto e:E) add_edge(e.x,e.y,e.v);
    dij(); 
    if (dis[t]!=-1) ans=max(ans,INF*2-dis[t]);
    vector<edge> E1,E2; E1.clear(); E2.clear();
    for (auto e:E){
        if (e.x>l&&e.y<mid) E1.pb(e);
        if (e.x>mid+1&&e.y<r) E2.pb(e);
    }
    for (int i=l;i<=mid;i++) hl[i]=hr[i]=INF;
    for (auto e:E){
        int L=e.x,R=e.y;
        if (l>mid) continue; 
        R=min(R,mid);
        if (L==l) hr[R]=min(hr[R],e.v);
        if (R==mid) hl[L]=min(hl[L],e.v);
    }
    for (int i=l+1;i<=mid;i++) if (hr[i]<INF) E1.pb((edge){l,i,hr[i]});
    for (int i=l;i<=mid-1;i++) if (hl[i]<INF) E1.pb((edge){i,mid,hl[i]});

    for (int i=mid+1;i<=r;i++) hl[i]=hr[i]=INF;
    for (auto e:E){
        int L=e.x,R=e.y;
        if (r<mid+1) continue; 
        L=max(L,mid+1);
        if (L==mid+1) hr[R]=min(hr[R],e.v);
        if (R==r) hl[L]=min(hl[L],e.v);
    }
    for (int i=mid+2;i<=r;i++) if (hr[i]<INF) E2.pb((edge){mid+1,i,hr[i]});
    for (int i=mid+1;i<=r-1;i++) if (hl[i]<INF) E2.pb((edge){i,r,hl[i]});

    solve(l,mid,E1);
    solve(mid+1,r,E2);
}
int main(){
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for (int i=1;i<=n;i++) scanf("%lld",&b[i]);
    for (int i=1;i<=n;i++) scanf("%lld",&c[i]);
    for (int i=1;i<=n;i++) a[i]+=a[i-1],b[i]+=b[i-1],c[i]+=c[i-1];
    for (int i=1;i<=n;i++) x[i-1]=a[i]-b[i-1],y[i]=c[n]-c[i-1]+b[i];
    s=n+1; t=n+2; ans=-1e18;
    vector<edge> tmp; tmp.clear();
    while (q--){
        int x,y; ll v;
        scanf("%d%d%lld",&x,&y,&v);
        tmp.pb((edge){x-1,y,v});
    }
    solve(0,n,tmp);
    printf("%lld\n",ans);
    return 0;
}