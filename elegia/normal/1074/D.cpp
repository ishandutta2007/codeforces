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
#include <unordered_map>

#define LOG(FMT...) // fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 200010;

int n;
int f[N * 2], val[N * 2];

unordered_map<int, int> mp;

int get(int x) {
	static int t;
	if (!mp[x]) {
		++t;
		f[t] = t;
		return mp[x] = t;
	} else
		return mp[x];
}

int find(int x) {
	if (f[x] == x)
		return x;
	find(f[x]);
	val[x] ^= val[f[x]];
	f[x] = f[f[x]];
	return f[x];
}

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	int last = 0;
	scanf("%d", &n);
	while (n--) {
		int t, l, r;
		scanf("%d%d%d", &t, &l, &r);
		l ^= last;
		r ^= last;
		if (l > r)
			swap(l, r);
		LOG("DO %d %d\n", l, r);
		++r;
		l = get(l);
		r = get(r);
		if (t == 1) {
			int x;
			scanf("%d", &x);
			x ^= last;
			if (find(l) == find(r))
				continue;
			val[f[l]] = x ^ val[l] ^ val[r];
			f[f[l]] = f[r];
			LOG("BEF %d %d\n", val[l], val[r]);
			find(l);
			LOG("AFT %d %d\n", val[l], val[r]);
			LOG("CHK %d %d\n", x, val[l] ^ val[r]);
		} else {
			if (find(l) != find(r)) {
				puts("-1");
				last = 1;
			} else
				printf("%d\n", last = val[l] ^ val[r]);
		}
	}

#ifdef LBT
	LOG("%dms\n", (clock() - nol_cl) * 1000 / CLOCKS_PER_SEC);
#endif
	return 0;
}