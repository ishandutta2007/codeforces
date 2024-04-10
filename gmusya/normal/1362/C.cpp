#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		ll ans = 0;
		while (n) {
			ans += n;
			n /= 2;
		}
		cout << ans << '\n';
	}
	return 0;
}