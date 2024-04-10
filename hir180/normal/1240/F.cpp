#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
 
int n,m,k;
vector<int>edge[105];
vector<P>G;
int cnt[105][1005];
int ans[1005];
int rev[105][105];
void dfs(int u, vector<int> &trail) {
        while (!edge[u].empty()) {
                int v = edge[u].back();
                edge[u].pop_back();
                for (int i = 0; i < edge[v].size(); i ++) {
                        if (edge[v][i] == u) {
                                if(i+1 != edge[v].size()) swap(edge[v][i], edge[v][edge[v].size()-1]);
                                edge[v].pop_back();
                                break;
                        }
                }
                dfs(v, trail);
        }
        trail.push_back(u);
}
void remake(int col1, int col2){
	for(int i=1;i<=n;i++) edge[i].clear();
	rep(i,m){
		if(ans[i] != col1 && ans[i] != col2) continue;
		edge[G[i].fi].pb(G[i].sc);
		edge[G[i].sc].pb(G[i].fi);
	}
	for(int i=1;i<=n;i++){
		if(edge[i].size()%2 == 1){
			{
				edge[0].pb(i);
				edge[i].pb(0);
			}
		}
		else{
			rep(e,2){
				edge[0].pb(i);
				edge[i].pb(0);
			}
		}
	}
	vector<int>vi;
	dfs(0,vi);
	vi.pb(0);
	assert(vi.back() == 0);
	rep(i,n+1) assert(edge[i].empty());
	for(int i=1;i<vi.size();i++){
		swap(col1,col2);
		int id = rev[vi[i-1]][vi[i]];
		if(id == -1) continue;
		cnt[vi[i-1]][ans[id]] --;
		cnt[vi[i]][ans[id]] --;
		ans[id] = col1;
		cnt[vi[i-1]][ans[id]] ++;
		cnt[vi[i]][ans[id]] ++;
	}
	for(int i=1;i<=n;i++){
		assert(abs(cnt[i][col1]-cnt[i][col2]) <= 2);
	}
}
int main(){
	cin >> n >> m >> k;
	rep(i,n) { int a; cin >> a; }
	memset(rev,-1,sizeof(rev));
	rep(i,m) {
		int a,b; cin >> a >> b;
		G.pb(P(a,b));
		rev[a][b] = rev[b][a] = i;
	}
	vector<int>vec; for(int i=1;i<=k;i++) vec.pb(i);
	rep(i,m){
		random_shuffle(vec.begin(),vec.end());
		int a = G[i].fi, b = G[i].sc;
		cnt[a][vec[0]]++;
		cnt[b][vec[0]]++;
		ans[i] = vec[0]; 
	}
	rep(loop,1000000){
		int col1 = -1, col2 = -1;
		for(int i=1;i<=n;i++){
			P mx = P(-INF,-INF);
			P mn = P(INF,INF);
			for(int j=1;j<=k;j++){
				mx = max(mx,P(cnt[i][j],j));
				mn = min(mn,P(cnt[i][j],j));
			}
			if(mx.fi-mn.fi >= 3){
				col1 = mx.sc;
				col2 = mn.sc;
				break;
			}
		}
		if(col1 == -1){
			rep(i,m) cout << ans[i] << endl;
			return 0;
		}
		remake(col1,col2);
	}
}