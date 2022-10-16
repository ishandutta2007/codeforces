/*input
100 5
4 4 3 2 4 4 1 2 2 1 5 3 2 5 5 3 2 3 4 5 2 2 3 4 2 4 3 1 2 3 5 5 1 3 3 5 2 3 3 4 1 3 1 5 4 4 2 1 5 1 4 4 1 5 1 1 5 5 5 4 1 3 1 2 3 2 4 5 5 1 3 4 3 3 1 2 2 4 1 5 1 1 2 4 4 4 5 5 5 3 4 3 3 3 3 2 1 1 5 5
*/
#include <bits/stdc++.h>

using namespace std;

int m = 0;

bool palyg(long long kiek[], long long kiek2[]) {
	for (int i = 0; i < m; i++) {
		if (kiek[i] > kiek2[i])
			return false;
	}

	return true;
}


int main () {
	ios_base::sync_with_stdio(false), cin.tie(0);
	long long n, k;
	cin >> n >> k;
	long long pirm[40], kiek[40];

	long long dal = 2;

	while (k > 1 and dal * dal <= k) {
		if (k % dal == 0) {
			if (m > 0 and pirm[m - 1] == dal)
				kiek[m - 1]++;
			else {
				pirm[m] = dal;
				kiek[m] = 1;
				m++;
			}

			k /= dal;
		}
		else
			dal++;

	}

	if (k > 1) {
		if (m > 0 and pirm[m - 1] == k)
			kiek[m - 1]++;
		else {
			pirm[m] = k;
			kiek[m] = 1;
			m++;
		}
	}

	assert(m <= 40);

	long long kiek2[n][40] = {};

	for (int i = 0; i < n; i++) {
		long long sk;
		cin >> sk;
		for (int j = 0; j < m; j++) {
			while (sk > 1 and sk % pirm[j] == 0) {
				kiek2[i][j]++;

				sk /= pirm[j];
			}
		}
	}

	long long temp[40] = {};
	int pra = 0;
	long long ats = 0;
	int pab = 0;

	while (pra < n) {
		while ((!palyg(kiek, temp) or pra == pab) and pab < n) {
			for (int j = 0; j < m; j++)
				temp[j] += kiek2[pab][j];

			pab++;
		}

		if (!palyg(kiek, temp))
			break;

		ats += n - pab + 1;

		for (int j = 0; j < m; j++)
			temp[j] -= kiek2[pra][j];

		pra++;
	}

	cout << ats;

	return 0;
}