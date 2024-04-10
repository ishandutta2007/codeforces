#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define MAXN 20
#define BIGINF (1000000000000000LL)

typedef long long lint;

using namespace std;

int a[MAXN], b[MAXN];
lint mincost[MAXN+1][MAXN+1+MAXN];
lint minmincost[MAXN+1][MAXN+1+MAXN];

lint dp[2][MAXN+1][MAXN+1+MAXN];

int main(int argc, char ** argv)
{
	int n, m;

	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	
	const int offd = n;

	int now = 0, prev = 1;

	for (int ms = 0; ms <= n; ms++) for (int d = -n; d <= n; d++) dp[prev][ms][d+offd] = BIGINF;
	dp[prev][0][0+offd] = 0;

	for (int i = 0; i < n; i++) {
		for (int ms = 0; ms <= n; ms++) for (int d = -n; d <= n; d++) dp[now][ms][d+offd] = BIGINF;

		for (int ms = 0; ms <= n; ms++)
			for (int d = -n; d <= n; d++) {
				if (d+1 <= n) {
					dp[now][ms][d+1+offd] = min(dp[now][ms][d+1+offd], dp[prev][ms][d+offd] + a[i]);
				}

				if (d-1 >= -n) {
					dp[now][max(ms, -(d-1))][d-1+offd] = min(dp[now][max(ms, -(d-1))][d-1+offd], dp[prev][ms][d+offd] + b[i]);
				}
			}

		swap(now, prev);
	}

	memcpy(mincost, dp[prev], sizeof(mincost));
	memcpy(minmincost, mincost, sizeof(minmincost));

	for (int ms = 1; ms <= n; ms++)
		for (int d = -n; d <= n; d++)
			minmincost[ms][d+offd] = min(minmincost[ms][d+offd], minmincost[ms-1][d+offd]);

	lint result = BIGINF;

	const int ms1 = 0;
	for (int d1 = 0; d1 <= n; d1++) {
		lint c1 = mincost[ms1][d1 + offd];

		if (c1 == BIGINF) continue;

		lint midc = 0;
		int now = 0;

		vector <int> costs;
		vector <int> nopen(n);

		for (int i = 0; i < n; i++) {
			midc += a[i] * (m-2);
			now += m-2;
			nopen[i] = m-2;
			costs.push_back(b[i]-a[i]);
		}
		sort(costs.begin(), costs.end());

		int next = 0;

		for (int d2 = -n; d2 <= 0; d2++) {
			lint c2 = minmincost[-d2][d2+offd];
			int midd = -d1-d2;

			if (c2 == BIGINF) continue;

			for (int &i = next; i < n; i++) {
				int exc = max(now - midd, 0);
				int change = min(exc/2, nopen[i]);
				
				nopen[i] -= change;
				now -= 2 * change;
				midc += change * costs[i];

				if (nopen[i] > 0) break;
			}

			if (now == midd) {
				result = min(result, c1 + midc + c2);
			}
		}
	}

	printf("%d\n", (int)result);

	return 0;
}