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
// #define int long long

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

const int N = 5e3 + 228;

pair<int, int> who[N];

signed main() {
	setup();
	fill(who, who + N, make_pair(1e9, -1e9));
	
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) 
		cin >> a[i];
	for(int i = 0; i < n; ++i) {
		who[a[i]].first = min(i, who[a[i]].first);
		who[a[i]].second = max(who[a[i]].second, i);
	}
	vector<int> dp(n + 1);
	dp[0] = 0;
	for(int i = 0; i < n; ++i) {
		dp[i + 1] = dp[i];
		pair<int, int> can = {i, i};
		int val = 0;
		vector<int> used(N);
		for(int j = i; j >= 0; --j) {
			can.first = min(can.first, who[a[j]].first);
			can.second = max(can.second, who[a[j]].second);
			if (!used[a[j]]) {
				val ^= a[j];
				used[a[j]] = 1;
			}
			if (can.first >= j && can.second <= i)
				dp[i + 1] = max(dp[i + 1], dp[j] + val);
		}
	}
	// for(auto i: dp)
	// 	cout << i << ' ';
	cout << dp[n];

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}