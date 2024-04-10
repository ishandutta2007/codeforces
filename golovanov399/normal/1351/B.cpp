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

int main() {
	int t = nxt();
	while (t--) {
		int x = nxt(), y = nxt();
		int q = nxt(), w = nxt();
		int s = (x + y + q + w);
		if (s % 3) {
			cout << "No\n";
			continue;
		}
		s /= 3;
		puts((x == s || y == s) && (q == s || w == s) ? "Yes" : "No");
	}

	return 0;
}