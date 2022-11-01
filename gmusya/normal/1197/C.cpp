#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector <int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector <int> b(n - 1);
	for (int i = 0; i < n - 1; i++) b[i] = a[i + 1] - a[i];
	sort(b.begin(), b.end());
	int sum = 0;
	for (int i = 0; i < n - k; i++) sum += b[i];
	cout << sum << endl;
	return 0;
}