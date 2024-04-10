#include<cstdio>
#include<algorithm>
int n, m;
int a[1001000];
int s[1001000];
int b[1001000];
int c[1001000];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &a[i]);
		s[i + 1] = s[i] + a[i];
	}
	for (int i = 0; i < m; i++) {
		b[i] = s[i] % n;
	}
	std::sort(b, b + m);
	b[m] = n;
	int p = (s[m] + n - 1) / n;
	printf("%d\n", p);
	for (int i = 0; i < m; i++) {
		c[i] = b[i + 1] - b[i];
		printf("%d ", c[i]);
	}
	printf("\n");
	int r = 0;
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < m; j++) {
			if (r == m) {
				printf("1 ");
				continue;
			}
			else {
				printf("%d ", r + 1);
				a[r] -= c[j];
				if (a[r] == 0)r++;
			}
		}
		printf("\n");
	}
	return 0;
}