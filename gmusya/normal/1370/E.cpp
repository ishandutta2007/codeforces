#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <char> a(n), b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	vector <int> arr(n);
	int x = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > b[i]) arr[i] = 1;
		if (a[i] < b[i]) arr[i] = -1;
		x += arr[i];
	}
	if (x) {
		cout << -1;
		return 0;
	}
	int ans = 0;
	{
		int cur_sum = 0;
		for (int i = 0; i < n; i++) {
			cur_sum += arr[i];
			ans = max(ans, cur_sum);
			cur_sum = max(0, cur_sum);
		}
	}
	{
		int cur_sum = 0;
		for (int i = 0; i < n; i++) {
			cur_sum -= arr[i];
			ans = max(ans, cur_sum);
			cur_sum = max(0, cur_sum);
		}
	}
	cout << ans;
	return 0;
}