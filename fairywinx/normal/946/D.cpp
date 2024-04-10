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

const int N = 505;
int dp[N][N];
int tmp[N][N];
int k1[N][N];
int kol1[N];

signed main() {
	setup();
	
	int n, m, kol;
	cin >> n >> m >> kol;
	vector<string> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];

	for(int i = 0; i < n; ++i) {
		int z = 0;
		for(int k = 0; k < m; ++k) {
			if (a[i][k] == '1') {
				k1[i][z] = k;
				++z;
			}
		}
		kol1[i] = z;
		for(; z < N; ++z) 
			k1[i][z] = 1e9 + i;
	}

	for(int i = 0; i < n; ++i) {
		for(int k = 0; k <= kol; ++k) {
			tmp[i][k] = 1e9;
			for(int l1 = 0; l1 <= k; ++l1) {
				int l2 = k - l1;

				int z1 = k1[i][l1], z2 = k1[i][max(kol1[i] - l2 - 1, (long long) 0)];
				if (kol1[i] - l2 - 1 < 0)
					tmp[i][k] = 0;
				// cout << l1 << ' ' << l2 << ' ' << i << ' ' << z1 << ' ' << z2 << '\n';
				tmp[i][k] = min(tmp[i][k], max((long long) 0, z2 - z1 + 1));

			}
		}
	}

	for(int i = 0; i < N; ++i) 
		dp[0][i] = tmp[0][i];
	for(int i = 1; i < n; ++i) {
		for(int k = 0; k <= kol; ++k) {
			dp[i][k] = 1e9;
			for(int j = 0; j <= k; ++j) {

				dp[i][k] = min(dp[i][k], dp[i - 1][k - j] + tmp[i][j]);

			}
		}
	}
	// for(int i = 0; i <= kol; ++i) 
	// 	cout << tmp[1][kol] << ' ';
	// cout << '\n';
	cout << dp[n - 1][kol];

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}