#include <bits/stdc++.h>

using namespace std;

vector<vector<long long>> d;
priority_queue<pair<long long, pair<int, int>>> h;
int n, m, p, q;

bool chk(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void upd(int x, int y, long long dist) {
	if (dist < d[x][y]) {
		d[x][y] = dist;
		h.push(make_pair(-dist, make_pair(x, y)));
	}
}

int main() {
	scanf("%d%d%d%d", &n, &m, &p, &q);
	vector<vector<char>> mp(n, vector<char>(m));
	vector<vector<bool>> vis(n, vector<bool>(m));
	d = vector<vector<long long>>(n, vector<long long>(m, LLONG_MAX));
	for (int i = 0; i < n; ++i) {
		scanf("\n");
		for (int j = 0; j < m; ++j) {
			mp[i][j] = getchar();
			if (mp[i][j] == '.') {
				d[i][j] = 0;
				h.push(make_pair(0, make_pair(i, j)));
			}
		}
	}
	while (!h.empty()) {
		pair<int, int> cur = h.top().second;
		int x = cur.first, y = cur.second;
		h.pop();
		if (vis[x][y]) continue;
		vis[x][y] = 1;
		if (chk(x - 1, y))
			if (mp[x - 1][y] == 'D')
				upd(x - 2, y, d[x][y] + q); else
			if (mp[x - 1][y] == 'R')
				upd(x - 1, y - 1, d[x][y] + p); else
			if (mp[x - 1][y] == 'L')
				upd(x - 1, y + 1, d[x][y] + p);
		if (chk(x + 1, y))
			if (mp[x + 1][y] == 'U')
				upd(x + 2, y, d[x][y] + q); else
			if (mp[x + 1][y] == 'R')
				upd(x + 1, y - 1, d[x][y] + p); else
			if (mp[x + 1][y] == 'L')
				upd(x + 1, y + 1, d[x][y] + p);
		if (chk(x, y - 1))
			if (mp[x][y - 1] == 'R')
				upd(x, y - 2, d[x][y] + q); else
			if (mp[x][y - 1] == 'D')
				upd(x - 1, y - 1, d[x][y] + p); else
			if (mp[x][y - 1] == 'U')
				upd(x + 1, y - 1, d[x][y] + p);
		if (chk(x, y + 1))
			if (mp[x][y + 1] == 'L')
				upd(x, y + 2, d[x][y] + q); else
			if (mp[x][y + 1] == 'D')
				upd(x - 1, y + 1, d[x][y] + p); else
			if (mp[x][y + 1] == 'U')
				upd(x + 1, y + 1, d[x][y] + p);
	}
	long long ans = LLONG_MAX;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j + 1 < m; ++j)
			if (d[i][j] != LLONG_MAX && d[i][j + 1] != LLONG_MAX)
				ans = min(ans, d[i][j] + d[i][j + 1]);
	for (int i = 0; i + 1 < n; ++i)
		for (int j = 0; j < m; ++j)
			if (d[i][j] != LLONG_MAX && d[i + 1][j] != LLONG_MAX)
				ans = min(ans, d[i][j] + d[i + 1][j]);
	printf("%lld\n", ans == LLONG_MAX ? -1 : ans);
	return 0;
}