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

// void solve() {
// 	//
// }

int main() {
	string s;
	while (getline(cin, s)) {
		if (s == "Is it rated?") {
			cout << "NO\n";
		} else {
			assert(false);
		}
	}
	// int t = nxt();
	// while (t--) {
	// 	solve();
	// }

	return 0;
}