#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <pii, int> ppi;

int n;
ppi a[100010];
vector <int> all;

struct BIT {
	int T[100010], tot;
	void clear() {memset(T, 0, sizeof(T)), tot = 0;}

	void modify(int x, int v) {
		tot += v;
		while (x <= 100005) T[x] += v, x += x & -x;
	}

	int query(int x) {
		int res = 0;
		while (x) res += T[x], x -= x & -x;
		return res;
	}

	int query(int l, int r) {
		return query(r) - query(l - 1);
	}
}T[3];

int Solve() {
	all.clear();
	int cnt[3] = {0, 0, 0};
	T[0].clear(), T[1].clear(), T[2].clear();
	for (int i = 0; i < n; i++) {
		all.push_back(a[i].fi.se);
		cnt[a[i].se]++;
	}
	sort(all.begin(), all.end()), all.resize(unique(all.begin(), all.end()) - all.begin());
	auto GetId = [&](int x) -> int {return lower_bound(all.begin(), all.end(), x) - all.begin() + 1;};
	sort(a, a + n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int j = i; while (j < n && a[i].fi.fi == a[j].fi.fi) j++;
		for (int k = i; k < j; k++) {
			T[a[k].se].modify(GetId(a[k].fi.se), 1);
		}
		for (int k = i; k < j; k++) {
			cnt[a[k].se]--;
		}
		for (int a = 0; a < 3; a++) {
			for (int b = 0; b < 3; b++) {
				if (a == b) continue;
				int c = 0 + 1 + 2 - a - b;
				int l = 1, r = all.size();
				while (l < r) {
					int mid = l + r + 1 >> 1;
					if (T[b].query(mid) < T[c].tot - T[c].query(mid)) l = mid;
					else r = mid - 1;
				}
				int val = min(T[b].query(l), T[c].tot - T[c].query(l));
				if (l < all.size()) {
					l++;
					val = max(val, min(T[b].query(l), T[c].tot - T[c].query(l)));
				}
				ans = max(ans, min(cnt[a], val));
			}
		}
		i = j - 1;
	}
	return ans;
}

int sum[3][100010];

int Work() {
	all.clear();
	for (int i = 0; i < n; i++) {
		all.push_back(a[i].fi.fi);
	}
	sort(all.begin(), all.end()), all.resize(unique(all.begin(), all.end()) - all.begin());
	int N = all.size();
	auto GetId = [&](int x) -> int {return lower_bound(all.begin(), all.end(), x) - all.begin();};
	for (int i = 0; i < N; i++) {
		sum[0][i] = sum[1][i] = sum[2][i] = 0;
	}
	for (int i = 0; i < n; i++) {
		sum[a[i].se][GetId(a[i].fi.fi)]++;
	}
	auto Check = [&](int mid) -> bool {
		if (mid == 0) return 1;
		int p[3] = {0, 1, 2};
		do {
			int cur = 0, tot = 0;
			for (int i = 0; i < N; i++) {
				BEG:;
				tot += sum[p[cur]][i];
				if (tot >= mid) {
					cur++, tot = 0;
					if (cur == 3) return 1;
					// goto BEG;
				}
			}
		} while (next_permutation(p, p + 3));
		return 0;
	};
	int l = 0, r = n / 3;
	while (l < r) {
		int mid = l + r + 1 >> 1;
		if (Check(mid)) l = mid;
		else r = mid - 1;
	}
	return l;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &a[i].fi.fi, &a[i].fi.se, &a[i].se), a[i].se--;
	}
	int ans = 0;
	ans = max(ans, Solve());
	for (int i = 0; i < n; i++) {
		a[i].fi.fi *= -1;
	}
	ans = max(ans, Solve());
	for (int i = 0; i < n; i++) {
		a[i].fi.fi *= -1;
		swap(a[i].fi.fi, a[i].fi.se);
	}
	ans = max(ans, Solve());
	for (int i = 0; i < n; i++) {
		a[i].fi.fi *= -1;
	}
	ans = max(ans, Solve());
	ans = max(ans, Work());
	for (int i = 0; i < n; i++) {
		swap(a[i].fi.fi, a[i].fi.se);
	}
	ans = max(ans, Work());
	printf("%d\n", ans * 3);
	return 0;
}