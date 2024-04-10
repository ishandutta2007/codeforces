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

vector<int> get_odd(int n, int k) {
	if(n%2 != k%2 || n<k) return {};
	vector<int> out;
	for(int i=1; i<k; i++) {
		out.push_back(1);
	}
	out.push_back(n-k+1);
	return out;
}

vector<int> get_even(int n, int k) {
	if(n%2 != 0 || n<2*k) return {};
	vector<int> out;
	for(int i=1; i<k; i++) {
		out.push_back(2);
	}
	out.push_back(n-2*k+2);
	return out;
}

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		int n, k;
		cin >> n >> k;
		vector<int> ans = get_odd(n, k);
		if(ans.empty()) ans = get_even(n, k);
		if(ans.empty()) {
			cout << "NO" << nl;
		} else {
			cout << "YES" << nl;
			for(int it : ans) {
				cout << it << " ";
			}
			cout << nl;
		}
	}

	return 0;
}