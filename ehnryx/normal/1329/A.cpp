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
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, m;
	cin >> n >> m;
	int ans[m], v[m];
	ll sum = 0;
	for(int i=0; i<m; i++) {
		cin >> v[i];
		sum += v[i];
	}
	if(sum < n) {
		cout << -1 << nl;
		return 0;
	}

	int cur = n;
	for(int i=0; i<m; i++) {
		sum -= v[i];
		ans[i] = min(sum+1, (ll)cur-v[i]+1);
		if(ans[i] <= 0) {
			cout << -1 << nl;
			return 0;
		}
		cur = ans[i]+v[i]-2;
	}

	for(int i=0; i<m; i++) {
		cout << ans[i] << nl;
	}

	return 0;
}