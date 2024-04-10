#include <iostream>
#include <vector>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <vector <char>> c(n);
	for (int i = 0; i < n; i++)
		c[i].resize(5);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 5; j++)
			cin >> c[i][j];
	bool tf = false;
	for (int i = 0; i < n; i++) {
		if (c[i][0] == 'O' && c[i][1] == 'O') {
			c[i][0] = '+';
			c[i][1] = '+';
			tf = true;
			break;
		}
		if (c[i][3] == 'O' && c[i][4] == 'O') {
			c[i][3] = '+';
			c[i][4] = '+';
			tf = true;
			break;
		}
	}
	if (!tf) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++)
			cout << c[i][j];
		cout << endl;
	}
	return 0;
}