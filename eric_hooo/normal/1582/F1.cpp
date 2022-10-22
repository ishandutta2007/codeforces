#include <bits/stdc++.h>
using namespace std;

bitset <512> T[510];

void modify(int x, bitset <512> v) {
	x++;
	while (x <= 505) T[x] |= v, x += x & -x;
}

bitset <512> query(int x) {
	x++;
	bitset <512> res;
	while (x) res |= T[x], x -= x & -x;
	return res;
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		bitset <512> tmp = query(x - 1); tmp.set(0);
		for (int i = 0; i < 512; i++) {
			if ((i ^ x) > i) {
				int a = tmp[i], b = tmp[i ^ x];
				tmp[i] = b, tmp[i ^ x] = a;
			}
		}
		modify(x, tmp);
	}
	bitset <512> ans = query(500); ans.set(0);
	printf("%d\n", (int)ans.count());
	for (int i = 0; i < 512; i++) {
		if (ans[i]) printf("%d ", i);
	}
	printf("\n");
	return 0;
}