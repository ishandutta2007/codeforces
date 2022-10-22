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
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1e6 + 1;
char colour[N], grid[N];
int indeg[N], dist[N];
vector<int> rev[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		int n, m;
		cin >> n >> m;

		function<int(int,int)> get = [=] (int i, int j) {
			return i*m + j;
		};
		function<int(int,int)> nxt = [=] (int u, char d) {
			int i = u/m;
			int j = u%m;
			if(d == 'U') return get(i-1, j);
			if(d == 'D') return get(i+1, j);
			if(d == 'L') return get(i, j-1);
			if(d == 'R') return get(i, j+1);
			assert(false);
		};

		fill(indeg, indeg+n*m, 0);
		fill(dist, dist+n*m, -1);
		fill(rev, rev+n*m, vector<int>());

		for(int u=0; u<n*m; u++) {
			cin >> colour[u];
		}
		for(int u=0; u<n*m; u++) {
			cin >> grid[u];
			int v = nxt(u, grid[u]);
			indeg[v]++;
			rev[v].push_back(u);
		}

		queue<int> rem;
		for(int u=0; u<n*m; u++) {
			if(indeg[u] == 0) {
				rem.push(u);
			}
		}
		while(!rem.empty()) {
			int u = rem.front();
			rem.pop();
			int v = nxt(u, grid[u]);
			assert(indeg[v] > 0);
			if(--indeg[v] == 0) {
				rem.push(v);
			}
		}

		int tot = 0;
		int good = 0;
		for(int u=0; u<n*m; u++) {
			if(indeg[u] == 0 || dist[u] != -1) continue;
			assert(indeg[u] > 0);

			queue<int> bfs;
			bfs.push(u);
			dist[u] = 0;

			int len = 0;
			vector<int> seen;
			while(!bfs.empty()) {
				int v = bfs.front();
				bfs.pop();
				seen.push_back(v);
				for(int w : rev[v]) {
					if(dist[w] == -1) {
						dist[w] = dist[v] + 1;
						bfs.push(w);
					} else {
						len = dist[v] + 1;
					}
				}
			}
			assert(len > 0);

			vector<bool> taken(len);
			int black = 0;
			for(int v : seen) {
				if(taken[dist[v] % len]) continue;
				if(colour[v] == '0') {
					taken[dist[v] % len] = true;
					black++;
				}
			}
			tot += len;
			good += black;
		}

		cout << tot << " " << good << nl;
	}

	return 0;
}