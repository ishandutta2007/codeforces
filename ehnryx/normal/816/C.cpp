#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int grid[n][m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> grid[i][j];
	int temp;
	int row[n], col[m];
	if (m > n) {
		for (row[0] = 500; row[0] >= 0; row[0]--) {
			for (int j = 0; j < m; j++) {
				col[j] = grid[0][j] - row[0];
				if (col[j] < 0) goto next;
			}
			for (int i = 1; i < n; i++) {
				row[i] = grid[i][0] - col[0];
				if (row[i] < 0) goto next;
			}
			for (int i = 1; i < n; i++) {
				for (int j = 1; j < m; j++) {
					temp = grid[i][j] - col[j];
					if (temp != row[i]) goto next;
				}
			}
			goto done;
			next:
			continue;
		}
	}
	else {
		for (col[0] = 500; col[0] >= 0; col[0]--) {
			for (int j = 0; j < n; j++) {
				row[j] = grid[j][0] - col[0];
				if (row[j] < 0) goto next2;
			}
			for (int i = 1; i < m; i++) {
				col[i] = grid[0][i] - row[0];
				if (col[i] < 0) goto next2;
			}
			for (int i = 1; i < m; i++) {
				for (int j = 1; j < n; j++) {
					temp = grid[j][i] - row[j];
					if (temp != col[i]) goto next2;
				}
			}
			goto done;
			next2:
			continue;
		}
	}
	cout << -1 << endl;
	return 0;
	done:
	int sum = 0;
	for (int i = 0; i < n; i++) 
		sum += row[i];
	for (int j = 0; j < m; j++)
		sum += col[j];
	cout << sum << endl;
	for (int i = 0; i < n; i++) {
		while (row[i]--) cout << "row " << i+1 << endl;
	}
	for (int j = 0; j < m; j++) {
		while (col[j]--) cout << "col " << j+1 << endl;
	}
	return 0;
}