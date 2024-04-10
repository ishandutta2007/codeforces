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

int check(int n, vector<int> &a, int k, int s) {
	vector<int> c(n);
	int pr = 0;
	for(int i = 0; i < n; ++i) 
		c[i] = (i + 1) * k + a[i];
	sort(c.begin(), c.end());
	for(int i = 0; i < k; ++i) 
		pr += c[i];
	if (pr > s)
		return -1;
	return pr;
}

signed main() {
	setup();
	
	int n, m;
	cin >> n >> m;
	vector<vector<int>> used(n, vector<int> (m + 2));
	for(int i = n - 1; i >= 0; --i) {
		string s;
		cin >> s;
		for(int j = 0; j < m + 2; ++j) {
			if (s[j] == '1')
				used[i][j] = 0;
			else
				used[i][j] = 1;
		}
	}
	vector<pair<int, int>> t(n, make_pair(1e9, -1e9));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m + 2; ++j) {
			if (!used[i][j]) {
				t[i].first = min(t[i].first, j);
				t[i].second = max(t[i].second, j);
			}
		}
	}
	while(n != 0 && t[n - 1].first == 1e9)
		--n;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	int ans = 1e9 + 228;
	for(int mask = 0; mask < (1 << (n - 1)); ++mask) {
		int l = 0, r; 
		int l_ans = 0;
		for(int i = 0; i < n - 1; ++i) {
			if (mask & (1 << i)) 
				r = m + 2;
			else 
				r = 0;
			if ((r == 0 && l == m + 2) || (r == m + 2 && l == 0)) {
				l_ans += m + 2;
				l = r;
				continue;
			}
			if (t[i].first == 1e9) {
				l_ans += 1;
				l = r;
				continue;
			}
			if (l == 0)
				l_ans += t[i].second * 2 + 1;
			else 
				l_ans += (m + 1 - t[i].first) * 2 + 1;
			l = r;
		}
		if (l == 0)
			l_ans += t[n - 1].second;
		else
			l_ans += (m + 1 - t[n - 1].first);
		ans = min(ans, l_ans);
	}
	cout << ans;

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}