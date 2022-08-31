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

const int N = 200010, X = 21;

ll ans = 0;
int cnt, n, k, m, rm;
int l[N], r[N], p[N], c[N];
vector<pair<int, int> > apply[N * 2];
int disc[N * 2];

ll cfw[1 << X];
ll sfw[1 << X];

int lowBit(int k) { return k & -k; }

void ch(int k, int x) {
	int pr = k;
	for (; k < (1 << X); k += lowBit(k)) {
		cfw[k] += x;
		sfw[k] += x * (ll)pr;
	}
} 

ll q(int k) {
	ll ret = 0;
	for (; k; k -= lowBit(k))
		ret += sfw[k];
	return ret;
}

int bd(int x) {
	int ret = 0;
	for (int j = X - 1; j >= 0; --j) 
		if (cfw[ret | (1 << j)] < x)
			x -= cfw[ret |= 1 << j];
	rm = x;
	return ret + 1;
}

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d%d%d", &n, &k, &m);
	disc[++cnt] = 1;
	disc[++cnt] = n + 1;
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%d%d", &l[i], &r[i], &c[i], &p[i]);
		disc[++cnt] = l[i];
		disc[++cnt] = ++r[i];
	}
	sort(disc + 1, disc + cnt + 1);
	cnt = unique(disc + 1, disc + cnt + 1) - disc - 1;
	for (int i = 1; i <= m; ++i) {
		l[i] = lower_bound(disc + 1, disc + cnt + 1, l[i]) - disc;
		r[i] = lower_bound(disc + 1, disc + cnt + 1, r[i]) - disc;
		apply[l[i]].emplace_back(p[i], c[i]);
		apply[r[i]].emplace_back(p[i], -c[i]);
	}
	ll cc = 0;
	for (int i = 1; i < cnt; ++i) {
		for (const auto& pr : apply[i]) {
			cc += pr.second;
			ch(pr.first, pr.second);
		}
		ll cost = 0;
		if (cc <= k) {
			cost = q((1 << X) - 1);
		} else {
			int bb = bd(k);
			cost = rm * (ll)bb + q(bb - 1);
		}
		ans += cost * (disc[i + 1] - disc[i]);
	}
	printf("%lld\n", ans);

#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}