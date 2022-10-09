// #define _GLIBCXX_DEBUG
 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
#include <queue>
#include <map>
#include <assert.h>
#include <math.h>
#include <iomanip>
#include <string>
 
// #include <algorithm>
#define int long long
#define SOLVE int t; cin >> t; while(t--) solve();
 
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma optimize("O3");

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

void solve() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << -1 << '\n';
	}
	cout << 5;
	for(int i = 0; i < n - 1; ++i)
		cout << 7;
	cout << '\n';
}

signed main() {
	setup();
	// SOLVE;
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	vector<int> b;
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] - (n - k) > 0) {
			ans += a[i];
			b.push_back(i);
		}
	}
	int ansm = 1;
	for(int i = 0; i < k - 1; ++i) {
		ansm = ansm * (b[i + 1] - b[i]) % 998244353;
	}
	cout << ans << ' ' << ansm << '\n';
	

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}