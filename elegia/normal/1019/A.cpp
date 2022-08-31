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

const int N = 3010;

int n, m;
int cnt[N], tmp[N];
bool vis[N];
pair<int, int> hh[N];

int main() {

	scanf("%d%d", &n, &m);
	int alr = 0, cc = 0;
	for (int rep = 1; rep <= n; ++rep) {
		int p, c;
		scanf("%d%d", &p, &c);
		if (p != 1) {
			++tmp[p];
			hh[++cc] = make_pair(c, p);
		} else
			++alr;
	}

	sort(hh + 1, hh + cc + 1);

	ll ans = numeric_limits<ll>::max();
	for (int c = alr; c <= n; ++c) {
		memcpy(cnt, tmp, sizeof(cnt));
		memset(vis, 0, sizeof(vis));
		ll cur = 0, talr = alr;
		for (int i = 1; i <= cc; ++i)
			if (cnt[hh[i].second] >= c) {
				cur += hh[i].first;
				--cnt[hh[i].second];
				vis[i] = true;
				++talr;
			}
		for (int i = 1; i <= cc; ++i)
			if (talr < c && !vis[i]) {
				++talr;
				cur += hh[i].first;
			}
		ans = min(ans, cur);
	}

	printf("%lld\n", ans);

	return 0;
}