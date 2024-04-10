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

const int N = 100010;

int n;
int a[N];
int l[N], r[N];

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	int ans = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i)
		l[i] = 1 + (a[i] > a[i - 1] ? l[i - 1] : 0);
	for (int i = n; i; --i)
		r[i] = 1 + (a[i] < a[i + 1] ? r[i + 1] : 0);
	for (int i = 1; i <= n; ++i) {
		ans = max(ans, l[i] + r[i] - 1);
		ans = max(ans, r[i + 1] + 1);
		ans = max(ans, l[i - 1] + 1);
		if (a[i + 1] - a[i - 1] >= 2)
			ans = max(ans, l[i - 1] + r[i + 1] + 1);
	}
	printf("%d\n", ans);

#ifdef LBT
	LOG("%dms\n", (clock() - nol_cl) * 1000 / CLOCKS_PER_SEC);
#endif
	return 0;
}