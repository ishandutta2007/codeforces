#include <bits/stdc++.h>

#define ll          long long
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
int n,m,k,s[100005];
vii adj[100005];
int dis[100005],par[100005];
void dijkstra(int source){
    memset(dis,-1,sizeof dis);
    using T=pair<int,pii>;
    priority_queue<T,vector<T>,greater<T>> pq;
    pq.push({0,{source,source}});
    while(!pq.empty()){
        auto g=pq.top();
        pq.pop();
        if(dis[g.y.x]!=-1) continue;
        dis[g.y.x]=g.x;
        par[g.y.x]=g.y.y;
        for(auto i:adj[g.y.x]){
            if(dis[i.x]==-1){
                pq.push({max(i.y,g.x),{i.x,g.y.x}});
            }
        }
    }
}
void solve(){
	cin>>n>>m>>k;
	rep(i,1,k+1) cin>>s[i];
	rep(i,0,m){
		int x,y,v;
		cin>>x>>y>>v;
		adj[x].pb({y,v});
		adj[y].pb({x,v});
	}
	dijkstra(s[1]);
	int ans=0;
	rep(i,1,k+1) ans=max(ans,dis[s[i]]);
	rep(i,1,k+1) cout<<ans<<" ";
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