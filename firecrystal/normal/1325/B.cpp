#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;

int n, a[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		sort(a + 1, a + 1 + n);
		int ans = 0;
		for (int i = 1; i <= n; i++) if (a[i] != a[i - 1]) ans++;
		printf("%d\n", ans);
	}
	return 0;
}