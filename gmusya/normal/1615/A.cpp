#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		long long sum = 0;
		for (int x : a) {
			sum += x;
		}
		if (sum % n == 0) {
			cout << 0 << '\n';
		} else {
			cout << 1 << '\n';
		}
	}
	return 0;
}