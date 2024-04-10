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

ll n, d, k;

ll s0(ll n, ll d, ll k) {
	k -= d;
	if (k < 0)
		return -1;
	ll ret = -1;
	for (ll l = n, r; l <= n * 2 && l <= k; l = r + 1) {
		r = min(n * 2, k / (k / l));
		ll c = k / l;
		ll lb = (n + k + c) / (c + 1), rb = (n * 2 + k - d) / (c + 1);
		if (k - d > 0)
			lb = max(lb, (k - d + c - 1) / c);
		rb = min(rb, r);
		lb = max(lb, l);
		if (rb >= lb)
			ret = rb - n;
	}
	if (k <= d && min(n + k - d, n) >= k)
		ret = max(ret, min(n + k - d, n));
	return ret;
}

ll s1(ll n, ll d, ll k) {
	k -= d - 1;
	if (k < 0)
		return -1;
	ll ret = -1;
	for (ll l = n, r; l <= n * 2 && l <= k; l = r + 1) {
		r = min(n * 2, k / (k / l));
		ll c = k / l;
		ll lb = (n + k + c) / (c + 1), rb = (n * 2 + k - d) / (c + 1);
		if (k - d > 0)
			lb = max(lb, (k - d + c - 1) / c);
		rb = min(rb, min(r, (k - 1) / c));
		lb = max(lb, l);
		if (rb >= lb)
			ret = rb - n;
	}
	if (k <= d && min(n + k - d, n) >= k)
		ret = max(ret, min(n + k - d, n));
	return ret;
}

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	ll l, r;
	scanf("%lld%lld%lld%lld", &n, &l, &r, &k);
	d = r - l + 1;
	if (d <= 0)
		d += n;
	printf("%lld\n", max(s0(n, d, k), s1(n, d, k)));

#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}