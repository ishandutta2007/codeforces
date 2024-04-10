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

int f(string s) {
	return s.back() == 'M' ? 0 : (s.back() == 'S' ? -1 : 1) * (int)s.length();
}

void solve() {
	string s, t;
	cin >> s >> t;
	int sign = f(s) - f(t);
	cout << (sign < 0 ? '<' : sign > 0 ? '>' : '=') << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	for (int i = 1; i <= t; ++i) {
		solve();
	}

	return 0;
}