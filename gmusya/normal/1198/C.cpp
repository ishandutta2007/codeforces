#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector <int> e;
		vector <bool> used(3 * n);
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			if (used[u] || used[v]) continue;
			e.push_back(i);
			used[u] = used[v] = true;
		}
		if (e.size() >= n) {
			cout << "Matching\n";
			for (int i = 0; i < n; i++)
				cout << e[i] + 1 << '\n';
			continue;
		}
		cout << "IndSet\n";
		int cnt = 0;
		for (int i = 0; i < 3 * n; i++) {
			if (cnt == n) break;
			if (!used[i]) {
				cout << i + 1 << ' ';
				cnt++;
			}
		}
		cout << '\n';
	}
	return 0;
}