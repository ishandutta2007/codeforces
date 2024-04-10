#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, p;
	cin >> n >> m >> p;
	vector <int> s(p + 1);
	for (int i = 1; i <= p; i++)
		cin >> s[i];
	vector <vector <int>> c(n, vector <int>(m));
	vector <vector <int>> d(n, vector<int>(m, INF));
	vector <queue <pair <int, int>>> q(p + 1);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			char x;
			cin >> x;
			if (x == '#') c[i][j] = -1;
			if (x >= '1' && x <= '9') {
				c[i][j] = x - '0';
				q[c[i][j]].push({ i, j });
				d[i][j] = 0;
			}
		}
	int cnt = p;
	int it = 0;
	while (cnt) {
		it++;
		for (int i = 1; i <= p; i++) {
			cnt -= !q[i].empty();
			while (!q[i].empty()) {
				int x = q[i].front().first, y = q[i].front().second;
				if (d[x][y] == s[i] * it) break;
				q[i].pop();
				if (x && d[x][y] + 1 < d[x - 1][y] && c[x - 1][y] == 0) {
					c[x - 1][y] = i;
					d[x - 1][y] = d[x][y] + 1;
					q[i].push({ x - 1, y });
				}
				if (y && d[x][y] + 1 < d[x][y - 1] && c[x][y - 1] == 0) {
					c[x][y - 1] = i;
					d[x][y - 1] = d[x][y] + 1;
					q[i].push({ x, y - 1 });
				}
				if (x + 1 < n && d[x][y] + 1 < d[x + 1][y] && c[x + 1][y] == 0) {
					c[x + 1][y] = i;
					d[x + 1][y] = d[x][y] + 1;
					q[i].push({ x + 1, y });
				}
				if (y + 1 < m && d[x][y] + 1 < d[x][y + 1] && c[x][y + 1] == 0) {
					c[x][y + 1] = i;
					d[x][y + 1] = d[x][y] + 1;
					q[i].push({ x, y + 1 });
				}
			}
			cnt += !q[i].empty();
		}
	}
	vector <int> ans(p + 1);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (c[i][j] > 0)
				ans[c[i][j]]++;
	for (int i = 1; i <= p; i++)
		cout << ans[i] << ' ';
	return 0;
}