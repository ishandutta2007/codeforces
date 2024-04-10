#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// DON'T USE THESE MACROS DURING ICPC PRACTICE
#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

ll power(ll n, ll e, ll m) {
	ll r = 1;
	for(;e;e/=2) {
		if(e&1) r = r*n%m;
		n = n*n%m;
	}
	return r;
}

const ll M = 1e9+9;
const ll P = 100;
const ll invP = power(P, M-2, M);
const ll inv10 = power(10, MOD-2, MOD);

struct Edge {
	int i; string s;
};

const int N = 1e5+1;
vector<Edge> adj[N];
map<pll,int> vis;
ll dist[N];

ll add_hash(ll ha, string add) {
	for(char c:add) {
		ha = (ha*P + c) % M;
	}
	return ha;
}

ll rm_hash(ll ha, string rm, int n) {
	for(int i=rm.size()-1;i>=n;i--) {
		ha = (ha-rm[i])*invP % M;
	}
	return (ha+M) % M;
}

ll add_dist(ll d, string add) {
	for(char c:add) {
		d = (d*10 + c-'0') % MOD;
	}
	return d;
}

ll rm_dist(ll d, string rm, int n) {
	for(int i=rm.size()-1;i>=n;i--) {
		d = (d-(rm[i]-'0'))*inv10 % MOD;
	}
	return (d+MOD) % MOD;
}

struct Node {
	int i; ll ha, dist; string suf; bool go;
	bool operator < (const Node& o) const {
		pll a(ha,dist), b(o.ha,o.dist);
		if(a!=b) return vis[a] > vis[b];
		return suf > o.suf; // lex
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		adj[i].clear();
	}

	for(int i=1;i<=m;i++) {
		int a,b;
		cin>>a>>b;
		adj[a].push_back({b,to_string(i)});
		adj[b].push_back({a,to_string(i)});
	}

	int vid = 0;
	ll init_ha = 0;
	for(int i=0;i<=6;i++) {
		vis[pll(init_ha,0)] = vid++;
		init_ha = (init_ha*P + '0') % M;
	}

	memset(dist,-1,sizeof dist);
	priority_queue<Node> dijk;
	dijk.push({1,0,0,"000000",true});
	while(!dijk.empty()) {
		Node cur = dijk.top(); dijk.pop();
		if(dist[cur.i] != -1) continue;
		ll ha = add_hash(cur.ha, cur.suf);
		ll cd = add_dist(cur.dist, cur.suf);
		if(!vis.count(pll(ha,cd))) {
			vis[pll(ha,cd)] = vid++;
		}
		if(!cur.go) continue;
		dist[cur.i] = cd;
		for(const Edge& e : adj[cur.i]) {
			if(dist[e.i]==-1) {
				int add = e.s.size();
				string suf = cur.suf + e.s;
				for(int i=1;i<add;i++) {
					dijk.push({e.i, rm_hash(ha, cur.suf, i), rm_dist(dist[cur.i], cur.suf, i), suf.substr(i,6), false});
				}
				dijk.push({e.i, rm_hash(ha, cur.suf, add), rm_dist(dist[cur.i], cur.suf, add), suf.substr(add), true});
			}
		}
	}

	for(int i=2;i<=n;i++) {
		cout<<dist[i]<<nl;
	}

	return 0;
}