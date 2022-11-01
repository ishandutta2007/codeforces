#include <iostream>
#include <vector>

using namespace std;

int main() {
	int r, c;
	cin >> r >> c;
	bool tf = false;
	vector <vector <int>> a(r + 1);
	if (r == 1 && c == 1) {
		cout << 0 << endl;
		return 0;
	}
	if (r > c) {
		swap(r, c);
		tf = true;
	}
	for (int i = 0; i <= r; i++)
		a[i].resize(c + 1);
	for (int i = 1; i <= r; i++)
		a[i][1] = 2 * i;
	for (int i = 2; i <= c; i++)
		if (i <= r + 1)
			a[1][i] = a[i - 1][1] + 1;
		else
			a[1][i] = a[1][i - 1] + 1;
	for (int i = 2; i <= r; i++)
		for (int j = 2; j <= c; j++)
			a[i][j] = a[1][j] * a[i][1];
	if (!tf)
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++)
				cout << a[i][j] << " ";
			cout << endl;
		}
	if (tf)
		for (int j = 1; j <= c; j++) {
			for (int i = 1; i <= r; i++)
				cout << a[i][j] << " ";
			cout << endl;
		}
	return 0;
}