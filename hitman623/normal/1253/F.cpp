#include <bits/stdc++.h>

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,k,q;
vii a[100005];
int dis[100005],par[100005],h[100005];
void dijkstra(){
    memset(dis,-1,sizeof dis);
    using T=pair<int,pii>;
    priority_queue<T,vector<T>,greater<T>> pq;
    rep(i,1,k+1) pq.push({0,{i,i}});
    while(!pq.empty()){
        auto g=pq.top();
        pq.pop();
        if(dis[g.y.x]!=-1) continue;
        dis[g.y.x]=g.x;
        par[g.y.x]=g.y.y;
        for(auto i:a[g.y.x]){
            if(dis[i.x]==-1){
                pq.push({i.y+g.x,{i.x,g.y.y}});
            }
        }
    }
}
int p[100005][20],val[100005][20];
void pre(){
    rep(j,1,20){
        rep(i,1,n+1){
            p[i][j]=p[p[i][j-1]][j-1];
            val[i][j]=max(val[i][j-1],val[p[i][j-1]][j-1]);
        }
    }
}
int get(int u,int v){
    if(h[u]>h[v]) swap(u,v);
    int res=0;
    for(int i=19;i>=0;i--){
        if(h[v]-(1<<i)>=h[u]){
            res=max(res,val[v][i]);
            v=p[v][i];
        }
    }
    if(u==v) return res;
    for(int i=19;i>=0;i--){
        if(p[u][i]!=p[v][i]){
            res=max(res,val[u][i]);
            res=max(res,val[v][i]);
            u=p[u][i];
            v=p[v][i];
        }
    }
    res=max(res,val[u][0]);
    res=max(res,val[v][0]);
    return res;
}
vector<pair<pii,int>> edges;
vector<pair<int,pii>> cand;
vii b[100005];
int find_par(int node){
    if(node==par[node]) return node;
    else return par[node]=find_par(par[node]);
}
void merge(int u,int v){
    u=find_par(u);
    v=find_par(v);
    if(u==v) return;
    par[v]=u;
}
void dfs(int node,int pa){
    p[node][0]=pa;
    h[node]=h[pa]+1;
    for(auto i:b[node]){
        if(i.x!=pa){
            val[i.x][0]=i.y;
            dfs(i.x,node);
        }
    }
}
void solve(){
    cin>>n>>m>>k>>q;
    rep(i,0,m){
        int x,y,w;
        cin>>x>>y>>w;
        a[x].pb({y,w});
        a[y].pb({x,w});
        edges.pb({{x,y},w});
    }
    dijkstra();
    for(auto i:edges){
        if(par[i.x.x]==par[i.x.y]) continue;
        cand.pb({dis[i.x.x]+dis[i.x.y]+i.y,{par[i.x.x],par[i.x.y]}});
    }
    sort(all(cand));
    rep(i,1,k+1) par[i]=i;
    for(auto i:cand){
        if(find_par(i.y.x)==find_par(i.y.y)) continue;
        b[i.y.x].pb({i.y.y,i.x});
        b[i.y.y].pb({i.y.x,i.x});
        merge(i.y.x,i.y.y);
    }
    dfs(1,1);
    pre();
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<get(l,r)<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}