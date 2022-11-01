#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 105;

int n, a[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		sort(a + 1, a + 1 + n);
		for (int i = n; i; i--) printf("%d ", a[i]);
		puts("");
	}
	return 0;
}