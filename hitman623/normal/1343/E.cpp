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
#define hell        1000000000000000007LL
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,a,b,c,p[200005],dis[3][200005];
vi adj[200005];
void dijkstra(int source,int f){
    rep(i,1,n+1) dis[f][i]=-1;
    using T=pair<int,pii>;
    priority_queue<T,vector<T>,greater<T>> pq;
    pq.push({0,{source,source}});
    while(!pq.empty()){
        auto g=pq.top();
        pq.pop();
        if(dis[f][g.y.x]!=-1) continue;
        dis[f][g.y.x]=g.x;
        for(auto i:adj[g.y.x]){
            if(dis[f][i]==-1){
                pq.push({g.x+1,{i,g.y.x}});
            }
        }
    }
}
void solve(){
    cin>>n>>m>>a>>b>>c;
    rep(i,1,n+1) adj[i].clear();
    rep(i,1,m+1) cin>>p[i];
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    sort(p+1,p+m+1);
    rep(i,1,m+1) p[i]+=p[i-1];
    dijkstra(a,0);
    dijkstra(b,1);
    dijkstra(c,2);
    int ans=hell;
    rep(i,1,n+1){
        int w=dis[0][i]+dis[1][i]+dis[2][i];
        if(w<=m) ans=min(ans,p[dis[1][i]]+p[w]);
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}