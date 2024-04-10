#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector <vector <char>> a(n + 1);
	for (int i = 0; i <= n; i++)
		a[i].resize(m + 1, '.');
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	bool tf = true;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if ((a[i][j] == 'S' && a[i + 1][j] == 'W') || (a[i][j] == 'S' && a[i][j + 1] == 'W') || (a[i][j] == 'W' && a[i + 1][j] == 'S') || (a[i][j] == 'W' && a[i][j + 1] == 'S'))
				tf = false;
	if (!tf)
		cout << "No";
	else {
		cout << "Yes" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == '.')
					cout << 'D';
				else
					cout << a[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}