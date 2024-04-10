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



int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> a(n), b(m);
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	for(int i=0; i<m; i++) {
		cin >> b[i];
	}

	vector<int> pa(n), pb(m);
	function<int(int,int)> block_sum = [] (int c, int v) {
		return (v == 0 ? 0 : c + v);
	};
	partial_sum(a.begin(), a.end(), pa.begin(), block_sum);
	partial_sum(b.begin(), b.end(), pb.begin(), block_sum);

	sort(pa.begin(), pa.end());
	sort(pb.begin(), pb.end());

	ll ans = 0;
	for(int d=1; d*d<=k; d++) {
		if(k%d != 0) continue;
		ll acnt, bcnt;
		acnt = pa.end() - lower_bound(pa.begin(), pa.end(), d);
		bcnt = pb.end() - lower_bound(pb.begin(), pb.end(), k/d);
		ans += acnt * bcnt;
		if(d*d != k) {
			acnt = pa.end() - lower_bound(pa.begin(), pa.end(), k/d);
			bcnt = pb.end() - lower_bound(pb.begin(), pb.end(), d);
			ans += acnt * bcnt;
		}
	}
	cout << ans << nl;

	return 0;
}