#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector <vector <char>> c(n, vector <char>(m));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> c[i][j];
		int cnt = 0;
		for (int i = 0; i < n - 1; i++)
			cnt += (c[i][m - 1] == 'R');
		for (int j = 0; j < m - 1; j++)
			cnt += (c[n - 1][j] == 'D');
		cout << cnt << '\n';
	}
	return 0;
}