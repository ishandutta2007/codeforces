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

ll binom[20][20];
ll pw[10];

ll choose(ll n, ll m) {
	if (m < 0)
		return 0;
	if (n < 0 && m == 0)
		return 1;
	return binom[n][m] * pw[m];
}

ll solve(ll x) {
	if (x < 1000)
		return x + 1;
	static int repr[20];
	int n = 0;
	while (x) {
		repr[n++] = x % 10;
		x /= 10;
	}
	int cnt = 0;
	ll ret = 0;
	for (int i = --n; i >= 0; --i) {
		if (repr[i] == 0)
			continue;
		for (int q = 0; q + cnt <= 3; ++q)
			ret += (repr[i] - 1) * choose(i, q - 1) + choose(i, q);
		++cnt;
	}
	if (cnt <= 3)
		++ret;
	return ret;
}

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	for (int i = 0; i < 20; ++i) {
		binom[i][0] = 1;
		for (int j = 1; j <= i; ++j)
			binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
	}
	pw[0] = 1;
	for (int i = 1; i < 5; ++i)
		pw[i] = pw[i - 1] * 9;
	int q;
	scanf("%d", &q);
	while (q--) {
		ll l, r;
		scanf("%lld%lld", &l, &r);
		printf("%lld\n", solve(r) - solve(l - 1));
	}

#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}