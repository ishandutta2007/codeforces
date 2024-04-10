#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <pair <int, int>> a(n - 1);
	for (int i = 0; i < n - 1; i++)
		cin >> a[i].first >> a[i].second;
	vector <int> c(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	vector <int> b(10e5 + 1);
	for (int i = 0; i < n - 1; i++) {
		if (c[a[i].first] != c[a[i].second]) {
			b[a[i].first]++;
			b[a[i].second]++;
		}
	}
	int cnt = 0;
	int ma = 1;
	for (int i = 1; i <= 10e5; i++) {
		if (b[i] > b[ma])
			ma = i;
		if (b[i] > 1)
			cnt++;
	}
	int sum = 0;
	for (int i = 1; i <= 10e5; i++)
		sum += b[i];
	if (cnt < 2 && sum == 2 * b[ma])
		cout << "YES" << endl << ma;
	else
		cout << "NO";
	return 0;
}