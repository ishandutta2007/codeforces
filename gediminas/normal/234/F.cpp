/*input
3
3 3
2 2 2
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
#ifndef LOCAL
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif

	int n, a, b;
	cin >> n >> a >> b;

	int tvor[n];
	int sum[n + 1] = {};

	for (int i = 0; i < n; i++) {
		cin >> tvor[i];
		sum[i + 1] = sum[i] + tvor[i];
	}

	int din[n + 1][a + 1][2];
	const int inf = 10000000;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= a; j++)
			din[i][j][0] = din[i][j][1] = inf;
	}

	din[0][a][0] = din[0][a][1] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = a; j - tvor[i - 1] >= 0; j--)
			din[i][j - tvor[i - 1]][0] = min(din[i - 1][j][0], din[i - 1][j][1] + min(tvor[i - 1], (i >= 2 ? tvor[i - 2] : inf)));

		for (int j = 0; b - sum[i] + a - j >= 0 and j <= a; j++)
			din[i][j][1] = min(din[i - 1][j][1], din[i - 1][j][0] + min(tvor[i - 1], (i >= 2 ? tvor[i - 2] : inf)));

		/*for (int j = 0; j <= a; j++)
			cout << din[i][j][0] << " " << din[i][j][1] << endl;

		cout << endl;*/
	}

	int ats = inf;

	for (int i = 0; i <= a; i++) {
		for (int j = 0; j < 2; j++)
			ats = min(ats, din[n][i][j]);
	}

	cout << (ats < inf ? ats : -1);

	return 0;
}