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

const int N = 1e3 + 228;

int dp[N][9];

signed main() {
	setup();
	
	int n;
	cin >> n;
	for(int i = 1; i < (1 << 3); ++i) 
		dp[0][i] = -1;
	dp[0][0] = 0;
	for(int i = 0; i < n; ++i) {
		int c;
		string s;
		cin >> c >> s;
		int now = 0;
		for(int i = 0; i < 3; ++i) {
			for(int j = 0; j < s.size(); ++j) {
				if (s[j] == 'A' + i) {
					now += (1 << i);
					break;
				}
			}
		}
		// cout << s << ' ' << now << '\n';
		for(int mask = 0; mask < (1 << 3); ++mask)
			dp[i + 1][mask] = dp[i][mask];
		for(int mask = 0; mask < (1 << 3); ++mask) {
			if (dp[i][mask] != -1) {
				if (dp[i + 1][mask | now] != -1)
					dp[i + 1][mask | now] = min(dp[i + 1][mask | now], dp[i][mask] + c);
				else 
					dp[i + 1][mask | now] = dp[i][mask] + c;
			}
		}
	}
	cout << dp[n][7];

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}