#include <iostream>
#include <vector>

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
		int cnt0 = 0, cnt1 = 0;
		for (int i = 0; i < n; i++) {
			if (b[i] == 0) cnt0++;
			else cnt1++;
		}
		if (cnt0 && cnt1) {
			cout << "Yes\n";
			continue;
		}
		bool tf = true;
		for (int i = 0; i < n - 1; i++)
			if (a[i] > a[i + 1])
				tf = false;
		if (tf) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}