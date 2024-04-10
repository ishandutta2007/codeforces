#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

ll gcd(ll a, ll b) {
	if (min(a, b) == 0) return max(a, b);
	if (a % b) return gcd(b, a % b);
	return b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		ll m, d, w;
		cin >> m >> d >> w;
		ll k = min(m, d);
		w /= gcd(w, d - 1);
		ll ans = 0;
		ll modulo = k % w;
		ll hm = k / w;
		ans = (hm * (hm - 1) / 2) * (w - modulo) + ((hm + 1) * hm / 2) * (modulo);
		cout << ans << '\n';
	}
	return 0;
}