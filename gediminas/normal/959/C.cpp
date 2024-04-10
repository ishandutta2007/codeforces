/*input
8

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;

	if (n <= 5) {
		cout << "-1\n";
	}
	else {
		cout << "1 2\n";
		cout << "2 3\n";
		cout << "2 4\n";

		for (int i = 5; i <= n; i++) {
			cout << i << " 1\n";
		}
	}

	for (int i = 2; i <= n; i++) {
		cout << i - 1 << " " << i << "\n";
	}


	return 0;
}