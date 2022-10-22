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

int count(int n) {
	int m = (n-1)/2;
	return n*m - m*(m+1);
}

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, m;
	cin >> n >> m;

	if(count(n) < m) {
		cout << -1 << nl;
		return 0;
	}

	if(n < 3) {
		assert(m == 0);
		for(int i=1; i<=n; i++) {
			cout << i << " ";
		}
		cout << nl;
		return 0;
	}

	int s = 3;
	while(count(s) < m) {
		s++;
	}
	assert(s <= n);

	vector<int> ans;
	for(int i=1; i<s; i++) {
		ans.push_back(i);
	}
	int want = m - count(s-1);
	int val = s - 2*want + s-1;
	ans.push_back(val);

	for(int i=s+1; i<=n; i++) {
		ans.push_back(1e9 - (n-i)*1e4);
	}

	for(int it : ans) {
		cout << it << " ";
	}
	cout << nl;

	return 0;
}