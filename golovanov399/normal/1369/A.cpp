#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	puts(nxt() % 4 ? "NO" : "YES");
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}