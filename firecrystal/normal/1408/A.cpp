#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;

const int N = 105;

int n, a[N], b[N], c[N];

bool st[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= 100; i++) st[i] = false;
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		for (int i = 1; i <= n; i++) scanf("%d", b + i);
		for (int i = 1; i <= n; i++) scanf("%d", c + i);
		printf("%d ", a[1]);
		int last = a[1];
		for (int i = 2; i < n; i++) {
			last = a[i] == last ? b[i] : a[i];
			printf("%d ", last);
		}
		int r;
		st[last] = st[a[1]] = true;
		if (!st[a[n]]) r = a[n];
		else if (!st[b[n]]) r = b[n];
		else if (!st[c[n]]) r = c[n];
		printf("%d\n", r);
	}	
	return 0;
}