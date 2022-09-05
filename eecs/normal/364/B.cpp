#include <bits/stdc++.h>
using namespace std;

int n, d;
bitset<510000> b;

int main() {
	scanf("%d %d", &n, &d);
	b[0] = 1;
	for (int i = 1, c; i <= n; i++) {
		scanf("%d", &c), b = b | (b << c);
	}
	int cur = 0, cnt = 0;
	while (1) {
		int _cur = -1;
		for (int i = cur + d; i > cur; i--) {
			if (b[i]) { _cur = i; break; }
		}
		if (!~_cur) break;
		cur = _cur, cnt++;
	}
	printf("%d %d\n", cur, cnt);
	return 0;
}