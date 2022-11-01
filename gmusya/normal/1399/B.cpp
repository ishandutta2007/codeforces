#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n), b(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		int mia = 1e9, mib = 1e9;
		for (int i = 0; i < n; i++) {
			if (a[i] < mia) mia = a[i];
			if (b[i] < mib) mib = b[i];
		}
		ll ans = 0;
		for (int i = 0; i < n; i++)
			ans += max(a[i] - mia, b[i] - mib);
		cout << ans << '\n';
	}
	return 0;
}