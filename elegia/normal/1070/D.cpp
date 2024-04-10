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


int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	int n, k, r = 0, r2 = 0;
	ll ans = 0;
	scanf("%d%d", &n, &k);
	while (n--) {
		scanf("%d", &r);
		int use = (r + r2) / k;
		ans += use;
		r2 -= use * k;
		if (r2 > 0) {
			ans += (r2 + k - 1) / k;
			r2 -= (r2 + k - 1) / k * k;
		}
		if (r2 < 0) {
			r += r2;
		}
		r2 = max(r, 0);
		r = 0;
	}
	ans += (r + r2 + k - 1) / k;
	printf("%lld\n", ans);

#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}