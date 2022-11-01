#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	vector <int> prefix_sum(n);
	prefix_sum[0] = a[0];
	for (int i = 1; i < n; i++)
		prefix_sum[i] = prefix_sum[i - 1] + a[i];
	int i;
	for (i = n - 1; i > 0 && prefix_sum[i - 1] >= prefix_sum[n - 1] - prefix_sum[i - 1]; i--);
	if (n == 2 && a[0] == a[1])
		cout << 2;
	else
		cout << n - i;
	return 0;
}