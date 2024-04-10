#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <set>
#include <ctime>

#define int long long
#define vi vector<int>
#define mp make_pair
#define pb emplace_back
#define SOLVE int t; cin >> t; for(int i = 0; i < t; ++i) solve();

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

void ct(vector<pair<int, int>> &a) {
	for(auto i: a)
		cout << i.first << ':' << i.second << ' ';
	cout << '\n';
}

void solve() {
	int n, s, k;
	cin >> n >> s >> k;
	int ans = 1e18;
	vector<int> a(2228);
	for(int i = 0; i < k; ++i) {
		int c;
		cin >> c;
		if (abs(s - c) > 1000) {
			continue;
		}
		a[s - c + 1010] = 1;
	}
	for(int i = 0; i < 2228; ++i) {
		if (!a[i]) {
			int c = s + 1010 - i;
			if (c <= 0)
				continue;
			if (c > n)
				continue;
			ans = min(ans, abs(i - 1010));
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