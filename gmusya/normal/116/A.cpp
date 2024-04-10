#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <pair <int, int>> a(n);
	int ans = 0;
	int cur = 0;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		cur += y - x;
		ans = max(ans, cur);
	}
	cout << ans;
	return 0;
}