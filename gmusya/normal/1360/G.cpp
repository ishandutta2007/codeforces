#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, a, b;
		cin >> n >> m >> a >> b;
		if (a * n != b * m) {
			cout << "NO\n";
			continue;
		}
		int tor;
		for (tor = 1; tor < m; tor++)
			if (tor * n % m == 0)
				break;
		vector <vector <int>> ans(n, vector <int>(m));
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < a; j++)
				ans[i][(j + i * tor) % m] = 1;
		cout << "YES\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << ans[i][j];
			cout << '\n';
		}
	}
	return 0;
}