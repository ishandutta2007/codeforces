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

	int n, A, R, M;
	cin >> n >> A >> R >> M;
	M = min(M, A + R);

	vector<int> v(n);
	for(int i=0; i<n; i++) {
		cin >> v[i];
	}

	function<ll(int)> calc = [=](int h) {
		ll lo = 0;
		ll hi = 0;
		for(int i=0; i<n; i++) {
			if(v[i] < h) lo += h - v[i];
			if(v[i] > h) hi += v[i] - h;
		}
		ll t = min(lo, hi);
		return t*M + (lo-t)*A + (hi-t)*R;
	};

	int l = 0;
	int r = *max_element(v.begin(), v.end());
	while(r-l > 2) {
		int m = (l+r) / 2;
		ll hi = calc(m+1);
		ll lo = calc(m);
		if(hi < lo) {
			l = m;
		} else {
			r = m+1;
		}
	}
	cout << min(min(calc(l), calc(l+1)), calc(r)) << nl;
	//cerr<<"height: "<<l<<" or "<<r<<nl;

	return 0;
}