// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// https://github.com/kth-competitive-programming/kactl/blob/main/content/graph/Dinic.h
struct Dinic {
	#define vi vector<int>
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, sz(adj[b]), c, c});
		adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		rep(L,0,31) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vi(sz(q));
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

int n,m;
int arr[1005];

vector<int> big,small;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m;
	rep(x,0,n) cin>>arr[x];
	
	rep(x,0,n) if (arr[x]>=(m+1)/2){
		cout<<"-1"<<endl;
		return 0;
	}
	
	rep(x,0,n){
		if (arr[x]*3>m) big.pub(arr[x]);
		else small.pub(arr[x]);
	}
	
	// for (auto it:big) cout<<it<<" "; cout<<endl;
	// for (auto it:small) cout<<it<<" "; cout<<endl;
	
	int s=sz(big)+sz(small),t=s+1;
	
	Dinic g=Dinic(s+2);
	rep(x,0,sz(big)) g.addEdge(s,x,1);
	rep(x,0,sz(small)) g.addEdge(x+sz(big),t,1);
	
	rep(x,0,sz(big)) rep(y,0,sz(small)) if (big[x]%small[y]==0 && big[x]*2+small[y]<=m){
		g.addEdge(x,y+sz(big),1);
	}
	
	if (g.calc(s,t)==sz(big)){
		vector<ii> ans;
		
		set<int> used;
		rep(x,0,sz(big)) for (auto it:g.adj[x]) if (it.flow()==1){
			int temp=it.to-sz(big);
			//cout<<x<<" "<<temp<<endl;
			ans.pub({big[x]*2+small[temp],big[x]+small[temp]});
			used.insert(temp);
		}
		rep(x,0,sz(small)) if (!used.count(x)) ans.pub({3*small[x],2*small[x]});
		
		cout<<sz(ans)<<endl;
		for (auto [a,b]:ans) cout<<a<<" "<<b<<endl;
	}
	else{
		cout<<"-1"<<endl;
	}
}