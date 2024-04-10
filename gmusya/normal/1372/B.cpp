#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ans = n;
		for (int i = 2; i * i <= n; i++)
			if (n % i == 0) {
				ans = i;
				break;
			}
		int x = n / ans;
		cout << x << ' ' << n - x << '\n';
	}
	return 0;
}