/*input
4
82 94 6
56 67 4
28 59 9
39 74 4
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int val[1000001];

	for (int i = 1; i <= 1000000; i++) {
		if (i < 10)
			val[i] = i;
		else {
			int j = 1;
			int x = i;

			while (x > 0) {
				if (x % 10 != 0) {
					j *= x % 10;
				}

				x /= 10;
			}

			val[i] = val[j];
		}
	}

	int din[1000001][10] = {};

	for (int i = 1; i <= 1000000; i++) {
		for (int j = 0; j < 10; j++) {
			din[i][j] = din[i - 1][j];
		}

		din[i][val[i]]++;
	}

	int q;
	cin >> q;

	for (int i = 0; i < q; i++) {
		int l, r, x;
		cin >> l >> r >> x;
		cout << din[r][x] - din[l - 1][x] << "\n";
	}


	return 0;
}