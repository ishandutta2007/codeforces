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

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma optimize("O3");

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
signed main() {
	setup();
	
	int n, k;
	cin >> n >> k;
	vector<int> c(k);
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < k; ++i)
		cin >> c[i];
	sort(a.rbegin(), a.rend());

	set<pair<int, int>> q;
	q.emplace(0, 0);
	vector<vector<int>> ans(1);
	for(int i = 0; i < n; ++i) {
		auto z = q.lower_bound(make_pair(c[a[i] - 1], 0));
		if (z == q.begin()) {
			q.emplace(1, ans.size());
			ans.push_back(vector<int> (1, a[i]));
		}
		else {
			auto o = *(--z);
			ans[o.second].push_back(a[i]);
			q.erase(o);
			q.emplace(o.first + 1, o.second);
		}
	}
	cout << ans.size() << '\n';
	for(auto i: ans) {
		cout << i.size() << ' ';
		sort(i.begin(), i.end());
		for(auto j: i)
			cout << j << ' ';
		cout << '\n';
	}
	

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}