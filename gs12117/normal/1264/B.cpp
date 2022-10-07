#include<cstdio>
int flg;
int res[100100];
int main() {
	int n;
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	n = a + b + c + d;
	flg = 1;
	if (b == 0) {
		if (a == 1 && c == 0 && d == 0) {
			res[0] = 0;
		}
		else if (a != 0) {
			flg = 0;
		}
		else if (c > d) {
			if (c - d >= 2) {
				flg = 0;
			}
			else {
				for (int i = 0; i < n; i++) {
					res[i] = 2 + i % 2;
				}
			}
		}
		else {
			if (d - c >= 2) {
				flg = 0;
			}
			else {
				for (int i = 0; i < n; i++) {
					res[i] = 3 - (i % 2);
				}
			}
		}
	}
	else if (c == 0) {
		if (a == 0 && b == 0 && d == 1) {
			res[0] = 3;
		}
		else if (d != 0) {
			flg = 0;
		}
		else if (a > b) {
			if (a - b >= 2) {
				flg = 0;
			}
			else {
				for (int i = 0; i < n; i++) {
					res[i] = i % 2;
				}
			}
		}
		else {
			if (b - a >= 2) {
				flg = 0;
			}
			else {
				for (int i = 0; i < n; i++) {
					res[i] = 1 - (i % 2);
				}
			}
		}
	}
	else {
		if (a + c - b - d >= 2) {
			flg = 0;
		}
		else if (b + d - a - c >= 2) {
			flg = 0;
		}
		else if (a + d - b - c >= 1) {
			flg = 0;
		}
		else if (a + c > b + d) {
			for (int i = 0; i < a * 2; i++) {
				res[i] = i % 2;
			}
			for (int i = a * 2; i < a * 2 + d * 2; i++) {
				res[i] = 2 + i % 2;
			}
			for (int i = a * 2 + d * 2; i < n; i++) {
				res[i] = 2 - i % 2;
			}
		}
		else {
			for (int i = 0; i < d * 2; i++) {
				res[i] = 3 - i % 2;
			}
			for (int i = d * 2; i < a * 2 + d * 2; i++) {
				res[i] = 1 - i % 2;
			}
			for (int i = a * 2 + d * 2; i < n; i++) {
				res[i] = 1 + i % 2;
			}
		}
	}
	if (flg == 0) {
		printf("NO\n");
	}
	else {
		printf("YES\n");
		for (int i = 0; i < n; i++) {
			printf("%d ", res[i]);
		}
	}
	return 0;
}