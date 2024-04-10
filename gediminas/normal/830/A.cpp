/*input
2 4 50
20 100
60 10 40 80
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n, k;
	long long p;
	cin >> n >> k >> p;

	long long ats = LONG_LONG_MAX;

	long long a[n], b[k];

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < k; i++)
		cin >> b[i];

	sort(a, a + n);
	sort(b, b + k);

	for (int i = 0; i + n - 1 < k; i++) {
		long long ma = 0;

		for (int j = 0; j < n; j++) {
			ma = max(ma, abs(a[j] - b[i + j]) + abs(b[i + j] - p));
		}
		ats = min(ats, ma);
	}

	cout << ats;


	return 0;
}