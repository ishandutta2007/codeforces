#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#include <iomanip>
#include <string>
#include <ctime>
#include <assert.h>

#include <algorithm>
#define int long long
#define SOLVE int t; cin >> t; while(t--) solve();

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

void solve() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> a(m);
	vector<int> s(n);
	for(int i = 0; i < m; ++i) {
		cin >> a[i].first;
		s[i] = a[i].first;
		a[i].second = i;
	}
	// sort(a.rbegin(), a.rend());
	vector<int> res(m);
	vector<int> last(m);
	last[0] = a[0].first;
	int mx_last = 0;
	for(int i = 1; i < m; ++i) {
		last[i] = a[i].first + i;
		mx_last = max(mx_last, last[i]);
		res[a[i].second] = i;
	}
	for(int i = m - 2; i >= 0; --i) {
		last[i] = max(last[i + 1], last[i]);
		// cout << last[i + 1] << ' ';
	}
	if (mx_last > n) {
		cout << -1 << '\n';
		return;
	}
	int pos = a[0].first, len = a[0].first;
	int sum = 0;
	for(int i = 1; i < m; ++i) {
		last[i] += sum;
		res[a[i].second] = pos - len + 2 + min(len - 1, n - last[i]) - 1; 	
		sum += min(len - 1, n - last[i]);
		last[i] += min(len - 1, n - last[i]);
		pos = res[a[i].second] + a[i].first;
		len = a[i].first;
	}
	// cout << '\n';
	mx_last = 0;
	for(auto i: last)
		mx_last = max(mx_last, i);
	if (mx_last < n) {
		cout << -1;
		return;
	}
	// for(auto i: res) {
	// 	if (i + 1 > n - s[i] + 1) {
	// 		cout << -1;
	// 		return;
	// 	}
	// }
	for(auto i:res) {
		assert(i + 1 <= n - s[i] + 1);
		cout << i + 1 << ' ';
	}
	cout << '\n';
}
signed main() {
	setup();
	// SOLVE;
	solve();



	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}