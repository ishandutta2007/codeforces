#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector <vector <char>> c(n);
	for (int i = 0; i < n; i++)
		c[i].resize(m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> c[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (c[i][j] != 'W' && c[i][j] != 'B' && c[i][j] != ' ' && c[i][j] != 'G') {
				cout << "#Color" << endl;
				return 0;
			}
	cout << "#Black&White";
	return 0;
}