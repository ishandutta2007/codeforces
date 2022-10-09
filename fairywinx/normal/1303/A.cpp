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
	int s = -1, f = -1;
	int kol1 = 0;
	// int n;
	// cin >> n;
	string z;
	cin >> z;
	int n = z.size();
	for(int i = 0; i < n; ++i) {
		char c = z[i];
		if (c == '1') {
			if (s == -1)
				s = i;
			f = i;
			++kol1;
		}
	}
	// cout << f << ' ' << s << ' ' << kol1 << ' ';
	if (f == -1 && s == -1)
		cout << 0 << '\n';
	else
		cout << f - s + 1 - kol1 << '\n';
}

signed main() {
	setup();
	int t; cin >> t; for(int i = 0; i < t; ++i) solve();
	

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}