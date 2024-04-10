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

int main() {
	int x1 = nxt(), y1 = nxt();
	int x2 = nxt(), y2 = nxt();

	int ans = 0;
	if (x1 == x2) {
		ans += 2;
	} else {
		ans += abs(x1 - x2) + 1;
	}
	if (y1 == y2) {
		ans += 2;
	} else {
		ans += abs(y1 - y2) + 1;
	}

	printf("%d\n", ans * 2);

	return 0;
}