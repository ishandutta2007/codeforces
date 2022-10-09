#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
// #include <algorithm>
#include <queue>

#define int long long
#define all(x) x.begin(), x.end()

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
	cout << '\n';
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

void ci(vector<pair<int, int>> &a) {
	for(auto &i: a)
		cin >> i.first >> i.second;
}

void solve() {
	int n, g, b;
	cin >> n >> g >> b;
	if (g >= (n + 1) / 2) {
		cout << n << '\n';
		return;
	}
	if (g >= b) {
		cout << n << '\n';
		return;
	}
	else {
		int z = (n + 1) / 2;
		int need = (z + g - 1) / g;
		int u = (need - 1) * b;
		u = max(u, (n - z));
		cout << u + z << '\n';
	}
}

signed main() {
	setup();
	int t; cin >> t; for(int i = 0; i < t; ++i) solve();
	

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}