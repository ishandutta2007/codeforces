#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 500010;

int n, k, d;
int a[N], sum[N];
bool f[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d%d%d", &n, &k, &d);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int l = 0;
	f[0] = true;
	sum[0] = 1;
	for (int i = 1; i <= n; ++i) {
		while (a[l + 1] + d < a[i])
			++l;
		if (i - k > l - 1)
			f[i] = sum[i - k] - (l > 0 ? sum[l - 1] : 0);
		sum[i] = sum[i - 1] + f[i];
	}
	puts(f[n] ? "YES" : "NO");

#ifndef ONLINE_JUDGE
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}