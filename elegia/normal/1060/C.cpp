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

const int N = 2010;

int n, m;
int va[N], vb[N];
int a[N], b[N];

int main() {
	int x;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		a[i] += a[i - 1];
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &b[i]);
		b[i] += b[i - 1];
	}
	scanf("%d", &x);
	fill(va, va + n + 1, numeric_limits<int>::max());
	fill(vb, vb + m + 1, numeric_limits<int>::max());
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j <= n; ++j)
			va[j - i] = min(va[j - i], a[j] - a[i]);
	for (int i = 0; i < m; ++i)
		for (int j = i + 1; j <= m; ++j)
			vb[j - i] = min(vb[j - i], b[j] - b[i]);
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (va[i] * (ll)vb[j] <= x)
				ans = max(ans, i * j);
	printf("%d\n", ans);
	return 0;
}