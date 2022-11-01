#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, t, c;
	cin >> n >> t >> c;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int cnt = 0;
	int ans = 0;
	for (int i = 0; i < c; i++)
		if (a[i] > t)
			cnt++;
	if (cnt == 0)
		ans++;
	for (int i = c; i < n; i++) {
		if (a[i - c] > t)
			cnt--;
		if (a[i] > t)
			cnt++;
		if (cnt == 0)
			ans++;
	}
	cout << ans;
	return 0;
}