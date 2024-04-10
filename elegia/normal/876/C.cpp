#include <cstdio>

#include <algorithm>

using namespace std;

int n;
int ans[110];

int sum(int x);

int main() {
	int cnt = 0;
	scanf("%d", &n);
	for (int x = max(0, n - 100); x <= n; ++x)
		if (sum(x) + x == n)
			ans[cnt++] = x;
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; ++i)
		printf("%d\n", ans[i]);
	return 0;
}

inline int sum(int x) {
	int ret = 0;
	while (x) {
		ret += x % 10;
		x /= 10;
	}
	return ret;
}