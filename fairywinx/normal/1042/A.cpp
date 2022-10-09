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
// #include <cmath>
#include <bitset>

#include <algorithm>
#define int long long
#define SOLVE int t; cin >> t; while(t--) solve();

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma optimize("O3")

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

signed main() {
	setup();
	
	int n, m;
	cin >> n >> m;
	pair<int, int> ans = {1e9, -1e9};
	vector<int> a(n);
	for(int i = 0; i < n; ++i) 
		cin >> a[i];
	int mx = 0;
	for(int i = 0; i < n; ++i) 
		mx = max(mx, a[i]);
	int sum = 0;
	for(int i = 0; i < n; ++i)
		sum += a[i];
	for(int i = mx; i < 1e6 + 5; ++i) {
		// cout << sum + m << ' ' << n * i << '\n';
		if ((sum + m) <= n * i) {
			cout << i << ' ';
			break;
		}
	}
	cout << mx + m << '\n';

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}