#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define endl '\n'

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <vector <int>> g(n);
		vector <int> deg(n);
		for (int i = 1; i < n; i++) {
			int u = i - 1, v = i;
			char c;
			cin >> c;
			if (c == '<') {
				g[u].push_back(v);
				deg[v]++;
				continue;
			}
			g[v].push_back(u);
			deg[u]++;
		}
		{
			vector <int> copy_deg = deg;
			int it = 1;
			vector <int> ans(n);
			set <int> q;
			for (int i = 0; i < n; i++)
				if (!copy_deg[i])
					q.insert(i);
			while (!q.empty()) {
				int v = *(--q.end());
				q.erase(--q.end());
				ans[v] = it++;
				for (int u : g[v]) {
					copy_deg[u]--;
					if (!copy_deg[u])
						q.insert(u);
				}
			}
			for (int i = 0; i < n; i++)
				cout << ans[i] << " ";
			cout << endl;
		}
		{
			vector <int> copy_deg = deg;
			int it = 1;
			vector <int> ans(n);
			set <int> q;
			for (int i = 0; i < n; i++)
				if (!copy_deg[i])
					q.insert(i);
			while (!q.empty()) {
				int v = *q.begin();
				q.erase(q.begin());
				ans[v] = it++;
				for (int u : g[v]) {
					copy_deg[u]--;
					if (!copy_deg[u])
						q.insert(u);
				}
			}
			for (int i = 0; i < n; i++)
				cout << ans[i] << " ";
			cout << endl;
		}
	}
	return 0;
}