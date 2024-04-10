#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
// #include <algorithm>

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
	int n;
	cin >> n;
	int k2 = 0;
	int k3 = 0;
	if (n % 2 == 1) {
		k3 = 1;
		k2 = n / 2 - 1;
	}
	else 
		k2 = n / 2;
	string ans = "";
	for(int i = 0; i < k3; ++i) 
		ans += '7';
	for(int i = 0; i < k2; ++i)
		ans += '1';
	cout << ans << '\n';
}

signed main() {
	setup();
	int t; cin >> t;
	for(int i = 0; i < t; ++i) solve();

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif	
}