/*input
2 4
*/
/*output
YES
5 4 7 2
3 6 1 8
*/
/*input
2 1
*/
/*output
NO
*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> rotate(int n, int m, vector<vector<int>> arr)
{
	vector<vector<int>> rot_arr(m, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			rot_arr[m - 1 - j][i] = arr[i][j];
	}

	return rot_arr;
}

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	bool rot = false;

	if (n > m) {
		swap(n, m);
		rot = true;
	}

	vector<vector<int>>mat(n, vector<int>(m));

	if (n == 1 and m == 1) {
		mat[0] = {1};
	}
	else if (n == 1 and m == 2) {
		cout << "NO\n";
		exit(0);
	}
	else if (n == 1 and m == 3) {
		cout << "NO\n";
		exit(0);
	}
	else if (n == 1 and m == 4) {
		mat[0] = {3, 1, 4, 2};
	}
	else if (n == 1) {
		mat[0].resize(0);
		for (int i = 1; i <= m; i++) {
			if (i % 2 == 1)
				mat[0].push_back(i);
		}

		for (int i = 1; i <= m; i++) {
			if (i % 2 == 0)
				mat[0].push_back(i);
		}
	}
	else if (n == 2 and m == 2) {
		cout << "NO\n";
		return 0;
	}
	else if (n == 2 and m == 3) {
		cout << "NO\n";
		return 0;
	}
	else if (n == 3 and m == 3) {
		mat[0] = {6, 1, 8};
		mat[1] = {7, 5, 3};
		mat[2] = {2, 9, 4};
	}
	else {
		if (!rot) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++)
					mat[i][j] = i * m + j + 1;
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++)
					mat[i][j] = i + j * n + 1;
			}
		}

		vector<vector<int>> old = mat;

		for (int i = 0; i < n; i += 2) {
			for (int j = 0; j < m; j++)
				mat[i][j] = old[i][(j + 2) % m];
		}

		old = mat;

		for (int j = 0; j < m; j += 2) {
			for (int i = 0; i < n; i++)
				mat[i][j] = old[(i + 1) % n][j];
		}
	}

	if (rot) {
		mat = rotate(n, m, mat);
		swap(n, m);
	}

	cout << "YES\n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << mat[i][j] << " ";

		cout << "\n";
	}


	return 0;
}