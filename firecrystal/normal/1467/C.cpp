#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 3e5 + 5;

LL sum, v = 9e18;

int mn = 2e9, a[3], b[3][N], c[N * 3];

int main() {
	for (int i = 0; i < 3; i++) scanf("%d", a + i);
	for (int i = 0; i < 3; i++) {
		int x; 
		LL k = 0;
		for (int j = 0; j < a[i]; j++) {
			scanf("%d", &x);
			b[i][j] = x;
			sum += x;
			k += x;
		}
		v = min(v, k);
		sort(b[i], b[i] + a[i]);
		c[i] = b[i][0];
	}
	for (int i = 0; i < 3; i++) {
		int x = 0;
		if (i == x) x = 1;
		int y = 3 - i - x;
		if (a[x] == 1) v = min(v, (LL)c[x]);
		if (a[y] == 1) v = min(v, (LL)c[y]);
		v = min(v, (LL)c[x] + c[y]);
	}
	printf("%lld\n", sum - 2 * v);
	return 0;
}