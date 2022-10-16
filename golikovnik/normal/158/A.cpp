#include <iostream>

using namespace std;

int  main() {
	int n, k;
	cin >> n >> k;
	int ans = 0;
	bool isPassed = false;
	int k_points = -1;
	for (int i = 0; i < n; i++) {
		int points;
		cin >> points;

		if (points <= 0)
			continue;
		if ((isPassed) && (points != k_points)) {
			break;
		}
		else if (isPassed) {
			ans++;
		}
		else if (i == k-1) {
			isPassed = true;
			k_points = points;
			ans++;
		}
		else {
			ans++;
		}
	}
	cout << ans;
	return 0;
}