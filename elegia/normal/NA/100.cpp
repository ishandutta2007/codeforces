#include <cstdio>
#include <cstring>

#include <algorithm>
#include <set>
#include <queue>
#include <vector>
#include <numeric>
#include <limits>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

int n, m, ce, cl, v;
set<int> fl, el;

int iabs(int x) {
	return x < 0 ? -x : x;
}

int main() {
	scanf("%d%d%d%d%d", &n, &m, &cl, &ce, &v);
	while (cl--) {
		int x;
		scanf("%d", &x);
		fl.insert(x);
	}
	while (ce--) {
		int x;
		scanf("%d", &x);
		el.insert(x);
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int x1, y1, x2, y2, xdist;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		xdist = x1 - x2;
		if (xdist < 0)
			xdist = -xdist;
		if (xdist == 0) {
			printf("%d\n", iabs(y1 - y2));
			continue;
		}
		int ans = numeric_limits<int>::max();
		set<int>::iterator it;
		if (y1 > y2)
			swap(y1, y2);
		if (!fl.empty()) {
			it = fl.lower_bound(y1);
			if (it != fl.end())
				ans = min(ans, xdist + iabs(y1 - *it) + iabs(y2 - *it));
			if (it != fl.begin()) {
				--it;
				ans = min(ans, xdist + iabs(y1 - *it) + iabs(y2 - *it));
			}
		}
		if (!el.empty()) {
			xdist = (xdist + v - 1) / v;
			it = el.lower_bound(y1);
			if (it != el.end())
				ans = min(ans, xdist + iabs(y1 - *it) + iabs(y2 - *it));
			if (it != el.begin()) {
				--it;
				ans = min(ans, xdist + iabs(y1 - *it) + iabs(y2 - *it));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}