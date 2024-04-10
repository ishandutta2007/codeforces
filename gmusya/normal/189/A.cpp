#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int INF = -100000;

int main() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	vector <int> ans(n + 1, INF);
	ans[0] = 0;
	for (int i = 1; i <= n; i++) {
		if (i - a >= 0)
			ans[i] = max(ans[i], ans[i - a] + 1);
		if (i - b >= 0)
			ans[i] = max(ans[i], ans[i - b] + 1);
		if (i - c >= 0)
			ans[i] = max(ans[i], ans[i - c] + 1);
	}
	cout << ans[n];
	return 0;
}