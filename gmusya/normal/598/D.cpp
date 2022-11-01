#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int n, m, k;

vector <int> cnt;
vector <vector <bool>> used;
vector <vector <char>> c;
vector <vector <int>> d, comp;

void dfs(int x, int y, int pos) {
	used[x][y] = true;
	if (!used[x - 1][y] && c[x - 1][y] == '.')
		dfs(x - 1, y, pos);
	if (!used[x + 1][y] && c[x + 1][y] == '.')
		dfs(x + 1, y, pos);
	if (!used[x][y - 1] && c[x][y - 1] == '.')
		dfs(x, y - 1, pos);
	if (!used[x][y + 1] && c[x][y + 1] == '.')
		dfs(x, y + 1, pos);
	comp[x][y] = pos;
	cnt[pos] += d[x][y];
}

int main() {
	cin >> n >> m >> k;
	c.resize(n, vector<char>(m)), d.resize(n, vector<int>(m)), used.resize(n, vector<bool>(m)), comp.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> c[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (c[i][j] == '*')
				continue;
			d[i][j] = (c[i - 1][j] == '*') + (c[i + 1][j] == '*') + (c[i][j - 1] == '*') + (c[i][j + 1] == '*');
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!used[i][j] && c[i][j] == '.') {
				cnt.push_back(0);
				dfs(i, j, cnt.size() - 1);
			}
	vector <int> ans;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		ans.push_back(cnt[comp[x][y]]);
	}
	for (int x : ans)
		cout << x << endl;
	return 0;
}