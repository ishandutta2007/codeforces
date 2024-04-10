#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll s;
		cin >> s;
		ll cnt = 0;
		while (s > 0) {
			ll x = s / 10;
			if (x == 0) {
				cnt += s;
				break;
			}
			cnt += x * 10;
			s -= 9 * x;
		}
		cout << cnt << endl;
	}
	return 0;
}