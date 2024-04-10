/*input
6 2
5 5 6 8 3 12
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, r;
	cin >> n >> r;

	long long x[n];
	long double y[n];

	for (int i = 0; i < n; i++) {
		cin >> x[i];
		y[i] = r;

		for (int j = 0; j < i; j++) {
			long long dx = x[i] - x[j];

			if (4 * r * r - dx * dx >= 0)
				y[i] = max(y[i], y[j] + sqrtl(4 * r * r - dx * dx));
		}

		cout << fixed << setprecision(15) << y[i] << " ";
	}


	return 0;
}