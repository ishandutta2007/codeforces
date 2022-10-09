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

#define int long long

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

void solve() {
	int n;
	cin >> n;
	unordered_map<int, int> cnt;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if (!cnt.count(a))
			cnt[a] = 0;
		cnt[a]++;
	}
	for(auto i: cnt) {
		if (i.second >= 4) {
			for(int j = 0; j < 4; ++j) 
				cout << i.first << ' ';
			cout << '\n';
			return;
		}
	}
	vector<int> cur;
	for(auto i: cnt) {
		if (i.second > 1) 
			cur.push_back(i.first);
	}
	sort(cur.begin(), cur.end());
	// for(auto i: cur)
	// 	cout << i << ' ';
	// cout << '\n';
	int mx1 = cur[0], mx2 = cur[1];
	for(int i = 1; i < cur.size() - 1; ++i) {
		if ((mx1 * mx1 + mx2 * mx2) * cur[i] * cur[i + 1] >= (cur[i] * cur[i] + cur[i + 1] * cur[i + 1]) * mx1 * mx2)
			mx1 = cur[i], mx2 = cur[i + 1];
	}
	cout << mx1 << ' ' << mx1 << ' ' << mx2 << ' ' << mx2 << '\n';
}


signed main() {
	setup();

	int t;
	cin >> t;
	while(t--)
		solve();
	
	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}