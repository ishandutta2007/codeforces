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

const int N = 5e3 + 228;
const int MOD = 1e9 + 7;
const int INF = 2e9 + 228;

char WHO[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int A[N][N];

signed main() {
	setup();
	
	map<char, int> who;
	for(int i = 0; i < 16; ++i) 
		who[WHO[i]] = i;
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; j += 4) {
			char c;
			cin >> c;
			int mask = who[c];
			// cout << mask << '\n';
			for(int k = 0; k < 4; ++k) {
				if (mask & (1 << k))
					A[i][j + 3 - k] = 1;
				else
					A[i][j + 3 - k] = 0;
			}
		}
	}
	// for(int i = 0; i < n; ++i) {
	// 	for(int j = 0; j < n; ++j)
	// 		cout << A[i][j] << ' ';
	// 	cout << '\n';
	// }

	vector<int> d;
	for(int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			d.push_back(i);
			if (i * i != n) 
				d.push_back(n / i);
		}
	}
	int ans = 1;
	for(auto D: d) {
		bool can = true;
		for(int i = 0; i < n; i += D) {
			for(int j = 0; j < n; j += D) {
				int type = A[i][j];
				for(int k = 0; k < D; ++k) {
					for(int p = 0; p < D; ++p) {
						if (type != A[i + k][j + p])
							can = false;
					}
				}
			}
		}
		if (can) 
			ans = max(ans, D);
	}
	cout << ans;

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}