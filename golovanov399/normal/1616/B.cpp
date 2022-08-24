#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

void solve() {
	int n = nxt();
	string s;
	cin >> s;
	if (n == 1) {
		cout << s << s << "\n";
	} else if (s[0] <= s[1]) {
		cout << s[0] << s[0] << "\n";
	} else {
		int len = 1;
		while (len < n && s[len] <= s[len - 1]) {
			++len;
		}
		s = s.substr(0, len);
		cout << s;
		reverse(all(s));
		cout << s << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}