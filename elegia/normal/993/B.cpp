#include <cstdio>

#include <iostream>

using namespace std;

int n, m;
int a[20][2], b[20][2];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &a[i][0], &a[i][1]);
		if (a[i][0] > a[i][1])
			swap(a[i][0], a[i][1]);
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &b[i][0], &b[i][1]);
		if (b[i][0] > b[i][1])
			swap(b[i][0], b[i][1]);
	}
	int asol = 0, bsol = 0;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int cnt = 0, cans = 0;
		for (int j = 1; j <= m; ++j) {
			if (a[i][0] == b[j][0] && a[i][1] == b[j][1])
				continue;
			if (a[i][0] == b[j][0] || a[i][0] == b[j][1]) {
				if (cnt && a[i][0] != cans) {
					puts("-1");
					return 0;
				}
				cans = a[i][0];
				cnt = 1;
			} else if (a[i][1] == b[j][0] || a[i][1] == b[j][1]) {
				if (cnt && a[i][1] != cans) {
					puts("-1");
					return 0;
				}
				cans = a[i][1];
				cnt = 1;
			}
		}
		if (cnt == 0)
			continue;
		if (ans != cans)
			++asol;
		ans = cans;
		continue;
		puts("-1");
		return 0;
	}
	ans = 0;
	for (int j = 1; j <= m; ++j) {
		int cnt = 0, cans = 0;
		for (int i = 1; i <= n; ++i) {
			if (a[i][0] == b[j][0] && a[i][1] == b[j][1])
				continue;
			if (a[i][0] == b[j][0] || a[i][0] == b[j][1]) {
				if (cnt && a[i][0] != cans) {
					puts("-1");
					return 0;
				}
				cans = a[i][0];
				cnt = 1;
			} else if (a[i][1] == b[j][0] || a[i][1] == b[j][1]) {
				if (cnt && a[i][1] != cans) {
					puts("-1");
					return 0;
				}
				cans = a[i][1];
				cnt = 1;
			}
		}
		if (cnt == 0)
			continue;
		if (ans != cans)
			++bsol;
		ans = cans;
		continue;
		puts("-1");
		return 0;
	}
	if (asol > 1 || bsol > 1) {
		puts("0");
		return 0;
	}
	printf("%d\n", ans);
	return 0;
}