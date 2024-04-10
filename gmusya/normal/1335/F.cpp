#include <iostream>
#include <vector>
#include <queue>

#define endl '\n'

using namespace std;

void dfs1(int v, vector <bool> &used, vector <int> &comp, vector <vector <int>> &g) {
	used[v] = true;
	for (int u : g[v])
		if (!used[u])
			dfs1(u, used, comp, g);
	comp.push_back(v);
}

void dfs2(int v, int &cnt, vector <int> &colour, vector <vector <int>> &g) {
	for (int u : g[v]) 
		if (colour[u] == -1) {
			colour[u] = (colour[v] + cnt - 1) % cnt;
			dfs2(u, cnt, colour, g);
		}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector <vector <char>> black_or_white(n, vector <char>(m));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> black_or_white[i][j];
		vector <vector <char>> c(n, vector <char>(m));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> c[i][j];
		vector <int> indeg(n * m), colour(n * m, -1);
		vector <vector <int>> g(n * m), org(n * m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				int u = i * m + j;
				int _i, _j;
				if (c[i][j] == 'U') _i = i - 1, _j = j;
				if (c[i][j] == 'D') _i = i + 1, _j = j;
				if (c[i][j] == 'R') _i = i, _j = j + 1;
				if (c[i][j] == 'L') _i = i, _j = j - 1;
				int v = _i * m + _j;
				g[u].push_back(v), g[v].push_back(u);
				org[u].push_back(v);
				indeg[v]++;
			}
		vector <bool> used(n * m);
		int ma = 0, bl = 0;
		for (int i = 0; i < n * m; i++) 
			if (!used[i]) {
				vector <int> comp;
				dfs1(i, used, comp, g);
				queue <int> q;
				for (int i = 0; i < comp.size(); i++)
					if (!indeg[comp[i]])
						q.push(comp[i]);
				int cnt = comp.size();
				int v_in_cycle = comp[0];
				while (!q.empty()) {
					cnt--;
					int v = q.front();
					q.pop();
					for (int u : org[v]) {
						indeg[u]--;
						v_in_cycle = u;
						if (!indeg[u])
							q.push(u);
					}
				}
				vector <int> cycle;
				colour[v_in_cycle] = 0;
				int old_v_in_cycle = v_in_cycle;
				int new_v_in_cycle = org[v_in_cycle][0];
				cycle.push_back(v_in_cycle);
				while (new_v_in_cycle != v_in_cycle) {
					colour[new_v_in_cycle] = (colour[old_v_in_cycle] + 1) % cnt;
					old_v_in_cycle = new_v_in_cycle;
					new_v_in_cycle = org[new_v_in_cycle][0];
					cycle.push_back(old_v_in_cycle);
				}
				for (int i = 0; i < cnt; i++)
					dfs2(cycle[i], cnt, colour, g);
				ma += cnt;
				vector <bool> flag(cnt);
				for (int j = 0; j < comp.size(); j++) {
					int v = comp[j];
					int x = v / m;
					int y = v % m;
					if (black_or_white[x][y] == '0') 
						flag[colour[v]] = true;
				}
				for (int j = 0; j < cnt; j++)
					bl += flag[j];
			}
		cout << ma << " " << bl << endl;
	}
	return 0;
}