#include <bits/stdc++.h>
using namespace std;

int a[100010];
int b[100010];

bool IN(int x) {
	return x >= -10000 && x <= 10000;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		if (n % 2 == 0) {
			for (int i = 1; i <= n; i += 2) {
				b[i] = a[i + 1], b[i + 1] = -a[i];
			}
		} else {
			for (int i = 4; i <= n; i += 2) {
				b[i] = a[i + 1], b[i + 1] = -a[i];
			}
			int t1 = a[1] < 0, t2 = a[2] < 0, t3 = a[3] < 0; a[1] = abs(a[1]), a[2] = abs(a[2]), a[3] = abs(a[3]);
			if (a[1] == a[2] && a[2] == a[3]) b[1] = 1, b[2] = 1, b[3] = -2;
			else {
				int flag = 0;
				if (a[1] == a[2]) flag = 1, swap(a[2], a[3]);
				assert(a[1] != a[2]);
				if (IN(a[1] + a[2])) b[1] = 1, b[2] = 1;
				else assert(IN(a[1] - a[2])), b[1] = 1, b[2] = -1;
				int sum = a[1] * b[1] + a[2] * b[2];
				b[3] = -sum, b[1] *= a[3], b[2] *= a[3];
				if (flag) swap(a[2], a[3]), swap(b[2], b[3]);
			}
			if (t1) b[1] *= -1;
			if (t2) b[2] *= -1;
			if (t3) b[3] *= -1;
		}
		for (int i = 1; i <= n; i++) {
			printf("%d ", b[i]);
		}
		printf("\n");
	}
	return 0;
}