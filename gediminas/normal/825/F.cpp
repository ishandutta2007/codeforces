/*input
aaaaaaaaaa
abcab
cczabababab
cbbbcccbbc


*/
#include <bits/stdc++.h>

using namespace std;

int ilgis(int x) {
	assert(x > 0);

	if (x < 10)
		return 1;

	else if (x < 100)
		return 2;

	else if (x < 1000)
		return 3;

	else if (x < 10000)
		return 4;

	exit(1);
}

int main () {
	string s;

	while (cin >> s) {
		const int n = s.size();
		int d[n + 1] = {};
		vector<vector<int>> len(n, vector<int>(n));

		for (int i = 1; i <= n; i++)
			d[i] = i + 1;

		for (int j = 0; j < n; j++) {
			int k = j;

			for (int i = 0; i < n; i++)
				len[j][i] = j;

			for (int i = j + 1; i < n; i++) {
				while (k > j and s[k] != s[i])
					k = len[j][k - 1];

				if (s[k] == s[i])
					len[j][i] = ++k;
			}
		}

		/*for (int j = 0; j < n; j++) {
			for (int i = 0; i < n; i++)
				cout << len[j][i] << " ";

			cout << endl;
		}*/

		for (int j = 1; j <= n; j++) {
			for (int i = 0; i < j; i++) {
				int ilg = j - len[i][j - 1];

				if ((j - i) % ilg == 0) {
					//cout << i << " " << j << " " << ilg << endl;
					d[j] = min(d[j], d[i] + ilg + ilgis((j - i) / ilg));
				}

				d[j] = min(d[j], d[i] + j - i + 1);
			}
		}

		/*for(int i = 0; i <= n; i++) {
			cout << d[i] << " ";
		}*/
		cout << d[n] << endl;
		//return 0;
	}

	return 0;

}