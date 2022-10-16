/*input
3 3 3 100
1 1 1
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, b;
	int mod;
	cin >> n >> m >> b >> mod;
	//n = b = m = 500, mod = 1000000007;
	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		//a[i] = i;
	}

	int din[m + 1][b + 1] = {}; // kiek eiluciu su kiek bugu

	din[0][0] = 1;

	for (int i = 0; i < n; i++) {
		int din2[m + 1][b + 1] = {};

		for (int k = 0; k <= b; k++) {

			for (int j = 0; j <= m; j++) {
				din2[j][k] += din[j][k];

				if (k - a[i] >= 0 and j - 1 >= 0)
					din2[j][k] += din2[j - 1][k - a[i]];

				din2[j][k] %= mod;
			}
		}

		for (int j = 0; j <= m; j++) {
			for (int k = 0; k <= b; k++)
				din[j][k] = din2[j][k];
		}
	}

	long long sum = 0;

	for (int i = 0; i <= b; i++) {
		sum += din[m][i];
		sum %= mod;
	}

	cout << sum;

	return 0;
}