#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
// #define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

long double f(long double s, int len) {
	pair<long double, int> opt{1e9, -1};
	// s = (i + 0.5) / len
	return s * len - 0.5;
}

void solve() {
	int n = nxt(), m = nxt();

	long double x = 0, y = 0;
	if (n == 1 && m == 1) {
		cout << "! 0 0" << endl;
		return;
	}
	if (n == 1) {
		cout << "? 3\n";
		cout << "0 0\n0.5 " << m << "\n1 0" << endl;
		long double s;
		cin >> s;
		y = m - 1 - f(s, m);
	} else if (m == 1) {
		cout << "? 3\n";
		cout << "0 0\n" << n << " 0.5\n0 1" << endl;
		long double s;
		cin >> s;
		x = n - 1 - f(s, n);
	} else {
		{
			cout << "? " << 2 + (n + 1) + n << endl;
			cout << "0 -1\n0 0\n";
			for (int i = 0; i < n; ++i) {
				cout << i << ".5 " << m << "\n";
				cout << i + 1 << " 0\n";
			}
			cout << n << " -1" << endl;
			long double s;
			cin >> s;
			y = m - 1 - f(s, m);
		}
		{
			cout << "? " << 2 + (m + 1) + m << endl;
			cout << "-1 0\n0 0\n";
			for (int i = 0; i < m; ++i) {
				cout << n << " " << i << ".5\n";
				cout << "0 " << i + 1 << "\n";
			}
			cout << "-1 " << m << endl;
			long double s;
			cin >> s;
			x = n - 1 - f(s, n);
		}
	}
	cout << setprecision(10) << fixed;
	cout << "! " << x << " " << y << endl;
}

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);

	int t = 1; // nxt();
	for (int i = 1; i <= t; ++i) {
		solve();
	}

	return 0;
}