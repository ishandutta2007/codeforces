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

const int inf = 1e18;
const int N = 3e5 + 228;
const int mod = 1e9 + 7;

int pow(int a, int b) {
	if (b == 0)
		return 1;
	if (b % 2 == 1)
		return (a * pow(a, b - 1)) % mod;
	int z = pow(a, b / 2);
	return (z * z) % mod;
}

void solve() {
	// int n;
	// cin >> n;
	// vector<int> a(n);
	// for(int i = 0; i < n; ++i) 
	// 	cin >> a[i];



	// for(int i = 0; i < n; ++i)
	// 	cout << a[i] << ' ';
	// cout << '\n';

	int n, m;
	cin >> n >> m;
	vector<vector<char>> ans(n, vector<char> (m, 'B'));
	ans[0][0] = 'B';
	for(int i = 1; i < m; ++i)
		ans[0][i] = 'W';
	// for(int i = 1; i < n; ++i)
	// 	ans[i][0] = 'W';
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j)
			cout << ans[i][j];
		cout << '\n';
	}
}

signed main() {
	setup();
	SOLVE;
	


	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}