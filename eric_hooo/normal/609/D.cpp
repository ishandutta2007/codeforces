#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int n, m, k, s;
int a[2][200010];
vector <pii> all[2];
vector <long long> sum[2];

bool check(int mid) {
	int c[2] = {0x3f3f3f3f, 0x3f3f3f3f};
	for (int _ = 0; _ < 2; _++) {
		for (int i = 0; i <= mid; i++) {
			c[_] = min(c[_], a[_][i]);
		}
	}
	long long ans = 0x3f3f3f3f3f3f3f3f;
	for (int i = 0; i <= k; i++) {
		if (i > all[0].size() || k - i > all[1].size()) continue;
		ans = min(ans, (i ? sum[0][i - 1] : 0) * c[0] + (k - i ? sum[1][k - i - 1] : 0) * c[1]);
	}
	return ans <= s;
}

void print(int mid) {
	int c[2] = {0x3f3f3f3f, 0x3f3f3f3f}, d[2] = {-1, -1};
	for (int _ = 0; _ < 2; _++) {
		for (int i = 0; i <= mid; i++) {
			if (c[_] > a[_][i]) {
				c[_] = a[_][i];
				d[_] = i;
			}
		}
	}
	long long ans = 0x3f3f3f3f3f3f3f3f;
	int pos = -1;
	for (int i = 0; i <= k; i++) {
		if (i > all[0].size() || k - i > all[1].size()) continue;
		if (ans > (i ? sum[0][i - 1] : 0) * c[0] + (k - i ? sum[1][k - i - 1] : 0) * c[1]) {
			ans = (i ? sum[0][i - 1] : 0) * c[0] + (k - i ? sum[1][k - i - 1] : 0) * c[1];
			pos = i;
		}
	}
	for (int i = 0; i < pos; i++) {
		printf("%d %d\n", all[0][i].se + 1, d[0] + 1);
	}
	for (int i = 0; i < k - pos; i++) {
		printf("%d %d\n", all[1][i].se + 1, d[1] + 1);
	}
}

int main () {
	scanf("%d%d%d%d", &n, &m, &k, &s);
	for (int _ = 0; _ < 2; _++) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[_][i]);
		}
	}
	for (int i = 0; i < m; i++) {
		int t, c; scanf("%d%d", &t, &c);
		all[t - 1].push_back(mp(c, i));
	}
	sort(all[0].begin(), all[0].end()), sort(all[1].begin(), all[1].end());
	for (int _ = 0; _ < 2; _++) {
		for (int i = 0; i < all[_].size(); i++) {
			if (i) sum[_].push_back(sum[_].back() + all[_][i].fi);
			else sum[_].push_back(all[_][i].fi);
		}
	}
	int l = 0, r = n;
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	if (l == n) {
		printf("-1\n");
		return 0;
	}
	printf("%d\n", l + 1);
	print(l);
	return 0;
}