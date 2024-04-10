#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	string s;
	cin >> s;
	string t = "";
	if ((int)s.length() == 7) {
		t = "vampire";
	}
	if ((int)s.length() == 6) {
		t = "slayer";
	}
	if ((int)s.length() == 5) {
		t = "buffy";
	}
	if ((int)s.length() == 3) {
		t = "the";
	}
	if (t == "") {
		cout << "none\n";
		return;
	}
	for (int i = 0; i < (int)s.length(); ++i) {
		int x = (s[i] - 'a') + (t[i] - 'a');
		if (x >= 26) {
			x -= 26;
		}
		s[i] = 'a' + x;
	}
	cout << s << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}