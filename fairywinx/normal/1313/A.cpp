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
// #define int long long
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
	int a, b, c;
	cin >> a >> b >> c;
	int ans = 0;
	vector<int> z = {a, b, c};
	sort(z.rbegin(), z.rend());
	for(int i = 0; i < 3; ++i) {
		if (z[i]) {
			--z[i];
			++ans;
		}
	}
	// ct(z);
	// cout << ans << '\n';
	if (z[0] && z[1]) {
		++ans;
		--z[0], --z[1];
	}
	// ct(z);
	// cout << ans << '\n';
	if (z[0] && z[2]) {
		++ans;
		--z[0], --z[2];
	}
	// ct(z);
// cout << ans << '\n';
	if (z[1] && z[2]) {
		++ans;
		--z[1], --z[2];
	}
	// ct(z);
// cout << ans << '\n';
	if (z[0] && z[1] && z[2]) {
		++ans;
	}
	cout << ans << '\n';
}

signed main() {
	setup();
	SOLVE;

	
	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}