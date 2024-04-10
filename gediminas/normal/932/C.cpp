/*input
9 2 5
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, a, b;
	cin >> n >> a >> b;

	for (int i = 0; i * a <= n; i++) {
		if ((n - i * a) % b == 0) {
			int j = (n - i * a) / b;
			int pan = 0;

			for (int k = 0; k < i; k++) {
				vector<int> dab;

				for (int l = 0; l < a; l++) {
					dab.push_back(++pan);
				}

				for (int l = 0; l < a; l++) {
					cout << dab[(l + 1) % a] << " ";
				}
			}

			for (int k = 0; k < j; k++) {
				vector<int> dab;

				for (int l = 0; l < b; l++) {
					dab.push_back(++pan);
				}

				for (int l = 0; l < b; l++) {
					cout << dab[(l + 1) % b] << " ";
				}
			}

			return 0;
		}
	}

	cout << -1;
	return 0;
}