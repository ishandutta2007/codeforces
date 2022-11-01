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
		int ans = 0;
		int min = a[n - 1];
		for (int i = n - 1; i >= 0; i--)
			if (a[i] <= min) {
				min = a[i];
				ans++;
			}
		cout << n - ans << endl;
	}
	return 0;
}