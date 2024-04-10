#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

ll gcd(ll a, ll b) {
	if (a % b) return gcd(b, a % b);
	return b;
}

ll solve(ll a, ll b, ll nok, ll X) {
	ll times = X / nok;
	ll ans = times * (nok - b);
	ll modulo = X % nok;
	ans += max(0LL, modulo - b);
	return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);
		ll g = gcd(a, b);
		int q;
		cin >> q;
		while (q--) {
			ll L, R;
			cin >> L >> R;
			L--;
			ll cntL = solve(a, b, a * b / g, L);
			if (L % (a * b / g) >= b) cntL++;
			ll cntR = solve(a, b, a * b / g, R);
			if (R % (a * b / g) >= b) cntR++;
			cout << cntR - cntL << ' ';
		}
		cout << '\n';
	}
	return 0;
}