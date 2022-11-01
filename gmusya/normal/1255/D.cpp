#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {
		int r, c, k;
		cin >> r >> c >> k;
		vector <vector <char>> a(r);
		for (int i = 0; i < r; i++)
			a[i].resize(c);
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				cin >> a[i][j];
		int sumofr = 0;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				sumofr += (a[i][j] == 'R');

		vector <vector <int>> ans(r);
		for (int i = 0; i < r; i++)
			ans[i].resize(c);

		int col = 1;
		int count = 0;

		for (int i = 0; i < r; i++) {
			if (i % 2 == 0) 
				for (int j = 0; j < c; j++) {
					count += (a[i][j] == 'R');
					ans[i][j] = col;
					if (count == (sumofr / k) + 1 && col <= sumofr % k) {
						count = 0;
						col++;
					}
					if (count == (sumofr / k) && col > sumofr % k) {
						count = 0;
						col++;
					}
					if (col > k) 
						col = k;
				}
			if (i % 2 == 1)
				for (int j = c - 1; j >= 0; j--) {
					count += (a[i][j] == 'R');
					ans[i][j] = col;
					if (count == (sumofr / k) + 1 && col <= sumofr % k) {
						count = 0;
						col++;
					}
					if (count == (sumofr / k) && col > sumofr % k) {
						count = 0;
						col++;
					}
					if (col > k)
						col = k;
				}
		}

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				char c;
				if (ans[i][j] >= 1 && ans[i][j] <= 26)
					c = 'a' + ans[i][j] - 1;
				if (ans[i][j] >= 27 && ans[i][j] <= 52)
					c = 'A' + ans[i][j] - 27;
				if (ans[i][j] >= 53 && ans[i][j] <= 62)
					c = '0' + ans[i][j] - 53;
				cout << c;
			}
			cout << endl;
		}
	}
	return 0;
}