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
	[[maybe_unused]] int n = nxt(), k = nxt();
	string s;
	cin >> s;
	auto t = s;
	reverse(all(t));
	if (s == t || k == 0) {
		cout << "1\n";
	} else {
		cout << "2\n";
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}