#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	if (n == 1 || n == 2) {
		cout << -1;
		return 0;
	}
	// 176
	// 235
	// 948
	vector <vector <int>> a(n, vector <int>(n));
	a[0][0] = 10 - 1;
	a[0][1] = 10 - 7;
	a[0][2] = 10 - 6;
	a[1][0] = 10 - 2;
	a[1][1] = 10 - 3;
	a[1][2] = 10 - 5;
	a[2][0] = 10 - 9;
	a[2][1] = 10 - 4;
	a[2][2] = 10 - 8;
	int cnt = 10;
	for (int i = 3; i < n; i++)
		a[i][0] = cnt++;
	for (int i = n - 1; i >= 3; i--)
		a[i][1] = cnt++;
	for (int i = 3; i < n; i++)
		a[i][2] = cnt++;
	for (int j = 3; j < n; j++) {
		if (j % 2)
			for (int i = n - 1; i >= 0; i--)
				a[i][j] = cnt++;
		else
			for (int i = 0; i <= n - 1; i++)
				a[i][j] = cnt++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << n * n + 1 - a[i][j] << " ";
		cout << endl;
	}
	return 0;
}