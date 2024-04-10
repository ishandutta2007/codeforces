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



// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		int n, m, A, B, C;
		cin >> n >> m >> A >> B >> C;

		vector<ll> cost(m);
		for(int i=0; i<m; i++) {
			cin >> cost[i];
		}
		sort(cost.begin(), cost.end());
		vector<ll> sum(m+1);
		partial_sum(cost.begin(), cost.end(), sum.begin() + 1);

		vector<vector<int>> adj(n+1);
		for(int i=0; i<m; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		function<vector<int>(int)> get_dists = [=](int s) {
			vector<int> d(n+1, -1);
			queue<int> bfs;
			d[s] = 0;
			bfs.push(s);
			while(!bfs.empty()) {
				int u = bfs.front();
				bfs.pop();
				for(int v : adj[u]) {
					if(d[v] == -1) {
						d[v] = d[u] + 1;
						bfs.push(v);
					}
				}
			}
			return d;
		};

		vector<int> adist = get_dists(A);
		vector<int> bdist = get_dists(B);
		vector<int> cdist = get_dists(C);
		ll ans = INFLL;
		for(int i=1; i<=n; i++) {
			int total = adist[i] + bdist[i] + cdist[i];
			if(total <= m) {
				ans = min(ans, sum[total] + sum[bdist[i]]);
			}
		}
		cout << ans << nl;
	}

	return 0;
}