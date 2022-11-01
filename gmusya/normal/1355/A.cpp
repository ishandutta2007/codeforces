#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;
		k--;
		while (k) {
			ll mind = 9;
			ll maxd = 0;
			ll copy_n = n;
			while (copy_n) {
				mind = min(mind, copy_n % 10);
				maxd = max(maxd, copy_n % 10);
				copy_n /= 10;
			}
			if (mind == 0) break;
			k--;
			n += mind * maxd;
		}
		cout << n << '\n';
	}
	return 0;
}