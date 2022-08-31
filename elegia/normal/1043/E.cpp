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

const int N = 300010;

int n;
int x[N], y[N], rk[N];
ll sx[N], sy[N];
vector<int> hate[N];
pair<int, int> haha[N];

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	int m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &x[i], &y[i]);
	while (m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		hate[u].push_back(v);
		hate[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i)
		hate[i].push_back(i);
	for (int i = 1; i <= n; ++i)
		haha[i] = make_pair(x[i] - y[i], i);
	sort(haha + 1, haha + n + 1);
	for (int i = 1; i <= n; ++i)
		rk[haha[i].second] = i;
	for (int i = 1; i <= n; ++i) {
		sx[i] = sx[i - 1] + x[haha[i].second];
		sy[i] = sy[i - 1] + y[haha[i].second];
	}
	for (int i = 1; i <= n; ++i) {
		ll ans = 0;
		ans += sx[rk[i]] + sy[n] - sy[rk[i]];
		ans += rk[i] * (ll)y[i] + (n - rk[i]) * (ll)x[i];
		for (int u : hate[i])
			ans -= min(x[i] + y[u], x[u] + y[i]);
		printf("%lld ", ans);
	}

#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}