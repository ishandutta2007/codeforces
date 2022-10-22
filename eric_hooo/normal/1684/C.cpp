#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		goto BEG;
		END:;
		continue;
		BEG:;
		int n, m; scanf("%d%d", &n, &m);
		static int a[200010];
		for (int i = 0; i < n * m; i++) {
			scanf("%d", &a[i]);
		}
		int X = -1, Y = -1;
		for (int i = 0; i < n; i++) {
			static int tmp[200010];
			for (int j = 0; j < m; j++) {
				tmp[j] = a[i * m + j];
			}
			sort(tmp, tmp + m);
			int P = -1, Q = -1, cnt = 0;
			for (int j = 0; j < m; j++) {
				if (tmp[j] != a[i * m + j]) {
					cnt++;
					if (P == -1) P = j;
					else Q = j;
				}
			}
			if (cnt > 2) {
				printf("-1\n");
				goto END;
			}
			if (P == -1) continue;
			X = P, Y = Q;
			break;
		}
		if (X == -1) {
			printf("1 1\n");
			continue;
		}
		for (int i = 0; i < n; i++) {
			static int tmp[200010];
			for (int j = 0; j < m; j++) {
				tmp[j] = a[i * m + j];
			}
			swap(tmp[X], tmp[Y]);
			for (int j = 1; j < m; j++) {
				if (tmp[j - 1] > tmp[j]) {
					printf("-1\n");
					goto END;
				}
			}
		}
		printf("%d %d\n", X + 1, Y + 1);
	}
	return 0;
}