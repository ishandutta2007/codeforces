#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	int x = nxt(), y = nxt();
	x = min(x, y);
	int ans = 1;
	for (int i = 2; i <= x; ++i) {
		ans *= i;
	}
	printf("%d\n", ans);

	return 0;
}