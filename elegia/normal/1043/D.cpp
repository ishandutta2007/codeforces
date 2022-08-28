#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <numeric>
#include <limits>
#include <functional>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 100010;

int n, m;
vector<pair<int, int> > segs;
int a[N], b[N];

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	segs.emplace_back(1, n);
	while (--m) {
		for (int i = 1; i <= n; ++i) {
			int x;
			scanf("%d", &x);
			b[x] = i;
		}
		vector<pair<int, int> > ne;
		for (const auto& pr : segs) {
			int cur = pr.first;
			for (int i = pr.first + 1; i <= pr.second; ++i)
				if (b[a[i]] != b[a[i - 1]] + 1) {
					ne.emplace_back(cur, i - 1);
					cur = i;
				}
			ne.emplace_back(cur, pr.second);
		}
		swap(ne, segs);
	}
	ll ans = 0;
	for (const auto& pr : segs) {
		int l = pr.second - pr.first + 1;
		ans += l * (ll)(l + 1) / 2;
	}
	printf("%lld\n", ans);

#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}