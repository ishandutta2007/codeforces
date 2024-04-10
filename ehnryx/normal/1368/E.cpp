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

const int N = 2e5 + 1;
vector<int> rev[N];

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		int n, m;
		cin >> n >> m;
		for(int i=1; i<=n; i++) {
			rev[i].clear();
		}

		for(int i=0; i<m; i++) {
			int a, b;
			cin >> a >> b;
			rev[b].push_back(a);
		}

		vector<int> ans;
		vector<int> dist(n+1);
		for(int i=1; i<=n; i++) {
			for(int v : rev[i]) {
				dist[i] = max(dist[i], dist[v] + 1);
			}
			if(dist[i] >= 2) {
				dist[i] = -1;
				ans.push_back(i);
			}
		}

		assert(ans.size() * 7 <= 4*n);
		cout << ans.size() << nl;
		for(int it : ans) {
			cout << it << " ";
		}
		cout << nl;
	}

	return 0;
}