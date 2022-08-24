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
	int i = 0;
	int ans = 0;
	while (i < n - 1) {
		if (s[i] == '(' || s[i] == s[i + 1]) {
			ans += 1;
			i += 2;
			continue;
		}
		int j = i + 1;
		while (j < n && s[j] == '(') {
			++j;
		}
		if (j == n) {
			break;
		}
		i = j + 1;
		ans += 1;
	}
	cout << ans << " " << n - i << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}