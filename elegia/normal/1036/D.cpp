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

int n, m;
int a[N], b[N];

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i)
		scanf("%d", &b[i]);
	ll sum = 0;
	for (int i = 1; i <= n; ++i)
		sum += a[i];
	for (int i = 1; i <= m; ++i)
		sum -= b[i];
	if (sum != 0) {
		puts("-1");
		return 0;
	}
	int pos = 0;
	int len = 0;
	for (int i = 1; i <= n; ++i) {
		sum += a[i];
		while (sum >= b[pos + 1] && pos <= m)
			sum -= b[++pos];
		if (sum == 0)
			++len;
	}
	printf("%d\n", len);

#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}