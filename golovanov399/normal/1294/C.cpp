#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	int n = nxt();
	int nn = n;
	vector<pair<int, int>> ps;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			ps.push_back({i, 0});
			while (n % i == 0) {
				ps.back().second += 1;
				n /= i;
			}
		}
	}
	if (n > 1) {
		ps.push_back({n, 1});
	}
	n = nn;
	if ((int)ps.size() >= 3) {
		cout << "YES\n" << ps[0].first << " " << ps[1].first << " " << n / ps[0].first / ps[1].first << "\n";
	} else if ((int)ps.size() == 2 && ps[0].second + ps[1].second >= 4) {
		cout << "YES\n" << ps[0].first << " " << ps[1].first << " " << n / ps[0].first / ps[1].first << "\n";
	} else if ((int)ps.size() == 1 && ps[0].second >= 6) {
		cout << "YES\n" << ps[0].first << " " << ps[0].first * ps[0].first << " " << n / ps[0].first / ps[0].first / ps[0].first << "\n";
	} else {
		cout << "NO\n";
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}