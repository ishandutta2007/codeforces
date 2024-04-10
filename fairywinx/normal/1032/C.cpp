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

const int N = 1e5 + 228;

int dp[N][5];


signed main() {
	setup();
	for(int i = 0; i < N; ++i) 
		fill(dp[i], dp[i] + 5, -1);
	fill(dp[0], dp[0] + 5, -2);

	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];

	for(int i = 1; i < n; ++i) {
		for(int j = 0; j < 5; ++j) {
			for(int k = 0; k < 5; ++k) {
				if (dp[i - 1][k] == -1)
					continue;
				if (a[i] == a[i - 1] && j != k)
					dp[i][j] = k;
				if (a[i] > a[i - 1] && j > k)
					dp[i][j] = k;
				if (a[i] < a[i - 1] && j < k)
					dp[i][j] = k; 
			}
		}
	}
	int s = -1;
	for(int i = 0; i < 5; ++i) {
		if (dp[n - 1][i] != -1)
			s = i;
	}
	if (s == -1) {
		cout << -1;
		return 0;
	}
	vector<int> ans(n);
	int i = n - 1;
	while(i >= 0) {
		ans[i] = s;
		s = dp[i][s];
		--i;
	} 
	for(auto i: ans)
		cout << i + 1 << ' ';

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}