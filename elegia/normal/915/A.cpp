#include <cstdio>

#include <algorithm>

using namespace std;

int main() {
	int n, k, ans = 1 << 20;
	scanf("%d%d", &n, &k);
	while (n--) {
		int a;
		scanf("%d", &a);
		if (k % a == 0)
			ans = min(ans, k / a);
	}
	printf("%d\n", ans);
	return 0;
}