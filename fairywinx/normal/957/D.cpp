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
#include <bitset>

#include <algorithm>
#define int long long

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

signed main() {
	setup();
	
	int ans = 0;
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) 
		cin >> a[i];
	vector<int> mx(n + 1);
	mx[n] = -5;
	for(int i = n - 1; i >= 0; --i)
		mx[i] = max(mx[i + 1] - 1, a[i]);
	int kol = 1;
	for(int i = 0; i < n; ++i) {
		if (mx[i + 1] > kol && i != 0)
			++kol;
		else if (a[i] == kol)
			++kol;
		ans += kol - a[i] - 1;
		// cout << mx[i + 1] << ' ' << kol << ' ' << ans << '\n';
	}
	cout << ans;

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}