#include <cstdio>
#include <iostream>

using namespace std;

typedef long long LL;

int n;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int ans = 1 << n;
		for (int i = 1; i < n / 2; i++)
			ans += 1 << i;
		for (int i = n / 2; i < n; i++) ans -= 1 << i;
		printf("%d\n", ans);
	}
	return 0;
}