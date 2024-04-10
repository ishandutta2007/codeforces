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

bool is_pal(const string& s) {
	for (int i = 0; i < (int)s.length() / 2; ++i) {
		if (s[i] != s[(int)s.length() - 1 - i]) {
			return false;
		}
	}
	return true;
}

void solve() {
	int n = nxt();
	vector<string> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		if (is_pal(a[i])) {
			cout << "Yes\n";
			return;
		}
	}
	set<string> inverses;
	set<string> which_2;
	set<string> which_prefix_3;
	for (auto s : a) {
		if (inverses.count(s)) {
			cout << "Yes\n";
			return;
		}
		reverse(all(s));
		inverses.insert(s);
		if ((int)s.length() == 3 && which_2.count(s.substr(0, 2))) {
			cout << "Yes\n";
			return;
		} else if ((int)s.length() == 2 && which_prefix_3.count(s)) {
			cout << "Yes\n";
			return;
		}
		reverse(all(s));
		if ((int)s.length() == 2) {
			which_2.insert(s);
		} else if ((int)s.length() == 3) {
			which_prefix_3.insert(s.substr(0, 2));
		} else {
			assert(false);
		}
	}
	cout << "No\n";
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