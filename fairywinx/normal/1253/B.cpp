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

signed main() {
	setup();
	
	int n;
	cin >> n;
	map<int, int> cnt;
	int bal = 0;
	vector<int> ans;
	int l = -1;
	for(int i = 0; i < n; ++i) {
		int c;
		cin >> c;
		if (c > 0) {
			if (!cnt.count(c)) 
				cnt[c] = 1, ++bal;
			else {
				cout << -1;
				return 0;
			}
		}
		else {
			c = -c;
			if (!cnt.count(c) || cnt[c] > 1) {
				cout << -1;
				return 0;
			}
			else {
				cnt[c]++;
				--bal;
				if (bal == 0) {
					ans.push_back(i - l);
					l = i;
					cnt = map<int, int> ();
				}
			}
		}
	}
	if (l != n - 1) {
		cout << -1;
		return 0;
	}
	int sum = 0;
	cout << ans.size() << '\n';
	for(auto i: ans) {
		cout << i << ' ';
	}

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}