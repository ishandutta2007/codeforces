#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

#define dl double long

using namespace std;

int main() {
	int n;
	dl x;
	cin >> n >> x;
	vector <dl> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	dl ans = max(a[0], x - a[n - 1]);
	for (int i = 0; i < n - 1; i++)
		ans = max(ans, (a[i + 1] - a[i]) / 2);
	cout << fixed << setprecision(15) << ans;
	return 0;
}