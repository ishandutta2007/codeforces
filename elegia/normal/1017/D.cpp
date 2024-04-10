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

const int N = 1 << 12, K = 110;

int U;
char str[20];
int a[20];
int val[N];
int cnt[N];
int dp[N][K];

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	U = (1 << n) - 1;
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for (int s = 0; s <= U; ++s)
		for (int i = 0; i < n; ++i)
			if ((s >> i) & 1)
				val[s] += a[i];
	while (m--) {
		scanf("%s", str);
		int s = 0;
		for (int i = 0; i < n; ++i)
			s |= (str[i] - '0') << i;
		++cnt[s];
	}
	for (int s = 0; s <= U; ++s) {
		for (int t = 0; t <= U; ++t) {
			int v = val[U ^ (s ^ t)];
			if (v <= 100)
				dp[s][v] += cnt[t];
		}
		for (int i = 1; i <= 100; ++i)
			dp[s][i] += dp[s][i - 1];
	}
	while (q--) {
		int k;
		scanf("%s%d", str, &k);
		int s = 0;
		for (int i = 0; i < n; ++i)
			s |= (str[i] - '0') << i;
		printf("%d\n", dp[s][k]);
	}

#ifndef ONLINE_JUDGE
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}