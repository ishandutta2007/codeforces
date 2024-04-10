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



// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> cnt(20);
	for(int i=0; i<n; i++) {
		cin >> a[i];
		for(int j=0; j<20; j++) {
			if(a[i] & 1<<j) {
				cnt[j]++;
			}
		}
	}

	ll ans = 0;
	for(int i=0; i<n; i++) {
		int cur = 0;
		for(int j=0; j<20; j++) {
			if(cnt[j]) {
				cur |= 1<<j;
				cnt[j]--;
			}
		}
		ans += (ll)cur*cur;
	}
	cout << ans << nl;

	return 0;
}