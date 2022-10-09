#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
#include <queue>
#include <iomanip>

using namespace std;

#pragma GCC optimize("Ofast,inline,fast-math,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")

#include <algorithm>
#define int long long
// #define _GLIBCXX_DEBUG
#define SOLVE int t; cin >> t; while(t--) solve();

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

void ct(vector<int> &a) {
	for(auto i: a)
		cout << i << ' ';
	cout << '\n';
}

void ct(pair<int, int> &a) {
	cout << a.first << ':' << a.second << ' ';
}

void ct(vector<pair<int, int>> &a) {
	for(auto i: a)
		ct(i);
}

void solve() {
	int n, x, y;
	cin >> n >> x >> y;
	int c = (x + y);
	if (x + y <= n) {
		cout << 1 << ' ';
		// cout << 5;
	}
	else {
		if (n == 1) {
			// cout << 4;
			cout << 1 << ' ';
		}
		else {
			int k = (x + y - n) + 1;
			// cout << x << ' ' << y << ' ' << n << '\n';
			if (x == n && y == n)
				cout << n << ' ';
			else 
				cout << k << ' ';
		}	
	}
	// int ans = x + y - 1;
	if (x + y >= n + 1) {
		cout << n << '\n';
	}
	else {
		cout << x + y - 1 << '\n';
	}
	// cout << ans << '\n';
}

signed main() {
	setup();
	SOLVE;


	
	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}