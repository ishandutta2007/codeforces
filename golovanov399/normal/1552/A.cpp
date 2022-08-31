#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	int n = nxt();
	string s;
	cin >> s;
	auto t = s;
	sort(all(t));
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += (s[i] == t[i]);
	}
	cout << n - ans << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}