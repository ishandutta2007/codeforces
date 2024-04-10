#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
#include <algorithm>
#include <queue>
#include <iomanip>

using namespace std;

// #define _GLIBCXX_DEBUG
#pragma GCC optimize("Ofast,inline,fast-math,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")

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

const int N = 228;

long long M[N][N];

signed main() {
	setup();
	for(int i = 0; i < N; ++i)
		fill(M[i], M[i] + N, 0);

	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		M[a - 1][b - 1] = c;
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			bool o = false;
			for(int k = 0; k < n; ++k) {
				if (M[i][j] && M[j][k]) {
					int c = min(M[i][j], M[j][k]);
					M[i][j] -= c;
					M[j][k] -= c;
					M[i][k] += c;
					i = max(0, i - 1);
					j = 0;
					k = -1;
				}
			}
		}
	}
	long long ans = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			ans += M[i][j];
		}
	}
	cout << ans;
	
	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}