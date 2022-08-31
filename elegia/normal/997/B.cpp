#include <cstdio>
#include <cstring>

#include <algorithm>
#include <functional>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

int n;

int ans[15], a[14 * 50 + 1], tmp[14 * 50 + 1];

int main() {
	scanf("%d", &n);
	a[0] = 1;
	for (int i = 1; i <= 14; ++i) {
		memset(tmp, 0, sizeof(tmp));
		for (int x = 0; x <= i * 50; ++x) {
			if (x >= 1)
				tmp[x] |= a[x - 1];
			if (x >= 5)
				tmp[x] |= a[x - 5];
			if (x >= 10)
				tmp[x] |= a[x - 10];
			if (x >= 50)
				tmp[x] |= a[x - 50];
		}
		memcpy(a, tmp, sizeof(a));
		ans[i] = count(a + 1, a + i * 50 + 1, 1);
	}
	if (n <= 14)
		printf("%d\n", ans[n]);
	else
		printf("%lld\n", ans[14] + (n - 14) * 49LL);
	return 0;
}