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

struct Robot {
	int x, r, q;

	bool operator>(const Robot& rhs) const { return r > rhs.r; }
};

const int N = 100010;

int n, k;
int disc[N];
Robot rbt[N];

map<int, int> fw[N];

int lowBit(int k) { return k & -k; }
void ch(int k, int x);
int q(int k, int x);

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d", &rbt[i].x, &rbt[i].r, &rbt[i].q);
		disc[i] = rbt[i].x;
	}
	sort(rbt + 1, rbt + n + 1, greater<Robot>());
	sort(disc + 1, disc + n + 1);
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += q(upper_bound(disc + 1, disc + n + 1, rbt[i].x + rbt[i].r) - disc - 1, rbt[i].q) -
				q(lower_bound(disc + 1, disc + n + 1, rbt[i].x - rbt[i].r) - disc - 1, rbt[i].q);
		ch(lower_bound(disc + 1, disc + n + 1, rbt[i].x) - disc, rbt[i].q);
	}
	printf("%lld\n", ans);

#ifndef ONLINE_JUDGE
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}

void ch(int k, int x) {
	for (; k <= n; k += lowBit(k))
		++fw[k][x];
}

int q(int k, int x) {
	int ret = 0;
	for (; k; k -= lowBit(k)) {
		int l = x - ::k, r = x + ::k;
		map<int, int>::iterator it = fw[k].lower_bound(l);
		while (it != fw[k].end() && it->first <= r)
			ret += it++->second;
	}
	return ret;
}