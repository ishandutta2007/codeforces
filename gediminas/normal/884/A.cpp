/*input
2 86400
0 86400
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, t;
	cin >> n >> t;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		t -= 86400 - x;

		if (t <= 0) {
			cout << i + 1;
			return 0;
		}
	}

	return 0;
}