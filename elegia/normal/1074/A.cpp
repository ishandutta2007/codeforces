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

int n, m; 
vector<int> ver, hor;

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d%d", &n, &m);
	while (n--) {
		int x;
		scanf("%d", &x);
		ver.push_back(x);
	}
	while (m--) {
		int x1, x2, y;
		scanf("%d%d%d", &x1, &x2, &y);
		if (x1 != 1)
			continue;
		hor.push_back(x2);
	}
	int ans = ver.size() + hor.size();
	sort(ver.begin(), ver.end());
	sort(hor.begin(), hor.end());
	for (int i = 0; i < ver.size(); ++i) {
		int cur = i + (hor.end() - lower_bound(hor.begin(), hor.end(), ver[i]));
		ans = min(ans, cur);
	}
	ans = min(ans, int(ver.size() + count(hor.begin(), hor.end(), 1e9)));
	printf("%d\n", ans);

#ifdef LBT
	LOG("%dms\n", (clock() - nol_cl) * 1000 / CLOCKS_PER_SEC);
#endif
	return 0;
}