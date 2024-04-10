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

	int n;
	cin >> n;
	int half = (n+1)/2;
	vector<ll> a(n+1);
	for(int i=1; i<=half; i++) {
		cin >> a[i];
	}
	int x;
	cin >> x;
	for(int i=half+1; i<=n; i++) {
		a[i] = x;
	}

	vector<ll> step(n+1);
	for(int i=1; i<=n; i++) {
		step[i] = x - a[i];
	}
	partial_sum(a.begin(), a.end(), a.begin());
	partial_sum(step.begin(), step.end(), step.begin());
	partial_sum(step.begin(), step.end(), step.begin(), [](ll c, ll v) {
		return min(c, v);
	});

	for(int i=n/2+1; i<=n; i++) {
		if(a[i] + step[n-i] > 0) {
			cout << i << nl;
			return 0;
		}
	}
	cout << -1 << nl;

	return 0;
}