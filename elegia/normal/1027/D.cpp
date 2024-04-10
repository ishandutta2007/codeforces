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

int n;
int c[N], a[N];
int vis[N];

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	int ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &c[i]);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i) {
		if (vis[i])
			continue;
		int x = i;
		while (!vis[x]) {
			vis[x] = i;
			x = a[x];
		}
		if (vis[x] != i)
			continue;
		int y = a[x], cur = c[x];
		while (y != x) {
			cur = min(cur, c[y]);
			y = a[y];
		}
		ans += cur;
	}
	printf("%d\n", ans);

#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}