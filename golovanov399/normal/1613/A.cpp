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
	long long x1 = nxt(), p1 = nxt();
	long long x2 = nxt(), p2 = nxt();
	if (to_string(x1).length() + p1 != to_string(x2).length() + p2) {
		cout << (to_string(x1).length() + p1 < to_string(x2).length() + p2 ? '<' : '>') << "\n";
	} else {
		while (p1 > p2) {
			x1 *= 10;
			--p1;
		}
		while (p2 > p1) {
			x2 *= 10;
			--p2;
		}
		if (x1 == x2) {
			cout << "=\n";
		} else {
			cout << (x1 < x2 ? "<" : ">") << "\n";
		}
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