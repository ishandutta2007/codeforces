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
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int cnt0 = 0, cnt1 = 0;
		for (int i = 0; i < n; i += 2) 
			if (a[i] % 2) cnt0++;
		for (int i = 1; i < n; i += 2)
			if (a[i] % 2 == 0) cnt1++;
		if (cnt0 == cnt1) cout << cnt0 << '\n';
		else cout << -1 << '\n';
	}
	return 0;
}