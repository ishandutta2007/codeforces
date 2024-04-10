#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt(), a = nxt(), b = nxt();
	string s;
	cin >> s;
	int cnt = 1;
	for (int i = 1; i < n; ++i) {
		cnt += s[i] != s[i - 1];
	}
	cout << a * n + max(b * n, b * ((cnt + 2) / 2)) << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}