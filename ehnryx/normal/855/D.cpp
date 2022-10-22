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

const int N = 1e5+1;
vector<int> adj[N];
int p[N], ty[N];

struct SegTree { int n; int *s, *t; // EXAMPLE
  SegTree(int len) { n = 1<<(32-__builtin_clz(len));
    s = new int[2*n]; fill(s, s+2*n, -INF);
    t = new int[2*n]; fill(t, t+2*n, INF);
	}
	void insert(int x, int v) {
		x += n;
		s[x] = t[x] = v;
		for (x/=2; x>0; x/=2) {
			s[x] = max(s[2*x], s[2*x+1]);
			t[x] = min(t[2*x], t[2*x+1]);
		}
	}
	int qmin(int l, int r) {
		int res = INF;
		for (l+=n,r+=n+1; l<r; l/=2,r/=2) {
			if (l&1) res = min(res, t[l++]);
			if (r&1) res = min(res, t[--r]);
		}
		return res;
	}
	int qmax(int l, int r) {
		int res = -INF;
		for (l+=n,r+=n+1; l<r; l/=2,r/=2) {
			if (l&1) res = max(res, s[l++]);
			if (r&1) res = max(res, s[--r]);
		}
		return res;
	}
};

namespace HLD { SegTree* segt[N];
  int d[N], par[N], sub[N], sz[N], root[N], ch[N], pos[N]; int dn, cn;
  int dfs(int u, int p) { d[u] = d[par[u]=p]+1; sub[u] = 1;
    for (int x:adj[u]) if (x!=p) sub[u] += dfs(x,u); return sub[u]; }
  void hld(int u, int p) { if (dn == cn) { root[cn]=u; sz[cn++]=0; }
    pos[u] = sz[ch[u]=dn]++; int b=-1, c=-1;
    for (int x:adj[u]) if (x!=p && sub[x]>b) b=sub[c=x]; if (c!=-1) hld(c,u);
    for (int y:adj[u]) if (y!=p && y!=c) { dn++; hld(y,u); } }
  void build(int r) { d[0] = dn = cn = 0; dfs(r,0); hld(r,0);
    for (int i=0; i<cn; i++) segt[i] = new SegTree(sz[i]); }
  int query_path(int a, int b, int t) {
		if (a==b) return false;
		int u = a, v = b;
		bool ok = true;
		int s = 0;
    while (ch[a] != ch[b]) { if (d[root[ch[a]]] < d[root[ch[b]]]) { swap(a,b); s^=1; }
			if (s) ok &= segt[ch[a]]->qmin(0, pos[a]);
			else ok &= !segt[ch[a]]->qmax(0, pos[a]);
			a = par[root[ch[a]]]; }
    if (pos[a] != pos[b]) { if (d[a] < d[b]) { swap(a,b); s^=1; }
			if (s) ok &= segt[ch[a]]->qmin(pos[b]+1, pos[a]);
			else ok &= !segt[ch[a]]->qmax(pos[b]+1, pos[a]);
		}
		ok &= !!b;
		if (t==1) {
			ok &= (b == v);
		} else {
			ok &= (b != v);
		}
		return ok;
	}
	void insert_node(int a, int v) {
		segt[ch[a]]->insert(pos[a], v);
	}
} // returns lca

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	FOR(i,1,n) {
		cin >> p[i] >> ty[i];
		if (p[i]==-1) p[i]=0;
		adj[p[i]].push_back(i);
	}
	HLD::build(0);

	FOR(i,1,n) {
		HLD::insert_node(i,ty[i]);
	}

	int q;
	cin >> q;
	while (q--) {
		int t, u, v;
		cin >> t >> u >> v;
		if (t==1) {
			cout << (HLD::query_path(v,u,t) ? "YES" : "NO") << nl;
		} else {
			cout << (HLD::query_path(u,v,t) ? "YES" : "NO") << nl;
		}
	}

	return 0;
}