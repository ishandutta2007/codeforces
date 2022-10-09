#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
// #include <algorithm>
#include <queue>

#define int long long
#define SOLVE int t; cin >> t; while(t--) solve();

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
}

void ct(vector<int> &a) {
	for(auto i: a)
		cout << i << ' ';
}

void ct(pair<int, int> &a) {
	cout << a.first << ':' << a.second << ' ';
}

void ct(vector<pair<int, int>> &a) {
	for(auto i: a)
		ct(i);
}

void ci(vector<int> &a) {
	for(auto &i: a)
		cin >> i;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	ci(a);
	int mn = 2e9;
	int mx = -1;
	for(int i = 0; i < n; ++i) {
		if (a[i] == -1)
			continue;
		if (i != n - 1 && a[i + 1] == -1) {
			mn = min(a[i], mn);
			mx = max(a[i], mx);
		}
		if (i != 0 && a[i - 1] == -1) {
			mn = min(a[i], mn);
			mx = max(a[i], mx);
		}
	}
	if (mx == -1) {
		cout << 0 << ' ' << 0 << '\n';
		return;
	}
	int z = (mn + mx) / 2;
	int ans = 0;
	for(auto &i: a) {
		if (i == -1)
			i = z;
	}
	for(int i = 0; i < n - 1; ++i) {
		ans = max(ans, abs(a[i] - a[i + 1]));
	}
	cout << ans << ' ' << z << '\n';
}

signed main() {
	setup();
	SOLVE;
	

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}