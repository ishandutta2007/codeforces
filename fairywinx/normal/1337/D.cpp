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
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
	#endif

	srand(time(0));
}

const int MOD = 1e9 + 7;

int pow(int a, int b) {
	if (b == 0)
		return 1;
	if (b % 2 == 1) 
		return (a * pow(a, b - 1)) % MOD;
	int z = pow(a, b / 2);
	return (z * z) % MOD;
}

const int N = 1e5 + 228;

vector<int> A[3];

signed main() {
	setup();	
	// SOLVE;
	int _;
	cin >> _;
	while(_--) {

		int n[3];
		cin >> n[0] >> n[1] >> n[2];
		A[0] = vector<int> (n[0] + 5, 5e18);
		A[1] = vector<int> (n[1] + 5, 5e18);
		A[2] = vector<int> (n[2] + 5, 5e18);
		for(int i = 0; i < n[0]; ++i)
			cin >> A[0][i];
		for(int i = 0; i < n[1]; ++i) 
			cin >> A[1][i];
		for(int i = 0; i < n[2]; ++i)
			cin >> A[2][i];
		vector<int> z = {0, 1, 2};
		for(int i = 0; i < 3; ++i)
			sort(A[i].begin(), A[i].end());
		int ans = 5e18;
		do {
			// cout << z[0] << ' ' << z[1] << ' ' << z[2] << '\n';
			for(int i = 0; i < n[z[1]]; ++i) {
				int c = A[z[1]][i];
				// cout << c << ' ';
				auto a1 = lower_bound(A[z[2]].begin(), A[z[2]].end(), c) - A[z[2]].begin();
				auto a2 = upper_bound(A[z[0]].begin(), A[z[0]].end(), c) - A[z[0]].begin() - 1;
				if (a2 < 0 || a2 >= n[z[0]])
					continue;
				if (a1 >= n[z[2]])
					continue;
				int b = A[z[2]][a1];
				int p = A[z[0]][a2];
				ans = min(ans, (c - b) * (c - b) + (c - p) * (c - p) + (b - p) * (b - p));
			}
		} while(next_permutation(z.begin(), z.end()));
		cout << ans << '\n';
	}

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}