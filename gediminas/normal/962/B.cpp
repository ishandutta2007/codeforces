/*input
5 3 0
*...*

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, a, b;
	cin >> n >> a >> b;
	int kiek = a + b;
	int tarp = 0;

	if (a > b)
		swap(a, b);

	for (int i = 0; i < n; i++) {
		char x;
		cin >> x;

		if (x == '.')
			tarp++;

		if (x == '*' or i == n - 1) {
			if (tarp == 0 or a + b == 0)
				continue;

			if (tarp <= min(a + b, 2 * a + 1)) {
				a -= tarp / 2;
				b -= tarp - tarp / 2;
			}
			else {
				tarp -= min(a + b, 2 * a + 1);
				b -= min(a + b, 2 * a + 1) - a;
				a = 0;

				b -= tarp / 2;
				b = max(b, 0);
			}

			if (a > b)
				swap(a, b);

			tarp = 0;
		}
	}

	a = max(a, 0);
	b = max(b, 0);
	cout << kiek - a - b << endl;

	return 0;
}