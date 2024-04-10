#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		vector <vector <char>> a(9, vector <char>(9));
		int n = 9;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				if (a[i][j] == '9') a[i][j] = '1';
			}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << a[i][j];
			cout << endl;
		}
	}
	return 0;
}