/*input
bab

*/
#include <bits/stdc++.h>

using namespace std;

int sum[2][5000 + 1] = {};

int main () {
	string x;
	cin >> x;

	for (int i = 0; i < x.size(); i++) {
		sum[0][i + 1] = sum[0][i];
		sum[1][i + 1] = sum[1][i];

		if (x[i] == 'a')
			sum[0][i + 1]++;
		else
			sum[1][i + 1]++;
	}

	int ats = 0;

	for (int i = 0; i <= x.size(); i++) {
		for (int j = i; j <= x.size(); j++)
			ats = max(ats, sum[0][i] + sum[1][j] - sum[1][i] + sum[0][x.size()] - sum[0][j]);
	}

	cout << ats;

	return 0;
}