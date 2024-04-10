/*input
6
2 2 2 2 2 2
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	long long a[n];
	long long sum = 0, s = 0;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	for (int i = 0; i < n; i++) {
		s += a[i];

		if (2 * s >= sum) {
			cout << i + 1;
			exit(0);
		}
	}


	return 0;
}