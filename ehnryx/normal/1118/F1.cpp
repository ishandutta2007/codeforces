#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

ll inverse(ll n) {
	ll res = 1;
	for (int e = MOD-2; e > 0; e /= 2) {
		if (e&1) res = res*n % MOD;
		n = n*n % MOD;
	}
	return res;
}

struct SegTree {
	int n;
	int *segt, *lazy;
  SegTree(int len) {
		n = 1<<(32-__builtin_clz(len));
    segt = new int[2*n]; fill(segt, segt+2*n, 0);
    lazy = new int[2*n]; fill(lazy, lazy+2*n, 0);
	}
	void update(int l, int r, int v) { update(l,r,v,1,0,n-1); }
	int query(int l, int r) { return query(l,r,1,0,n-1); }

	void push(int i) {
		if (lazy[i]) {
			lazy[2*i] = lazy[2*i+1] = lazy[i];
			segt[2*i] = segt[2*i+1] = lazy[i];
			lazy[i] = 0;
		}
	}

	void pull(int i) {
		segt[i] = segt[2*i] | segt[2*i+1];
	}

	void update(int l, int r, int v, int i, int s, int e) {
		if (r<s || e<l) return;
		if (l<=s && e<=r) {
			lazy[i] = segt[i] = v;
			return;
		}
		push(i);
		int m = (s+e)/2;
		update(l,r,v,2*i,s,m);
		update(l,r,v,2*i+1,m+1,e);
		pull(i);
	}

	int query(int l, int r, int i, int s, int e) {
		if (r<s || e<l) return 0;
		if (l<=s && e<=r) return segt[i];
		push(i);
		int m = (s+e)/2;
		return query(l,r,2*i,s,m) | query(l,r,2*i+1,m+1,e);
	}
};

const int N = 3e5+1;
vector<int> adj[N];

namespace HLD {
  SegTree* segt[N];
  int d[N], par[N], sub[N], sz[N], root[N], ch[N], pos[N]; int dn, cn;
  int dfs(int u, int p) { d[u] = d[par[u]=p]+1; sub[u] = 1;
    for (int x:adj[u]) if (x!=p) sub[u] += dfs(x,u); return sub[u]; }
  void hld(int u, int p) { if (dn == cn) { root[cn]=u; sz[cn++]=0; }
    pos[u] = sz[ch[u]=dn]++; int b=-1, c=-1;
    for (int x:adj[u]) if (x!=p && sub[x]>b) b=sub[c=x]; if (c!=-1) hld(c,u);
    for (int y:adj[u]) if (y!=p && y!=c) { dn++; hld(y,u); } }
  void build(int r) { d[0] = dn = cn = 0; dfs(r,0); hld(r,0);
    for (int i=0; i<cn; i++) segt[i] = new SegTree(sz[i]); }
	int query_node(int a) { return segt[ch[a]]->query(pos[a], pos[a]); }
	void insert_node(int a, int v) { segt[ch[a]]->update(pos[a], pos[a], v); }
  // Returns LCA of path ab, MODIFY for insert_node, query_path, query_node
  void insert_path(int a, int b, int v) { // please expand this when typing
    while (ch[a] != ch[b]) { if (d[root[ch[a]]] < d[root[ch[b]]]) swap(a,b);
      segt[ch[a]]->update(0, pos[a], v); a = par[root[ch[a]]]; }
    if (pos[a] != pos[b]) { if (d[a] < d[b]) swap(a,b);
      segt[ch[a]]->update(pos[b]+1, pos[a], v); }
		insert_node(b, v);
	}
  int query_path(int a, int b) {
		int res = 0;
    while (ch[a] != ch[b]) { if (d[root[ch[a]]] < d[root[ch[b]]]) swap(a,b);
      res |= segt[ch[a]]->query(0, pos[a]); a = par[root[ch[a]]]; }
    if (pos[a] != pos[b]) { if (d[a] < d[b]) swap(a,b);
      res |= segt[ch[a]]->query(pos[b]+1, pos[a]); }
		res |= query_node(b);
		return res;
	}
}

int col[N];
vector<int> nodes[N];

ll dp[N][2]; // node, cut
ll solve(int u, int c, int p) {
	if (dp[u][c] != -1) return dp[u][c];

	ll res = 0;

	if (col[u]) { // at a coloured node, so no choice
		ll cur = 1;
		for (int x : adj[u]) {
			if (x!=p) {
				// no choice, so just force cut
				cur = cur * solve(x,1,u) % MOD;
			}
		}
		res += cur;
	}

	else { // not a coloured node
		ll cur = 1;
		// cut later
		for (int x : adj[u]) {
			if (x!=p) {
				cur = cur * solve(x,1,u) % MOD;
			}
		}
		if (c) { // possibly cut all
			res += cur;
		}
		// cut now
		for (int x : adj[u]) {
			if (x!=p) {
				res += cur * solve(x,0,u) % MOD * inverse(solve(x,1,u)) % MOD;
			}
		}
	}

	return dp[u][c] = res % MOD;
}

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n, k;
	cin >> n; k=2;

	for (int i=1; i<=n; i++) {
		cin >> col[i];
		nodes[col[i]].push_back(i);
	}

	for (int i=1; i<n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	HLD::build(n);

	for (int i=1; i<=k; i++) {
		int base = nodes[i].front();
		for (int j : nodes[i]) {
			if (HLD::query_path(base, j)) {
				cout << 0 << nl;
				return 0;
			}
		}
		for (int j : nodes[i]) {
			HLD::insert_path(base, j, i);
		}
	}
	for (int i=1; i<=n; i++) {
		int colour = HLD::query_node(i);
		if (col[i]) assert(col[i] == colour);
		col[i] = colour;
	}

	memset(dp, -1, sizeof dp);
	cout << (solve(nodes[1][0], 0, 0) + MOD) % MOD << nl;

	return 0;
}