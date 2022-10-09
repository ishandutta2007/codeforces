#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define all(a) a.begin(), a.end()

using namespace std;

bool solve(int a, int b) {
	if (a == b)
		return true;
	vector<int> c(32);
	int x = 0;
	for (int i = 0; i < 31; ++i) {
		bool a1 = (a & (1 << i));
		bool a2 = b & (1 << i);
		if (a1 == a2) {
			c[i] = x;
		} else if (a1 == 1 && a2 == 0) {
			c[i] = ++x;
		} else {
			c[i] = --x;
			if (x < 0)
				return false;
		}
		// cout << (1 << i) << ' ' << x << '\n';
	}
	for (int i = 30; i >= 0; --i) {
		while (c[i] && a + (1 << i) <= b)
			--c[i], a += (1 << i);
	}
	return (a == b);
}

void solve() {
	int a, b;
	cin >> a >> b;
	if (solve(a, b))
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// solve();
	int t;
	cin >> t;
	while (t--)
		solve();
}