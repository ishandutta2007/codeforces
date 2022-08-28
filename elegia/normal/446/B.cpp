#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 1010, K = 1000010;

int n, m, k, p;
int a[N][N];
ll sum[N];
ll r[K], c[K];

void calc(int n, int dec, ll* arr) {
	priority_queue<ll> q;
	for (int i = 1; i <= n; ++i)
		q.push(sum[i]);
	for (int i = 1; i <= k; ++i) {
		arr[i] = arr[i - 1] + q.top();
		q.push(q.top() - dec);
		q.pop();
	}
}

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d%d%d%d", &n, &m, &k, &p);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; ++i)
		sum[i] = accumulate(a[i] + 1, a[i] + m + 1, 0);
	calc(n, m * p, r);
	for (int j = 1; j <= m; ++j) {
		sum[j] = 0;
		for (int i = 1; i <= n; ++i)
			sum[j] += a[i][j];
	}
	calc(m, n * p, c);
	ll ans = numeric_limits<ll>::min();
	for (int i = 0; i <= k; ++i)
		ans = max(ans, r[i] + c[k - i] - i * (ll)(k - i) * p);
	printf("%lld\n", ans);

#ifdef LBT
	LOG("%dms\n", (clock() - nol_cl) * 1000 / CLOCKS_PER_SEC);
#endif
	return 0;
}