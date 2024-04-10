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

struct Path {
	int a, b, c;
};

struct Edge {
	int i, c;
};

const int N = 1e3+1;
vector<Edge> adj[N];

int dfs(int u, int p) {
	for (const Edge& e : adj[u]) {
		if (e.i!=p) {
			return dfs(e.i, u);
		}
	}
	return u;
}

pii find_leaves(int u, int v) {
	int cnt = 0;
	vector<int> res;
	for (const Edge& e : adj[u]) {
		if (e.i != v && cnt<2) {
			cnt++;
			res.push_back(dfs(e.i, u));
		}
	}
	return pii(res[0],res[1]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	vector<Path> edges;
	For(i,n-1) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
		edges.push_back({a,b,c});
	}

	FOR(i,1,n) {
		if (adj[i].size() == 2) {
			cout << "NO" << nl;
			return 0;
		}
	}

	cout << "YES" << nl;

	if (n == 2) {
		cout << 1 << nl;
		cout << 1 << " " << 2 << " " << adj[1][0].c << nl;
		return 0;
	}

	vector<Path> ans;
	for (const Path& p : edges) {
		if (adj[p.a].size() == 1) {
			int a, b;
			tie(a,b) = find_leaves(p.b, p.a);
			ans.push_back({p.a,a,p.c/2});
			ans.push_back({p.a,b,p.c/2});
			ans.push_back({a,b,-p.c/2});
		} else if (adj[p.b].size() == 1) {
			int a, b;
			tie(a,b) = find_leaves(p.a, p.b);
			ans.push_back({p.b,a,p.c/2});
			ans.push_back({p.b,b,p.c/2});
			ans.push_back({a,b,-p.c/2});
		} else {
			int a, b, c, d;
			tie(a,b) = find_leaves(p.a, p.b);
			tie(c,d) = find_leaves(p.b, p.a);
			ans.push_back({a,c,p.c/2});
			ans.push_back({b,d,p.c/2});
			ans.push_back({a,b,-p.c/2});
			ans.push_back({c,d,-p.c/2});
		}
	}

	cout << ans.size() << nl;
	for (const Path& p : ans) {
		cout << p.a << " " << p.b << " " << p.c << nl;
	}

	return 0;
}