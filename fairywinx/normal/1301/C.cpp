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
	int n, m;
	cin >> n >> m;
	if (m == 1) {
		int ans = n * (n + 1) / 2;
		int u = n - 1;
		ans -= (u / 2) * (u / 2 + 1) / 2;
		ans -= (u - u / 2) * (u - u / 2 + 1) / 2;
		cout << ans << '\n';
		return;
	}
	if (m == 0) {
		cout << 0 << '\n';
		return;
	}
	int ans = n * (n + 1) / 2;
	int k = (n - m) / (m + 1);
	int a = (k + 1) * (m + 1) - n + m;
	int b = (m + 1) - a;
	ans -= a * k * (k + 1) / 2;
	ans -= b * (k + 1) * (k + 2) / 2;
	// cout << a << ' ' << b << ' ' << k << '\n';
	cout << ans << '\n';
}

signed main() {
	setup();
	SOLVE;
	

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}