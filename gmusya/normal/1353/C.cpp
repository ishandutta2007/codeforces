#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <long long> a(n);
		for (int i = 1; i < (n + 1) / 2; i++)
			a[i] = a[i - 1] + 8;
		long long ans = 0;
		for (int i = 0; i < n; i++)
			ans += 1LL * i * a[i];
		cout << ans << '\n';
	}
	return 0;
}