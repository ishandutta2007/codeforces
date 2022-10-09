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
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
	#endif

	srand(time(0));
}

const int N = 1e6 + 228;

int dp[N];

signed main() {
	setup();
	
	dp[0] = 0;
	for(int i = 1; i < N; ++i) {
		string s = to_string(i);
		dp[i] = 1e9 + 228;
		for(auto j: s)
			dp[i] = min(dp[i], dp[i - (j - '0')] + 1);
	}
	int n;
	cin >> n;
	cout << dp[n];

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}