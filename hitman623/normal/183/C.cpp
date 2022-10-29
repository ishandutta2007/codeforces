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
int n,m,res,last[100005],deg[100005];
mii edges;
vii a[100005];
set<int> vis[200005];
void dfs(int node,int dis){
    if(vis[node].count(dis)) return;
    vis[node].insert(dis);
    if(res and last[node] and abs(dis-last[node])%res==0) return;
    if(last[node]) res=__gcd(res,abs(dis-last[node]));
    last[node]=dis;
    for(auto i:a[node]) dfs(i.x,dis+i.y);
}
void solve(){
    cin>>n>>m;
    rep(i,0,m){
        int u,v;
        cin>>u>>v;
        if(edges.count({u,v})) continue;
        if(u==v){
            cout<<1<<endl;
            return;
        }
        edges[{u,v}]=1;
        a[u].pb({v,1});
        a[v].pb({u,-1});
        deg[v]++;
    }
    rep(i,1,n+1) if(last[i]==0) dfs(i,5e5);
    if(res==0) res=n;
    cout<<res<<endl;
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