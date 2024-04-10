#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
#include <deque>
#include <algorithm>

#define SOLVE int t; cin >> t; while(t--) solve();
#define int long long

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

void ct(pair<int, int> a) {
	cout << a.first << ':' << a.second << ' ';
}

void ct(vector<pair<int, int>> &a) {
	for(auto i: a)
		ct(a);
	cout << '\n';
}

void ct(vector<vector<int>> a) {
	for(auto i: a)
		ct(i);
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(2 * n);
	for(auto &i: a) {
		cin >> i;
	}
	sort(a.begin(), a.end());
	// ct(a);
	int ans = 2e9;
	for(int i = 0; i < 2 * n; ++i) {
		int z = (2 * n - 1) / 2;
		if (i > (2 * n - 1) / 2) {
			ans = min(ans, abs(a[i] - a[z]));
		}
		else {
			ans = min(ans, abs(a[i] - a[z + 1]));
		}
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