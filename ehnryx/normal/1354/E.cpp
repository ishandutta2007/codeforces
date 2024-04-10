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

const int N = 5000 + 1;
vector<int> adj[N];
bool vis[N];
int vals[N][N];
int root[N], cnt[N];
vector<int> nodes[N];
bool ans[N];

pair<int,int> colourable(int s) {
	int yes = 0;
	int no = 0;
	stack<int> dfs;
	dfs.push(s);
	ans[s] = true;
	vis[s] = true;
	while(!dfs.empty()) {
		int u = dfs.top();
		dfs.pop();
		nodes[s].push_back(u);
		yes += ans[u];
		no += !ans[u];
		for(int v : adj[u]) {
			if(vis[v]) {
				if(ans[u] == ans[v]) {
					return make_pair(0, 0);
				}
			} else {
				dfs.push(v);
				vis[v] = true;
				ans[v] = !ans[u];
			}
		}
	}
	cnt[s] = yes;
	assert(yes + no);
	return make_pair(yes, no);
}

void colour(int s, int c) {
	if(c == cnt[s]) return;
	for(int v : nodes[s]) {
		ans[v] = !ans[v];
	}
}

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, m;
	cin >> n >> m;
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;

	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	memset(vals, -1, sizeof vals);
	vals[0][0] = 0;
	int cid = 0;
	for(int i=1; i<=n; i++) {
		if(!vis[i]) {
			auto [a, b] = colourable(i);
			if(a+b) {
				for(int j=0; j<=n; j++) {
					if(j >= a && vals[cid][j-a] != -1) {
						vals[cid+1][j] = j-a;
					}
					if(j >= b && vals[cid][j-b] != -1) {
						vals[cid+1][j] = j-b;
					}
				}
				root[++cid] = i;
			} else {
				cout << "NO" << nl;
				return 0;
			}
		}
	}

	if(vals[cid][n2] == -1) {
		cout << "NO" << nl;
		return 0;
	}

	for(int i=cid, j=n2; i>0; i--) {
		int nj = vals[i][j];
		colour(root[i], j - nj);
		j = nj;
	}

	cout << "YES" << nl;
	for(int i=1; i<=n; i++) {
		if(ans[i]) {
			cout << 2;
		} else if(n1 > 0) {
			cout << 1;
			n1--;
		} else {
			cout << 3;
		}
	}
	cout << nl;

	return 0;
}