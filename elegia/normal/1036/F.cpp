#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <numeric>
#include <limits>
#include <functional>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll INF = 1LL << 62;

int mu[62];
bool vis[62];

ll mpow(ll x, int k) {
	ll ret = 1;
	while (k) {
		if (k & 1) {
			if (ret >= INF / x)
				return INF;
			ret *= x;
		}
		if (k >>= 1) {
			if (x >= INF / x)
				return INF;
			x *= x;
		}
	}
	return ret;
}

ll rt(ll n, int k) {
	ll v = pow(n, 1. / k) - 1;
	if (v < 2)
		v = 2;
	while (mpow(v + 1, k) <= n)
		++v;
	return v;
}

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	fill(mu, mu + 62, 1);
	for (int x = 2; x < 62; ++x) {
		if (vis[x])
			continue;
		for (int y = x; y < 62; y += x) {
			vis[y] = true;
			mu[y] = -mu[y];
			if (y / x % x == 0)
				mu[y] = 0;
		}
	}
	int t;
	scanf("%d", &t);
	while (t--) {
		ll n;
		scanf("%lld", &n);
		ll ans = n - 1;
		for (int k = 2; (1LL << k) <= n; ++k) {
			if (mu[k] == 0)
				continue;
			ll gs = rt(n, k);
			ans += (gs - 1) * mu[k];
		}
		printf("%lld\n", ans);
	}

#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}