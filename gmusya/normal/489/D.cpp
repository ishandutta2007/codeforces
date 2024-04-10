#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector <vector <bool>> mat(n, vector<bool>(n));
	vector <vector <int>> g(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		mat[u][v] = 1;
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			if (i != j) {
				int r = 0;
				for (int y : g[i])
					if (y != i && y != j && mat[y][j])
						r++;
				ans += r * (r - 1) / 2;
			}
	cout << ans;
	return 0;
}