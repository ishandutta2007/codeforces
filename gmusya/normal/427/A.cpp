#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int cnt = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		if (cnt == 0 && a[i] < 0) {
			ans++;
			continue;
		}
		if (a[i] >= 0)
			cnt += a[i];
		else
			cnt--;
	}
	cout << ans;
	return 0;
}