#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
	int q;
	cin >> q;
	while (q--) {
		ll n;
		cin >> n;
		int cnt = 0;
		while (n > 1) {
			ll L = 1;
			ll R = 1e9;
			while (L != R) {
				ll M = (L + R + 1) / 2;
				ll C = M * (M + 1) / 2 * 3 - M;
				if (C > n) R = M - 1;
				else L = M;
			}
			ll C = L * (L + 1) / 2 * 3 - L;
			n -= C;
			cnt++;
		}
		cout << cnt << '\n';
	}
}