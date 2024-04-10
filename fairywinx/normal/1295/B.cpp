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
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	int kol1 = 0, kol0 = 0;
	for(int i = 0; i < n; ++i) {
		char c;
		cin >> c;
		if (c == '0'){
			a[i] = 0;
			++kol0;
		}
		else{
			a[i] = 1;
			++kol1;
		}
	}
	if (x < 0) {
		swap(kol0, kol1);
		for(auto &i: a)
			i = 1 - i;
		x = -x;
	}
	vector<int> ans(2 * n + 2);
	int bal = 0;
	//ans[n] = 1;
	for(int i = 0; i < n; ++i) {
		if (a[i] == 0)
			bal += 1;
		else
			--bal;
		// bal -= a[i];
		ans[bal + n]++;
	}
	// ct(ans);
	int z = 0;
	if (kol1 == kol0) {
		if (x + n >= 2 * n + 1 || x + n < 0) {
			cout << 0 << '\n';
			return;
		}
		else if (x == 0) {
			cout << -1 << '\n';
			return;
		}
		else if (ans[x + n] != 0) {
			cout << -1 << '\n';
			return;
		}
		else {
			cout << 0 << '\n';
			return;
		}
	}
	else {
		if (x == 0)
			++z;
		int m = kol0 - kol1;
		if (x > n && m <= 0) {
			cout << 0 << '\n';
			return;
		}
		if (x + n < 0 && m > 0) {
			cout << 0 << '\n';
			return;
		}
		if (x > n) {
			int u = (x - n + m - 1) / m;
			x -= u * m;
		}
		else if (x + n < 0) {
			x = -x;
			m = -m;
			int u = (x - n + m + 1) / m;
			x -= u * m;
			x = -x;
		}
		while(true) {
			// cout << z << ' ' << x << '\n';
			if (x > n || x + n < 0) {
				break;
			}
			z += ans[x + n];
			x = x + kol1 - kol0;
		}
		cout << z << '\n';
	}
}

signed main() {
	setup();
	int t; cin >> t;
	for(int i = 0; i < t; ++i) solve();

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif	
}