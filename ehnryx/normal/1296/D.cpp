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

	int n, a, b, k;
	cin >> n >> a >> b >> k;
	vector<ll> res;
	for(int i=0; i<n; i++) {
		int v;
		cin >> v;
		int lb = (v-1) / (a+b) * (a+b);
		if(lb + a >= v) {
			res.push_back(0);
		} else {
			res.push_back((v - (lb + a) + a-1) / a);
		}
	}
	sort(res.begin(), res.end());
	partial_sum(res.begin(), res.end(), res.begin());
	int ans = upper_bound(res.begin(), res.end(), k) - res.begin();
	cout << ans << nl;

	return 0;
}