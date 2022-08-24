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
	int x = 0;
	for (int i = 0; i < n; ++i) {
		cout << (x ^ i) << endl;
		if (nxt() == 1) {
			return;
		}
		x ^= (x ^ i);
	}
	assert(false);
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}