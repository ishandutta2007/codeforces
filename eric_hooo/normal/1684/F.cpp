#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int n, m;
int a[200010];
int f[200010], g[200010];
int suc[200010], pre[200010];
vector <int> pos[200010];

struct RMQ {
	int f[200010][18];
	void Init(int *a, const function <int(int, int)> &fun) {
		for (int i = 1; i <= n; i++) {
			f[i][0] = a[i];
		}
		for (int j = 1; j < 18; j++) {
			for (int i = 1; i <= n; i++) {
				if (i + (1 << j) - 1 > n) break;
				f[i][j] = fun(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
			}
		}
	}
}SUC, PRE;

namespace DS {
	int cnt[200010], ccc[200010];
	void Clear(int n) {
		for (int i = 0; i <= n; i++) {
			cnt[i] = 0, ccc[i] = 0;
		}
		ccc[0] = n;
	}
	void Modify(int x, int w) {
		ccc[cnt[x]]--, cnt[x] += w, ccc[cnt[x]]++;
	}
	bool OK() {return ccc[0] + ccc[1] == n;}
}

void CalcF(int *f) {
	int p = 1; DS :: Clear(n);
	for (int i = 1; i <= n; i++) {
		while (p <= n) {
			DS :: Modify(a[p], 1);
			if (!DS :: OK()) {
				DS :: Modify(a[p], -1);
				break;
			}
			p++;
		}
		f[i] = p - 1;
		DS :: Modify(a[i], -1);
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		{
			static vector <int> all; all.clear();
			for (int i = 1; i <= n; i++) {
				all.push_back(a[i]);
			}
			sort(all.begin(), all.end()), all.resize(unique(all.begin(), all.end()) - all.begin());
			for (int i = 1; i <= n; i++) {
				a[i] = lower_bound(all.begin(), all.end(), a[i]) - all.begin() + 1;
			}
		}
		for (int i = 1; i <= n; i++) {
			pos[i].clear();
		}
		for (int i = 1; i <= n; i++) {
			pos[a[i]].push_back(i);
		}
		{
			static int lst[200010]; for (int i = 1; i <= n; i++) lst[i] = -1;
			for (int i = 1; i <= n; i++) {
				pre[i] = lst[a[i]], lst[a[i]] = i;
			}
		}
		{
			static int lst[200010]; for (int i = 1; i <= n; i++) lst[i] = n + 1;
			for (int i = n; i >= 1; i--) {
				suc[i] = lst[a[i]], lst[a[i]] = i;
			}
		}
		PRE.Init(pre, [&](int x, int y) -> int {return max(x, y);}), SUC.Init(suc, [&](int x, int y)-> int {return min(x, y);});
		CalcF(f), reverse(a + 1, a + n + 1), CalcF(g), reverse(a + 1, a + n + 1), reverse(g + 1, g + n + 1);
		for (int i = 1; i <= n; i++) {
			g[i] = n - g[i] + 1;
		}
		static vector <pii> rng; rng.clear();
		for (int i = 0; i < m; i++) {
			int l, r; scanf("%d%d", &l, &r);
			for (int j = 17; j >= 0; j--) {
				if (l + (1 << j) - 1 > n) continue;
				if (SUC.f[l][j] > r) l += (1 << j);
			}
			for (int j = 17; j >= 0; j--) {
				if (r - (1 << j) + 1 < 1) continue;
				if (PRE.f[r - (1 << j) + 1][j] < l) r -= (1 << j);
			}
			if (l > r) continue;
			rng.push_back(mp(l, r));
		}
		sort(rng.begin(), rng.end(), [&](pii x, pii y) -> bool {return x.fi != y.fi ? x.fi < y.fi : x.se > y.se;});
		rng.resize(unique(rng.begin(), rng.end()) - rng.begin());
		{
			int p = 0;
			for (int i = 0; i < rng.size(); i++) {
				if (!p || rng[i].se > rng[p - 1].se) rng[p++] = rng[i];
			}
			rng.resize(p);
		}
		if (!rng.size()) {
			printf("0\n");
			continue;
		}
		auto GetLef = [&](int x) -> int {
			auto it = lower_bound(rng.begin(), rng.end(), x, [&](pii x, int y) -> bool {return x.se < y;});
			if (it == rng.end()) return 0x3f3f3f3f;
			return it->fi;
		};
		auto GetRig = [&](int x) -> int {
			auto it = lower_bound(rng.begin(), rng.end(), x + 1, [&](pii x, int y) -> bool {return x.fi < y;});
			if (it == rng.begin()) return -0x3f3f3f3f;
			return (--it)->se;
		};
		int R = 0;
		for (auto it : rng) {
			R = max(R, g[it.se] - 1);
		}
		int ans = R;
		for (int i = 1; i <= n; i++) {
			int x = a[i];
			if (GetLef(i) <= pre[i]) break;
			int lim = GetRig(i);
			auto it = upper_bound(pos[x].begin(), pos[x].end(), lim);
			if (it != pos[x].begin()) R = max(R, *--it);
			ans = min(ans, R - i);
		}
		printf("%d\n", ans);
	}
	return 0;
}