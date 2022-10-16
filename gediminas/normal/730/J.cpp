/*input
10
18 42 5 1 26 8 40 34 8 29
18 71 21 67 38 13 99 37 47 76
*/
#include <bits/stdc++.h>

using namespace std;

int din[100][100][10001];

int main () {
	int n;
	cin >> n;
	pair<int, int> bot[n];

	for (int i = 0; i < n; i++)
		cin >> bot[i].second;

	for (int i = 0; i < n; i++)
		cin >> bot[i].first;

	sort(bot, bot + n, [](const auto & i, const auto & j) -> bool {
		return i > j;
	});

	int sum = 0;

	for (int i = 0; i < n; i++)
		sum += bot[i].second;

	int k = 0;
	int gali = 0;

	while (sum > gali)
		gali += bot[k++].first;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			for (int l = 0; l <= k * 100; l++)
				din[i][j][l] = -2 * sum;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			for (int l = 0; l <= k * 100; l++)
				din[i][j][l] = max(din[i][j][l], (i == 0 ? (j == 0 and l == 0 ? 0 : -2 * sum) : din[i - 1][j][l]));
		}

		for (int j = 0; j < k and j <= i; j++) {
			for (int l = 0; l + bot[i].first <= k * 100; l++)
				din[i][j][l + bot[i].first] = max(din[i][j][l + bot[i].first], (i == 0 or j == 0 ? (j == 0 and l == 0 ? 0 : -2 * sum) : din[i - 1][j - 1][l]) + bot[i].second);
		}
	}

	int ats = 0;

	for (int i = sum; i <= k * 100; i++)
		ats = max(ats, din[n - 1][k - 1][i]);

	cout << k << " " << sum - ats << endl;

	return 0;
}