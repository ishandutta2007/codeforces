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
	vector<int> a(n);
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}

	vector<int> pref(n), suff(n);
	pref[0] = (1<<30)-1;
	for(int i=1; i<n; i++) {
		pref[i] = pref[i-1] & ~a[i-1];
	}
	suff[n-1] = (1<<30)-1;
	for(int i=n-2; i>=0; i--) {
		suff[i] = suff[i+1] & ~a[i+1];
	}

	int s = 0;
	for(int i=1; i<n; i++) {
		if((pref[i] & suff[i] & a[i]) > (pref[s] & suff[s] & a[s])) {
			s = i;
		}
	}

	swap(a[s], a[0]);
	for(int i=0; i<n; i++) {
		cout << a[i] << " ";
	}
	cout << nl;

	return 0;
}