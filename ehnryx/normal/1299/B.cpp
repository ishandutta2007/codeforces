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

ld cp(const pt& a, const pt& b) {
	return imag(conj(a) * b);
}
ld dp(const pt& a, const pt& b) {
	return real(conj(a) * b);
}

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	vector<pt> p;
	for(int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		p.push_back(pt(x, y));
	}

	bool ok = (n%2 == 0);
	for(int i=0; i<n/2 && ok; i++) {
		int ni = (i+1)%n;
		int j = (i+n/2)%n;
		int nj = (j+1)%n;
		ok &= (abs(abs(p[i]-p[ni]) - abs(p[j]-p[nj])) < EPS);
		ok &= (abs(cp(p[i]-p[ni], p[j]-p[nj])) / abs(p[i]-p[ni]) < EPS);
		ok &= (dp(p[i]-p[ni], p[j]-p[nj]) < 0);
	}

	if(ok) {
		cout << "Yes" << nl;
	} else {
		cout << "No" << nl;
	}

	return 0;
}