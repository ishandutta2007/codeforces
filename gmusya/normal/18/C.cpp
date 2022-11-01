#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i];
	int ans = 0;
	int cur_sum = 0;
	for (int i = 0; i < n - 1; i++) {
		cur_sum += a[i];
		if (2 * cur_sum == sum)
			ans++;
	}
	cout << ans;
	return 0;
}