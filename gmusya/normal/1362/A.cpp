#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll a, b;
		cin >> a >> b;
		if (a < b) swap(a, b);
		if (a % b) {
			cout << "-1\n";
			continue;
		}
		ll k = a / b;
		ll cnt = 0;
		while (k % 2 == 0) {
			k /= 2;
			cnt++;
		}
		if (k - 1) {
			cout << "-1\n";
			continue;
		}
		cout << (cnt + 2) / 3 << '\n';
	}
	return 0;
}