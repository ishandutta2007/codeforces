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
int n,m,vis[100005],taken[100005],par[100005],h[100005],r;
vi a[100005],s;
void dfs(int node){
	vis[node]=1;
	h[node]=h[par[node]]+1;
	for(auto i:a[node]){
		if(i==par[node]) continue;
		if(vis[i] and h[node]-h[i]+1>=r){
			int d=h[node]-h[i]+1;
			cout<<2<<endl<<d<<endl;
			rep(_,0,d){
				cout<<node<<" ";
				node=par[node];
			}
			exit(0);
		}
		else if(!vis[i]){
			par[i]=node;
			dfs(i);
		}
	}
	int can=1;
	for(auto i:a[node]) if(taken[i]) can=0;
	if(can){
		taken[node]=1;
		s.pb(node);
	}
}
void solve(){
    cin>>n>>m;
    while(r*r<n) r++;
    rep(i,0,m){
    	int u,v;
    	cin>>u>>v;
    	a[u].pb(v);
    	a[v].pb(u);
    }
    dfs(1);
    cout<<1<<endl;
    s.resize(r);
    for(auto i:s) cout<<i<<" ";
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