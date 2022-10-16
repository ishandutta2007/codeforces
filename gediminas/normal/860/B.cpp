/*input
4
123456789
193456789
134567819
934567891
*/
#include <bits/stdc++.h>

using namespace std;

std::string fixedLength(int value, int digits) {
	unsigned int uvalue = value;

	if (value < 0)
		uvalue = -uvalue;

	std::string result;

	while (digits-- > 0) {
		result += ('0' + uvalue % 10);
		uvalue /= 10;
	}

	if (value < 0)
		result += '-';

	std::reverse(result.begin(), result.end());
	return result;
}

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;

	map<int, int> x[10];
	map<int, int> y[10][n];

	long long des[11] = {1};

	for (int i = 1; i <= 10; i++)
		des[i] = des[i - 1] * 10;

	for (int kk = 0; kk < n; kk++) {
		int sk;
		cin >> sk;

		for (int i = 0; i < 10; i++) {
			for (int j = 1; j + i < 10; j++) {
				int skk = (sk / des[i]) % des[j];
				x[j][skk]++;
				y[j][kk][skk]++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 1; j < 10; j++) {
			for (auto && xx : y[j][i]) {
				if (xx.second == x[j][xx.first]) {
					cout << fixedLength(xx.first, j) << endl;
					j = 10;
					break;
				}
			}
		}
	}

	return 0;
}