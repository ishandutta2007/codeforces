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

const int N = 300010;

int n;
int a[N], sum[N], cnt[N][2];

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d", &n);
	cnt[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		ll x;
		scanf("%lld", &x);
		a[i] = __builtin_popcountll(x);
		sum[i] = (a[i] & 1) ^ sum[i - 1];
		cnt[i][0] = cnt[i - 1][0];
		cnt[i][1] = cnt[i - 1][1];
		++cnt[i][sum[i]];
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		int mx = 0, sum = 0;
		for (int j = i; j > 0 && i - j + 1 <= 120; --j) {
			mx = max(mx, a[j]);
			sum += a[j];
			if (!(sum & 1) && 2 * mx <= sum)
				++ans;
		}
		if (i - 121 >= 0)
			ans += cnt[i - 121][::sum[i]];
	}
	printf("%lld\n", ans);


#ifndef ONLINE_JUDGE
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}