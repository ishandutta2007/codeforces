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

signed main() {
	setup();
	// SOLVE;

	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &i: a)
		cin >> i;
	int ans = 0;
	vector<int> res(n);
	for(int i = 0; i < n; ++i) {
		int now = a[i];
		int now_ans = 0;
		vector<int> now_res(n);
		for(int j = i; j >= 0; --j) {
			now_res[j] = min(now, a[j]);
			now = now_res[j];
			now_ans += now_res[j];
		}
		now = a[i];
		for(int j = i + 1; j < n; ++j) {
			now_res[j] = min(now, a[j]);
			now = now_res[j];
			now_ans += now_res[j];
		}
		// ct(now_res);
		if (now_ans > ans) {
			ans = now_ans;
			res = now_res;
		}
	}
	// cout << ans << '\n';
	ct(res);
	
	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}