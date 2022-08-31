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

ll solve(ll n, ll m, ll k) {
	if (n < m)
		swap(n, m);
	if ((n ^ k) & 1)
		return k - 2;
	else
		return k;
}

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	int q;
	scanf("%d", &q);
	while (q--) {
		ll n, m, k;
		scanf("%lld%lld%lld", &n, &m, &k);
		if (n < m)
			swap(n, m);
		if (k < n) {
			puts("-1");
			continue;
		}
		if ((n ^ m) & 1) {
			printf("%lld\n", max(solve(n - 1, m, k - 1), solve(n, m - 1, k - 1)));
		} else
			printf("%lld\n", solve(n, m, k));
	}

#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}