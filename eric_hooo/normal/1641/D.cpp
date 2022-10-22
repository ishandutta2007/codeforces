#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int n, m;
vector <int> a[100010];
int id[100010][32];
int W[100010];
deque <int> seq;
unordered_map <ull, int> ID;
int f[3300000];
int cnt[32];

int main() {
	cnt[0] = 0; for (int i = 1; i < 32; i++) cnt[i] = cnt[i >> 1] + (i & 1);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x; scanf("%d", &x);
			a[i].push_back(x);
		}
		scanf("%d", &W[i]);
		sort(a[i].begin(), a[i].end());
		for (int mask = 0; mask < (1 << m); mask++) {
			ull tmp = 0;
			for (int j = 0; j < m; j++) {
				if (mask >> j & 1) tmp = tmp * 323232323 + a[i][j];
			}
			if (!ID.count(tmp)) ID[tmp] = ID.size();
			id[i][mask] = ID[tmp];
		}
		seq.push_back(i);
	}
	sort(seq.begin(), seq.end(), [&](int x, int y) -> bool {return W[x] < W[y];});
	auto Check = [&](long long mid) -> bool {
		memset(f, 0, sizeof(f));
		auto jt = seq.begin();
		auto Insert = [&](int x) -> void {
			for (int mask = 0; mask < (1 << m); mask++) {
				f[id[x][mask]]++;
			}
		};
		for (int it = n - 1; it >= 0; it--) {
			int x = seq[it];
			while (jt != seq.end() && W[*jt] + W[x] <= mid) Insert(*jt), jt++;
			int tot = 0;
			for (int mask = 0; mask < (1 << m); mask++) {
				tot += f[id[x][mask]] * (cnt[mask] & 1 ? -1 : 1);
			}
			if (tot) return 1;
		}
		return 0;
	};
	long long l = 0, r = 2000000001;
	while (l < r) {
		long long mid = l + r >> 1;
		if (Check(mid)) r = mid;
		else l = mid + 1;
	}
	if (l == 2000000001) l = -1;
	printf("%lld\n", l);
	return 0;
}