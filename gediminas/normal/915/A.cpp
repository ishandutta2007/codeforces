/*input
6 7
1 2 3 4 5 6
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	long long ats = k;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		if (k % x == 0 and k / x < ats)
			ats = k / x;
	}

	cout << ats;


	return 0;
}