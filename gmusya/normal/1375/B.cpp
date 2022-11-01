#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector <vector <int>> a(n, vector <int>(m));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> a[i][j];
		bool tf = true;
		if (a[0][0] > 2) tf = false;
		else a[0][0] = 2;
		if (a[n - 1][m - 1] > 2) tf = false;
		else a[n - 1][m - 1] = 2;
		if (a[0][m - 1] > 2) tf = false;
		else a[0][m - 1] = 2;
		if (a[n - 1][0] > 2) tf = false;
		else a[n - 1][0] = 2;
		for (int i = 1; i < n - 1; i++) {
			if (a[i][0] > 3) tf = false;
			else a[i][0] = 3;
		}
		for (int i = 1; i < n - 1; i++) {
			if (a[i][m - 1] > 3) tf = false;
			else a[i][m - 1] = 3;
		}
		for (int j = 1; j < m - 1; j++) {
			if (a[0][j] > 3) tf = false;
			else a[0][j] = 3;
		}
		for (int j = 1; j < m - 1; j++) {
			if (a[n - 1][j] > 3) tf = false;
			a[n - 1][j] = 3;
		}
		for (int i = 1; i < n - 1; i++) 
			for (int j = 1; j < m - 1; j++) {
				if (a[i][j] > 4) tf = false;
				else a[i][j] = 4;
			}
		if (!tf) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << a[i][j] << ' ';
			cout << '\n';
		}
	}
	return 0;
}