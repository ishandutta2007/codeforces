#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, x, y;
		cin >> n >> m >> x >> y;
		int cntW = 0;
		vector <vector <char>> c(n, vector <char>(m));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				cin >> c[i][j];
				cntW += (c[i][j] == '.');
			}
		if (2 * x <= y) {
			cout << cntW * x << '\n';
			continue;
		}
		int cnt12 = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m - 1; j++) 
				if (c[i][j] == '.' && c[i][j + 1] == '.') cnt12++, j++;
		cout << cnt12 * y + (cntW - 2 * cnt12) * x << '\n';
	}
	return 0;
}