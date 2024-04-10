#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {
		int n, m;
		cin >> n >> m;
		vector <int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		if (n <= 2)
			cout << "-1" << endl;
		int ans = 0;
		if (n > 2) {
			if (m < n)
				cout << "-1" << endl;
			if (m >= n) {
				for (int i = 1; i < n; i++)
					ans += a[i - 1] + a[i];
				ans += a[0] + a[n - 1];
				int min1 = 100000, min2 = 100000, min_id1 = 100000, min_id2 = 100000;
				for (int i = 0; i < n; i++) {
					int x = a[i];
					if (x <= min1) {
						min2 = min1;
						min1 = x;
						min_id2 = min_id1;
						min_id1 = i;
					}
					else
						if (x < min2) {
							min2 = x;
							min_id2 = i;
						}
				}
				for (int i = n; i < m; i++)
					ans += a[min_id1] + a[min_id2];
				cout << ans << endl;
				for (int i = 1; i < n; i++)
					cout << i << " " << i + 1 << endl;
				cout << 1 << " " << n << endl;
				for (int i = n; i < m; i++)
					cout << min_id1 + 1 << " " << min_id2 + 1 << endl;
			}
		}
	}
	return 0;
}