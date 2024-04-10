#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	long long int n, k;
	cin >> n >> k;
	vector <long long int> a(n);
	for (long long int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	long long int ans = a[(n - 1) / 2];
	long long int i = (n - 1) / 2;
	long long int numbers = 1;
	while (i < n) {
		if (i != n - 1) {
			long long int raz = a[i + 1] - ans;
			if (k >= numbers * raz) {
				ans += raz;
				k -= numbers * raz;
				numbers++;
			}
			else {
				ans += (k / numbers);
				cout << ans;
				return 0;
			}
		}
		if (i == n - 1) {
			ans += (k / numbers);
			cout << ans;
			return 0;
		}
		i++;
	}

	return 0;
}