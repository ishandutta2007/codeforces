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

int n, X;
bool f[N], dp[N];
int mu[N];
ll p[N], q[N], r[N];

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d", &n);
	while (n--) {
		int a;
		scanf("%d", &a);
		f[a] = true;
		X = max(a, X);
	}
	mu[1] = 1;
	for (int x = 1; x <= X; ++x)
		for (int y = x + x; y <= X; y += x)
			mu[y] -= mu[x];
	for (int rep = 1; rep <= 7; ++rep) {
		copy(f + 1, f + X + 1, p + 1);
		copy(dp + 1, dp + X + 1, q + 1);
		for (int x = 1; x <= X; ++x)
			for (int y = x + x; y <= X; y += x) {
				p[x] += p[y];
				q[x] += q[y];
			}
		memset(r, 0, sizeof(r));
		for (int x = 1; x <= X; ++x)
			for (int y = 1; y * x <= X; ++y)
				r[x] += mu[y] * p[x * y] * q[x * y];
		for (int x = 1; x <= X; ++x)
			dp[x] = f[x] | dp[x] | r[x];
		if (dp[1]) {
			printf("%d\n", rep);
			return 0;
		}
	}
	puts("-1");

#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}