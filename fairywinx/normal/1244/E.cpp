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

vector<int> G[N];
vector<int> A[3];
int dp[N][3][3];

signed main() {
	setup();

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) 
		cin >> a[i];
	sort(a.begin(), a.end());
	int l = 0, a1 = a[0];
	int r = n - 1, a2 = a[n - 1];
	int ans = a2 - a1;
	while(k != 0) {
		for(; l < n; ++l) {
			if (a[l] != a1)
				break;
		}
		if (l == n) 
			break;
		for(; r >= 0; --r) {
			if (a[r] != a2)
				break;
		}
		// cout << l << ' ' << a1 << ' ' << a[l] << ' ' << r << ' ' << a2 << ' ' << a[r] << '\n';
		if (l < (n - 1 - r)) {
			if (k < (a[l] - a1) * l) {
				ans -= k / l;
				break;
			}
			else {
				ans -= (a[l] - a1);
				k -= (a[l] - a1) * l;
				a1 = a[l];
			}
		}	
		else {
			if (k < (a2 - a[r]) * (n - 1 - r)) {
				ans -= k / (n - 1 - r);
				break;
			} 
			else {
				k -= (a2 - a[r]) * (n - 1 - r);
				ans -= (a2 - a[r]);
				a2 = a[r];
			}
		}
	}
	cout << max((long long) 0, ans);


	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}