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

int lower(int n) {
	int j = 0;
	int res = 0;
	while(1<<j <= n) {
		n -= 1<<j;
		res += j * (1<<j);
		j++;
	}
	res += j * n;
	return res;
}

int upper(int n) {
	return n * (n-1) / 2;
}

void solve(int n, int d, int s, int p, vector<int>& ans) {
	assert(lower(n) <= d && d <= upper(n));
	if(n == 0) return;
	if(n == 1) {
		ans.push_back(p);
		return;
	}
	d -= n-1;
	n -= 1;
	for(int k=0; k<=n/2; k++) {
		if(d < lower(k)+lower(n-k) || d > upper(k)+upper(n-k)) continue;
		int left = min(upper(k), d-lower(n-k));
		if(p != 0) ans.push_back(p);
		solve(k, left, s+1, s, ans);
		solve(n-k, d-left, s+1+k, s, ans);
		break;
	}
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
		int n, d;
		cin >> n >> d;
		if(lower(n) <= d && d <= upper(n)) {
			vector<int> ans;
			solve(n, d, 1, 0, ans);
			cout << "YES" << nl;
			for(int it : ans) {
				cout << it << " ";
			}
			cout << nl;
		} else {
			cout << "NO" << nl;
		}
	}

	return 0;
}