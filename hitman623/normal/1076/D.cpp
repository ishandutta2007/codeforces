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
int n,m,k,vis[300005];
vii adj[300005];
vi ans;
mii mp;
void solve(){
    cin>>n>>m>>k;
    rep(i,1,m+1){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
        mp[{u,v}]=i;
        mp[{v,u}]=i;
    }
    using T=pair<int,pii>;
    priority_queue<T,vector<T>,greater<T>> pq;
    pq.push({0,{1,0}});
    while(!pq.empty() and k){
        auto g=pq.top();
        pq.pop();
        if(vis[g.y.x]) continue;
        vis[g.y.x]=1;
        if(g.y.y) k--,ans.pb(mp[{g.y.x,g.y.y}]);
        for(auto i:adj[g.y.x]){
            if(!vis[i.x]){
                pq.push({i.y+g.x,{i.x,g.y.x}});
            }
        }
    }
    cout<<sz(ans)<<endl;
    for(auto i:ans) cout<<i<<" ";
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