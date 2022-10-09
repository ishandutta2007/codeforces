// #define GLIBCXX_DEBUG

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
#include <cmath>

#include <algorithm>
#define int long long
#define SOLVE int t; cin >> t; while(t--) solve();

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma optimize("O3");

using namespace std;

void setup() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
	#endif

	srand(time(0));
}

const int N = 2e5 + 228;
const int MOD = 1e9 + 7;

int pow(int a, int b) {
	if (b == 0)
		return 1;
	if (b % 2 == 1)
		return (a * pow(a, b - 1)) % MOD;
	int z = pow(a, b / 2);
	return (z * z) % MOD; 
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) 
		cin >> a[i];

	int mx = -1e15;
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		if (mx > a[i]) {
			int c = mx - a[i];
			for(int j = 0; j < 50; ++j) {
				if (c & (1ll << j)) {
					ans = max(ans, j + 1);
				}
			}
		}

		mx = max(mx, a[i]);
	}
	cout << ans << '\n';

	// if (o) {
	// 	cout << 0 << '\n';
	// 	return;
	// }
	// while(r - l > 1) {
	// 	vector<int> c = a;
	// 	int m = (l + r) / 2;
	// 	c.back() += (1ll << (m)) - 1;
	// 	for(int i = n - 2; i >= 1; --i) {
	// 		int k = 0;
	// 		while(k < m && c[i] + (1ll << k) <= c[i + 1])
	// 			c[i] += (1ll << k), ++k;
	// 	}
	// 	bool res = true;
	// 	for(int i = 0; i < n - 1; ++i) {
	// 		if (c[i] > c[i + 1])
	// 			res = false;
	// 	}
	// 	if (res) {
	// 		// cout << m << '\n';
	// 		// for(auto i: c)
	// 		// 	cout << i << ' ';
	// 		// cout << '\n';
	// 		r = m;
	// 	}
	// 	else
	// 		l = m;
	// }
	// cout << r << '\n';
}

signed main() {
	setup();
	SOLVE;



	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}