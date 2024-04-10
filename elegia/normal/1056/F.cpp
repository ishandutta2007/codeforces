#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <numeric>
#include <limits>
#include <functional>
#include <iostream>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 110;

int n;
pair<int, int> task[N];
double dp[N][N * 10];
double c, t;

double minimize(double v, double c) {
	if (sqrt(v / c) - 1 / c < 0)
		return v;
	else
		return 2 * sqrt(v / c) - 1 / c;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%lf%lf", &n, &c, &t);
		for (int i = 1; i <= n; ++i)
			scanf("%d%d", &task[i].first, &task[i].second);
		sort(task + 1, task + n + 1);
		fill(dp[0], dp[n + 1], numeric_limits<double>::max());
		dp[0][0] = 0;
		for (int i = 1; i <= n; ++i) {
			for (int v = 10 * i; v >= task[i].second; --v)
				for (int j = i; j; --j)
					dp[j][v] = min(dp[j][v], (dp[j - 1][v - task[i].second] + task[i].first) / 0.9);
		}
		int ans = 0;
		for (int v = 10 * n; v; --v) {
			for (int i = 1; i <= n; ++i) {
				double tt = minimize(dp[i][v], c) + 10 * i;
				if (tt <= t) {
					ans = v;
					break;
				}
			}
			if (ans)
				break;
		}
		printf("%d\n", ans);
	}
	return 0;
}