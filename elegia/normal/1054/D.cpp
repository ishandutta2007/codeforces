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

const int N = 200010; 

int n, k;
int a[N];

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		a[i] ^= a[i - 1];
	}
	ll ans = n * (ll)(n + 1) / 2;
	for (int i = 1; i <= n; ++i) {
		a[i] = min(a[i], (~a[i]) & ((1 << k) - 1));
	}
	sort(a + 1, a + n + 1);
	int cur = 0, cnt = 1;
	for (int i = 1; i <= n; ++i) {
		if (cur != a[i]) {
			int p1 = cnt / 2, p2 = cnt - p1;
			ans -= p1 * (ll)(p1 - 1) / 2 + p2 * (ll)(p2 - 1) / 2;
			
			cur = a[i];
			cnt = 0;
		}
		++cnt;
	}
	int p1 = cnt / 2, p2 = cnt - p1;
	ans -= p1 * (ll)(p1 - 1) / 2 + p2 * (ll)(p2 - 1) / 2;
	printf("%lld\n", ans);

#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}