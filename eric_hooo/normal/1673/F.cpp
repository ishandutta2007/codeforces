#include <bits/stdc++.h>
using namespace std;

int Flag = 1;

int Trans(int x, int p) {
	if (Flag) {
		while ((x & -x) != x) x -= x & -x;
	}
	int ans = 0;
	for (int i = 0; i < 5; i++) {
		if (x >> i & 1) ans |= 1 << 2 * i + p;
	}
	return ans;
}

int Split(int x, int p) {
	int ans = 0;
	for (int i = 0; i < 5; i++) {
		if (x >> 2 * i + p & 1) ans |= 1 << i;
	}
	return ans;
}

int Work(int x) {
	int ans = 0, cnt = 0;
	for (int i = 4; i >= 0; i--) {
		cnt ^= x >> i & 1, ans |= cnt << i;
	}
	return ans;
}

int Calc(int x) {
	int u = Split(x, 0), v = Split(x, 1);
	return Trans(Work(u), 0) | Trans(Work(v), 1);
}

int main() {
	int n, k; scanf("%d%d", &n, &k);
	int used = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			int val = Trans(j ^ j + 1, 1);
			printf("%d ", val);
			used += val;
		}
		printf("\n");
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n; j++) {
			int val = Trans(i ^ i + 1, 0);
			printf("%d ", val);
			used += val;
		}
		printf("\n");
	}
	Flag = 0;
	// cout << used << endl;
	fflush(stdout);
	int cur = 0;
	while (k--) {
		int x; scanf("%d", &x), cur ^= Calc(x);
		printf("%d %d\n", Split(cur, 0) + 1, Split(cur, 1) + 1);
		fflush(stdout);
	}
	return 0;
}