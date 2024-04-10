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

const int N = 300010;

int n;
int x[N], y[N];
vector<pair<int, int> > pts;
int ans, ans3;

int dis(const pair<int, int>& p, const pair<int, int>& q) {
	return abs(p.first - q.first) + abs(p.second - q.second);
}

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &x[i], &y[i]);
	ans = abs(x[1] - x[n]) + abs(y[1] - y[n]);
	for (int i = 1; i < n; ++i)
		ans += abs(x[i] - x[i + 1]) + abs(y[i] - y[i + 1]);
	pts.emplace_back(x[1], y[1]);
	for (int i = 2; i < n; ++i) {
		if(abs(x[i - 1] - x[i + 1]) + abs(y[i - 1] - y[i + 1]) !=
		   abs(x[i] - x[i + 1]) + abs(y[i] - y[i + 1]) +
		   abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]))
		   pts.emplace_back(x[i], y[i]);
	}
	pts.emplace_back(x[n], y[n]);
	if (pts.size() < 3) {
		ans3 = ans;
	} else {
		int m = pts.size();
		for (int i = 1; i <= n; ++i) {
			pair<int, int> a = make_pair(x[i], y[i]);
			for (int j = 0; j < m; ++j)
				for (int k = j + 1; k < m; ++k)
					ans3 = max(ans3, dis(a, pts[j]) + dis(pts[j], pts[k]) + dis(pts[k], a));
		}
	}
	printf("%d", ans3);
	for (int i = 4; i <= n; ++i)
		printf(" %d", ans); 

#ifdef LBT
	LOG("%dms\n", (clock() - nol_cl) * 1000 / CLOCKS_PER_SEC);
#endif
	return 0;
}