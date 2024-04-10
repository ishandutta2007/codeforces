//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma")
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
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 5e5 + 1;
ll val[N], sum[N];
int idx[N];
vector<int> adj[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		int n, m;
		cin >> n >> m;
		for(int i=1; i<=n; i++) {
			cin >> val[i];
			adj[i].clear();
			idx[i] = 0;
		}
		for(int i=0; i<m; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			sum[i] = 0;
		}
		sum[m] = 0;

		int nid = 0;
		for(int i=1; i<=n; i++) {
			map<int,int> rmp;
			for(int j : adj[i]) {
				if(!rmp.count(idx[j])) {
					rmp[idx[j]] = ++nid;
				}
				idx[j] = rmp[idx[j]];
			}
		}

		for(int i=1; i<=n; i++) {
			sum[idx[i]] += val[i];
		}
		//ll ans = accumulate(sum+1, sum+nid+1, (ll) 0, [] (ll a, ll b) {
			//return __gcd(a, b);
		//});
		ll ans = 0;
		for(int i=1; i<=nid; i++) {
			ans = __gcd(ans, sum[i]);
		}
		cout << ans << nl;
	}

	return 0;
}