#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			a[i]--;
		}
		int cnt = 0;
		for (int i = 0; i < n; i++)
			cnt += (a[i] == i);
		if (cnt == n) {
			cout << 0 << '\n';
			continue;
		}
		if (!cnt) {
			cout << 1 << '\n';
			continue;
		}
		int l = 0;
		int r = n - 1;
		while (a[l] == l) l++;
		while (a[r] == r) r--;
		if (r - l + 1 == n - cnt) cout << 1 << '\n';
		else cout << 2 << '\n';
	}
	return 0;
}