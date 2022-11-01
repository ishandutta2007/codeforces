#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 0;
	for (int it = -30; it <= 30; it++) {
		vector <int> b = a;
		for (int i = 0; i < n; i++)
			if (b[i] > it)
				b[i] = -INF;
		int max_sum = -INF;
		int cur_sum = 0;
		for (int i = 0; i < n; i++) {
			cur_sum += b[i];
			max_sum = max(cur_sum, max_sum);
			cur_sum = max(0, cur_sum);
		}
		ans = max(max_sum - it, ans);
	}
	cout << ans;
	return 0;
}