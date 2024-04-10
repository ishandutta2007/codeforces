#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
#include <algorithm>

#define all(x) x.begin(), x.end()
#define int long long
#define pb emplace_back

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
	string s, t;
	cin >> s >> t;
	unordered_map<char, vector<int>> a;
	int ans = -1;
	for(int j = 0; j < s.size(); ++j) {
		char i = s[j];
		if (!a.count(i))
			a[i] = vector<int> ();
		a[i].pb(j);
	}
	int l_ans = 1;
	for(auto i: t) {
		if (!a.count(i)) {
			cout << -1 << '\n';
			return;
		}
		// cout << i << ' ' << ans << ' ';
		// ct(a[i]);
		auto z = upper_bound(a[i].begin(), a[i].end(), ans);
		if (z == a[i].end()) {
			++l_ans;
			ans = a[i][0];
			// cout << "J";
		}
		else {
			// cout << *z << ' ';
			ans = *z;
		}

	}
	cout << l_ans << '\n';
}

signed main() {
	setup();
	int t; cin >> t;
	for(int i = 0; i < t; ++i) solve();

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif	
}