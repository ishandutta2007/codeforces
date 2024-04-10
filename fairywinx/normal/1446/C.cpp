#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
#include <queue>
#include <assert.h>
#include <iomanip>
#include <deque>
#include <map>
#include <random>
#include <cmath>
#include <bitset>
#include <complex>

#include <algorithm>
#define int long long 
#define SOLVE int t; cin >> t; while(t--) solve();
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma optimize("O3")

using namespace std;

void setup() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	#endif
		srand(time(0));
}

int solve(vector<int> &a, int mx = 30) {
	// cout << mx << '\n';
	if (mx == 0)
		return a.size();
	vector<vector<int>> z(mx + 1);
	for (int el : a) {
		for (int i = mx; i >= 0; --i) {
			if (el & (1 << i)) {
				z[i].push_back(el);
				break;
			}
		}
	}
	// for (auto i : z) {
	// 	for (int j : i)
	// 		cout << j  << ' ';
	// 	cout << '\n';
	// }
	// cout << mx << " MEOW\n";
	int ans = 0;
	int cnt = 0;
	int mn = -1;
	for (int i = 0; i <= mx; ++i) {
		if (z[i].size()) {
			mn = i;
			break;
		}
	}
	for (int i = mx; i > 0; --i) {
		if (!z[i].size())
			continue;
		if (i == mn)
			ans = max(ans, solve(z[i], i - 1) + cnt);
		else
			ans = ans = max(ans, solve(z[i], i - 1) + cnt + 1);
		cnt++;
	}
	ans = max(ans, (int) z[0].size() + cnt);
	// cout << "! " << mx << ' ' << ans << '\n';
	return ans;
}

signed main() {
	setup();
	// SOLVE;
	// solve();
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0 ; i < n; ++i) {
		cin >> a[i];
		a[i] = a[i] * 2 + 1;
		// cout << a[i] << ' ';
	}
	cout << n - solve(a) << '\n';
	
	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s  ";
	#endif
}