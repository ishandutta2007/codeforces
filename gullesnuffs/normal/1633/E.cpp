#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = (a-1); i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

int x;

struct Edge {
	int v, u, w;

	bool operator<(const Edge& other) const {
		return abs(w-x) < abs(other.w-x);
	}
};

vector<Edge> mst(int n, vector<Edge> edges) {
	UF uf(n);
	sort(all(edges));
	vector<Edge> ans;
	for (auto edge : edges) {
		if (uf.sameSet(edge.u, edge.v))
			continue;
		uf.join(edge.u, edge.v);
		ans.push_back(edge);
	}
	return ans;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<Edge> edges;
	rep(i,0,m) {
		Edge e;
		cin >> e.v >> e.u >> e.w;
		--e.v;
		--e.u;
		edges.push_back(e);
	}
	ll p, k, a, b, c;
	cin >> p >> k >> a >> b >> c;
	vector<ll> q(p);
	rep(i,0,p)
		cin >> q[i];
	rep(i,p,k) {
		q.push_back((q[i-1] * a + b)%c);
	}
	set<int> interesting_x;
	rep(i,0,m) {
		interesting_x.insert(edges[i].w);
		rep(j,0,i) {
			interesting_x.insert((edges[i].w+edges[j].w)/2);
			interesting_x.insert((edges[i].w+edges[j].w+1)/2);
		}
	}
	interesting_x.insert(-1);
	interesting_x.insert(200000000);
	map<int, ll> x_map;
	for (int X : interesting_x) {
		x = X;
		auto e = mst(n, edges);
		ll cost = 0;
		for (auto E : e) {
			cost += abs(E.w-x);
		}
		x_map[x] = cost;
	}
	ll ans = 0;
	rep(i,0,k) {
		auto it = x_map.upper_bound(q[i]);
		auto it2 = it;
		it2--;
		ll res = it->second + (q[i]-it->first)*((it2->second-it->second)/(it2->first-it->first));
		ans ^= res;
	}
	cout << ans << endl;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
		solve();
}