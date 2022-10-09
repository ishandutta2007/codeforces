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

int gcd(int a, int b) {
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

int fact(int n) {
	int ans = 1;
	for(int i = 1; i <= n; ++i)
		ans *= i;
	return ans;
}

void rek_per(vector<int> &a, vector<int> &b, vector<int> &used, int n, int &ans, int m, int last) {
	if (a.size() == n) {
		int z = 1;
		for(auto i: a)
			z *= i;
		ans += (m - 1) / z;
		return;
	}
	for(int i = last; i < b.size(); ++i) {
		if (!used[i]) {
			a.pb(b[i]);
			used[i] = true;
			rek_per(a, b, used, n, ans, m, i + 1);
			a.pop_back();
			used[i] = false;
		}
	}
}

void solve() {
	int a, m;
	cin >> a >> m;
	if (m == 1) {
		cout << 1 << '\n';
		return;
	}
	int d = gcd(a, m);
	int u = m / d;

	if (u == 1) {
		cout << 1 << '\n';
		return;
	}

	vector<int> b;
	for(int i = 2; i * i <= u; ++i) {
		if (u % i == 0) {
			b.pb(i);
			while(u % i == 0)
				u /= i;
			i = 1;
		}
	}
	if (u != 1)
		b.pb(u);
	// ct(b);
	int ans = 0;
	for(int i = 1; i <= b.size(); ++i) {
		int l_ans = 0;
		vector<int> z;
		vector<int> used(b.size());
		rek_per(z, b, used, i, l_ans, m, 0);
		// cout << i << ' ' << l_ans << '\n';
		if (i % 2 == 1)
			ans += l_ans;
		else 
			ans -= l_ans;
	}
	// cout << m - ans << '\n';
	ans = (m - ans - 1) / d;
	cout << ans << '\n';
}

signed main() {
	setup();
	int t;
	cin >> t;
	while(t--) {
		solve();
	}

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif	
}