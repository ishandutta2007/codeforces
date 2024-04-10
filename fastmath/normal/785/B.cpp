#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <string>

using namespace std;

int main() {
	int x, y;
	int n, m;
	cin >> n;

	int r1 = pow(10, 9), l1 = 0;
	int r2 = pow(10, 9), l2 = 0;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;

		l1 = max(l1, x);
		r1 = min(r1, y);
	}

	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y;

		l2 = max(l2, x);
		r2 = min(r2, y);
	}

	int ans = 0;
	ans = max(ans, l1 - r2);
	ans = max(ans, l2 - r1);

	cout << ans;
	return 0;
}