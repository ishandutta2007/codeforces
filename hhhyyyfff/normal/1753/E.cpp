#include <bits/stdc++.h>

using namespace std;

map<int, vector<int>> mp;
vector<int> vc[40], ps[40];
char o[1000001];
int n, b, p, m, a[1000001], cnt;
long long c[40], px[40], mul, ans;
bool used[40];

void dfs(int x, long long lst, int b) {
	if (x == cnt) {
		long long l = 0, r = vc[0].empty() ? 0 : vc[0].back() * mul, mid;
		px[0] = 1;
		int totsum = 0;
		for (int i = 0; i < cnt; ++i) {
			px[i + 1] = px[i];
			if (used[i]) px[i + 1] *= c[i];
			if (px[i + 1] != 1) totsum += vc[i + 1].size();
			if (!vc[i + 1].empty())
				r = max(r, vc[i + 1].back() * mul);
		}
		b /= p;
		if (b >= totsum) {
			long long thistime = 0;
			for (int i = 0; i <= cnt; ++i)
				if (!ps[i].empty())
					thistime += ps[i].back();
			ans = max(ans, thistime * mul);
			return;
		}
		while (l < r) {
			mid = (l + r) / 2;
			int number = 0;
			for (int i = 0; i <= cnt; ++i) {
				if (px[i] == 1) continue;
				auto it = upper_bound(vc[i].begin(), vc[i].end(), mid / (mul - mul / px[i]));
				number += vc[i].end() - it;
			}
			if (number > b)
				l = mid + 1; else
				r = mid;
		}
		int number = 0;
		long long thistime = 0;
		for (int i = 0; i <= cnt; ++i) {
			if (vc[i].empty()) continue;
			if (px[i] == 1) {
				thistime += mul * ps[i].back();
				continue;
			}
			auto it = upper_bound(vc[i].begin(), vc[i].end(), l / (mul - mul / px[i]));
			number += vc[i].end() - it;
			if (it != vc[i].begin()) {
				thistime += (mul / px[i]) * ps[i][it - vc[i].begin() - 1];
				thistime += mul * (ps[i].back() - ps[i][it - vc[i].begin() - 1]);
			} else thistime += mul * ps[i].back();
		}
		if (number < b) thistime += l * (b - number);
		ans = max(ans, thistime);
		return;
	}
	used[x] = 1;
	dfs(x + 1, max(lst, c[x]), b);
	if (c[x] > lst && b >= m) {
		used[x] = 0;
		dfs(x + 1, lst, b - m);
	}
}

int main() {
	scanf("%d%d%d%d", &n, &b, &p, &m);
	mul = 1;
	for (int i = 1; i <= n; ++i) {
		scanf("\n");
		o[i] = getchar();
		scanf("%d", &a[i]);
		if (o[i] == '+') vc[cnt].push_back(a[i]); else
		if (a[i] != 1) mul *= c[cnt++] = a[i];
	}
	for (int i = 0; i <= cnt; ++i) {
		sort(vc[i].begin(), vc[i].end());
		if (vc[i].empty()) continue;
		ps[i].reserve(vc[i].size());
		ps[i].push_back(vc[i][0]);
		for (int j = 1; j < vc[i].size(); ++j)
			ps[i].push_back(ps[i].back() + vc[i][j]);
	}
	dfs(0, 0, b);
	printf("%lld\n", ans + mul);
	return 0;
}