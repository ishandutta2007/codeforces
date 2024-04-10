#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;

const int N = 3e5 + 5;

int n, a[N], sum, c[N], ans;

int res = 0;

bool inline check(int i) {
	if (i == 1 || i == n) return false;
	return ((a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1]));
}

void inline work(int i) {
	res = sum - c[i] - c[i - 1] - c[i + 1];
	if (check(i)) res++;
	if (check(i + 1)) res++;
	if (check(i - 1)) res++;
	ans = min(ans, res);
}


int main() {
	int T; scanf("%d", &T);
	while (T--) {
		sum = 0; ans = 2e9;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		for (int i = 2; i < n; i++) {
			if ((a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1])) {
				c[i] = 1;
				sum++;
			} else c[i] = 0;
		}
		ans = sum;
		c[n] = c[n + 1] = 0;
		for (int i = 2; i < n; i++) {
			int t = a[i];
			a[i] = a[i - 1];
			work(i);
			a[i] = a[i + 1];
			work(i);
			a[i] = t;
		}
		printf("%d\n", ans);
	}
	return 0;
}