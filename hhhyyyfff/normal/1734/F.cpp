#include <bits/stdc++.h>

using namespace std;
#define LL long long

int t;
LL n, m, f[60][2][2], ans;

int popcount(LL x) {
	int ret = 0;
	while (x) {
		++ret;
		x -= x & -x;
	}
	return ret;
}

int g(LL x, LL y) {
	return (popcount(x) + popcount(y) - popcount(x + y)) & 1;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%lld%lld", &n, &m);
		memset(f, 0, sizeof(f));
		f[0][0][0] = 1;
		for (int i = 0; i < 59; ++i)
			if (n >> i & 1) {
				f[i + 1][0][0] = f[i][0][0];
				f[i + 1][1][0] = f[i][1][0];
				f[i + 1][0][1] = f[i][1][0] + f[i][1][1] * 2;
				f[i + 1][1][1] = f[i][0][0] + f[i][0][1] * 2;
			} else {
				f[i + 1][0][0] = f[i][0][0] * 2 + f[i][0][1];
				f[i + 1][1][0] = f[i][1][0] * 2 + f[i][1][1];
				f[i + 1][0][1] = f[i][1][1];
				f[i + 1][1][1] = f[i][0][1];
			}
		ans = 0;
		for (int i = 59; i >= 0; --i)
			if (m >> i & 1)
				ans += f[i][g((m >> i) - 1, (n >> i))][0] +
						f[i][g((m >> i), (n >> i))][1];
		if (!(popcount(n) & 1)) ans = m - ans;
		printf("%lld\n", ans);
	}
	return 0;
}