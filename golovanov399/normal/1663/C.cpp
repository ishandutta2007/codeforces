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
	int n = nxt();
	int s = 0;
	while (n --> 0) {
		s += nxt();
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