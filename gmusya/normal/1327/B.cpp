#include <iostream>
#include <vector>

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
		for (int i = 0; i < n; i++) {
			int m;
			cin >> m;
			g[i].resize(m);
			for (int j = 0; j < m; j++) {
				cin >> g[i][j];
				--g[i][j];
			}
		}
		vector <bool> l(n), r(n);
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < g[i].size(); j++)
				if (!r[g[i][j]]) {
					r[g[i][j]] = true;
					l[i] = true;
					break;
				}
		int L = -1, R = -1;
		for (int i = 0; i < n; i++) 
			if (!l[i]) {
				L = i;
				break;
			}
		for (int i = 0; i < n; i++)
			if (!r[i]) {
				R = i;
				break;
			}
		if (L == -1) cout << "OPTIMAL\n";
		else cout << "IMPROVE\n" << L + 1 << ' ' << R + 1 << '\n';
	}
	return 0;
}