#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 105;
int n, a[N], b[N];
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		for (int i = 1; i <= n; i++) scanf("%d", b + i);
		sort(a + 1, a + 1 + n);
		sort(b + 1, b + 1 + n);
		for (int i = 1; i <= n; i++) printf("%d ", a[i]);
		puts("");
		for (int i = 1; i <= n; i++) printf("%d ", b[i]);
		puts("");
	}
}