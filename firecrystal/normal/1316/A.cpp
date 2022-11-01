#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1005;
int n, m, a[N];
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		int p = 0;
		for (int i = 1; i <= n; i++) scanf("%d", a + i), p += a[i];
		printf("%d\n", min(m, p));
	}
	return 0;
}