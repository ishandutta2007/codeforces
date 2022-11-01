#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int ans = 0;

map <pair <int, int>, set <pair <int, int>>> ed;
map <pair <int, int>, int> ma;

const int INF = 1e7;
int n, m, k;

void rec(int pos, vector <int> &hm) {
	if (pos == k) {
		ans++;
		return;
	}
	for (int i = 0; i <= pos; i++) {
		if (ma[{i, pos}] <= 0) continue;
		for (auto &now : ed[{i, pos}]) 
			ma[now]--;
		if (ma[{i, pos}] <= 0) {
			for (auto &now : ed[{i, pos}])
				ma[now]++;
			continue;
		}
		hm.push_back(i);
		rec(pos + 1, hm);
		hm.pop_back();
		for (auto &now : ed[{i, pos}])
			ma[now]++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	vector <vector <pair <int, int>>> g(n);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		g[u].push_back({ w, v });
	}
	for (int i = 0; i < n; i++)
		sort(g[i].begin(), g[i].end());

	vector <vector <pair <int, int>>> s(n);

	for (int v = 0; v < n; v++)
		for (int i = 0; i < g[v].size(); i++)
			s[g[v][i].second].push_back({ i, g[v].size() - 1 });

	for (int v = 0; v < n; v++) {
		sort(s[v].begin(), s[v].end());
		vector <pair <int, int>> x;
		for (int i = 0; i < s[v].size(); i++)
			if (i < 2 || (s[v][i] != s[v][i - 2]))
				x.push_back(s[v][i]);
		for (int i = 0; i < x.size(); i++)
			for (int j = 0; j < x.size(); j++) {
				if (i == j) continue;
				pair <int, int> now1 = x[i], now2 = x[j];
				if (now1.second > now2.second) swap(now1, now2);
				ed[now1].insert(now2);
			}
	}

	for (int i = 0; i < k; i++)
		for (int j = 0; j <= i; j++)
			ma[{j, i}] = 1;
	vector <int> hm;
	rec(0, hm);
	cout << ans;
	return 0;
}