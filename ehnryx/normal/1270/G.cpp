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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1e6+1;
int out[N], par[N], ans[N];
bool vis[N];

int find(int u) {
	if(vis[u]) {
		int n = 0;
		ans[++n] = u;
		for(int v=par[u]; v!=u; v=par[v]) {
			ans[++n] = v;
		}
		return n;
	}

	par[out[u]] = u;
	vis[u] = true;
	return find(out[u]);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		for(int i=1; i<=n; i++) {
			cin >> out[i];
			out[i] = i - out[i];
		}

		fill(vis, vis+n+1, false);
		int sz = find(1);
		assert(sz > 0);
		cout << sz << nl;
		for(int i=1; i<=sz; i++) {
			cout << ans[i] << " ";
		}
		cout << nl;
	}

	return 0;
}