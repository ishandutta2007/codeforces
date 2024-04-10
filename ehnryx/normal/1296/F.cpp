//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

struct SegTree {
	int n; int *st, *answer;
  SegTree(int len) {
		n = (len>1 ? 1<<(32-__builtin_clz(len-1)) : 1);
    st = new int[2*n]; fill(st, st+2*n, 1);
		answer = new int[2*n]; fill(answer, answer+2*n, INF);
	}
  /* implement the rest of the segment tree */

  void update(int l, int r, int v) {
		for(l+=n, r+=n+1; l<r; l/=2, r/=2) {
			if(l&1) {
				st[l] = max(st[l], v);
				l++;
			}
			if(r&1) {
				--r;
				st[r] = max(st[r], v);
			}
		}
	}

	int query(int x) {
		int res = 0;
		for(int i=x+n; i>0; i/=2) {
			res = max(res, st[i]);
		}
		for(int i=x+n; i>0; i/=2) {
			answer[i] = min(answer[i], res);
		}
		return res;
	}

	int query(int l, int r) {
		int res = INF;
		for(l+=n, r+=n+1; l<r; l/=2, r/=2) {
			if(l&1) res = min(res, answer[l++]);
			if(r&1) res = min(res, answer[--r]);
		}
		return res;
	}
};

const int N = 5000 + 1;
vector<int> adj[N];

namespace HLD { SegTree* segt[N];
int d[N], par[N], sub[N], sz[N], root[N], ch[N], pos[N]; int dn, cn;
int dfs(int u, int p) { d[u] = d[par[u]=p]+1; sub[u] = 1;
	for (int x:adj[u]) { if(x!=p) sub[u] += dfs(x,u); } return sub[u]; }
void hld(int u, int p) { if (dn == cn) { root[cn]=u; sz[cn++]=0; }
  pos[u] = sz[ch[u]=dn]++; int b=-1, c=-1;
  for (int x:adj[u]) if (x!=p && sub[x]>b) b=sub[c=x];
  if (c!=-1) hld(c,u);
  for (int y:adj[u]) if (y!=p && y!=c) { dn++; hld(y,u); } }
void build(int r) { d[0] = dn = cn = 0; dfs(r,0); hld(r,0);
  for (int i=0; i<cn; i++) segt[i] = new SegTree(sz[i]); }
// Returns lca of path ab, MODIFY for insert_node,query_path,query_node
int insert_path(int a, int b, int v) {
  while (ch[a] != ch[b]) {
    if (d[root[ch[a]]] < d[root[ch[b]]]) swap(a,b);
    segt[ch[a]]->update(0, pos[a], v); a = par[root[ch[a]]]; }
  if (pos[a] != pos[b]) { if (d[a] < d[b]) swap(a,b);
    segt[ch[a]]->update(pos[b]+1, pos[a], v); } return b; }
int query_node(int a) {
	return segt[ch[a]]->query(pos[a]);
}
int query_path(int a, int b) {
	int res = INF;
  while (ch[a] != ch[b]) {
    if (d[root[ch[a]]] < d[root[ch[b]]]) swap(a,b);
    res = min(res, segt[ch[a]]->query(0, pos[a]));
		a = par[root[ch[a]]]; }
  if (pos[a] != pos[b]) { if (d[a] < d[b]) swap(a,b);
    res = min(res, segt[ch[a]]->query(pos[b]+1, pos[a]));
	}
	return res;
}
}

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	vector<pair<int,int>> edges;
	for(int i=1; i<n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		edges.emplace_back(a, b);
	}
	HLD::build(1);

	int m;
	cin >> m;
	vector<tuple<int,int,int>> queries;
	for(int i=0; i<m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		HLD::insert_path(a, b, c);
		queries.emplace_back(a, b, c);
	}

	vector<int> ans;
	for(auto [a, b] : edges) {
		if(a == HLD::par[b]) swap(a, b);
		ans.push_back(HLD::query_node(a));
	}

	for(auto [a, b, c] : queries) {
		if(HLD::query_path(a, b) != c) {
			cout << -1 << nl;
			return 0;
		}
	}

	for(int it : ans) {
		cout << it << " ";
	}
	cout << nl;

	return 0;
}