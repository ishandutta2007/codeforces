#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector <int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int cnt0 = 0, cnt1 = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] % 2 == 0) cnt0++;
			else cnt1++;
		}
		bool tf = false;
		for (int odd = 1; odd <= cnt1; odd += 2) {
			int even = k - odd;
			if (even < 0) continue;
			if (even <= cnt0 && odd <= cnt1)
				tf = true;
		}
		if (tf) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}