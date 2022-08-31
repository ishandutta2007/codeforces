#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

const int K = 5010;
const int P = 1000000007;

int n, k;
int poly[K], tmp[K], frac[K];

int mpow(int x, int k) {
	int ret = 1;
	while (k) {
		if (k & 1)
			ret = ret * (ll)x % P;
		x = x * (ll)x % P;
		k >>= 1;
	}
	return ret;
}

int main() {
	scanf("%d%d", &n, &k);
	if (n <= k) {
		int ans = 0;
		frac[0] = 1;
		for (int i = 1; i <= n; ++i)
			frac[i] = frac[i - 1] * (ll)i % P;
		for (int i = 1; i <= n; ++i)
			ans = (ans + frac[n] * (ll)mpow(frac[i], P - 2) % P * (ll)mpow(frac[n - i], P - 2) % P * mpow(i, k)) % P;
		printf("%d\n", ans);
		return 0;
	}
	poly[0] = 1;
	for (int i = 0; i < k; ++i) {
		memset(tmp, 0, sizeof(tmp));
		for (int j = 0; j <= i; ++j) {
			tmp[j + 1] = (tmp[j + 1] + (ll)poly[j] * (n - j)) % P;
			tmp[j] = (tmp[j] + poly[j] * (ll)j) % P;
		}
		memcpy(poly, tmp, sizeof(poly));
	}
	int ans = 0;
	for (int i = 0; i <= k; ++i)
		ans = (ans + poly[i] * (ll)mpow(2, n - i)) % P;
	printf("%d\n", ans);
	return 0;
}