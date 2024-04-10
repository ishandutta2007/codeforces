/*input
5 787787787
123456789 234567890 345678901 456789012 987654321
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	long long n, l;
	cin >> n >> l;
	long long c[30];

	for (int i = 0; i < n; i++)
		cin >> c[i];

	for (int i = 1; i < n; i++)
		c[i] = min(c[i], 2 * c[i - 1]);

	for (int i = n; i < 30; i++)
		c[i] = 2 * c[i - 1];

	long long ats = l * c[0];
	long long atstemp = 0;

	while (l > 0) {
		for (int i = 29; i >= 0; i--) {
			if ((1ll << i) > l)
				ats = min(ats, atstemp + c[i]);
			else if ((1ll << i) == l) {
				l -= (1ll << i);
				ats = min(ats, atstemp + c[i]);
				break;
			}
			else{
				l -= (1ll << i);
				atstemp += c[i];
				break;
			}
		}
	}

	cout << ats << endl;

	return 0;
}