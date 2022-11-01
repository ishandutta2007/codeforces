#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll f(ll n) {
	ll ans = 0;
	while (n) {
		ans += n % 10;
		n /= 10;
	}
	return ans;
}

void update(ll &ans, ll &newans) {
	if (ans == -1 || ans > newans) ans = newans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll ans = -1;
		int n, k;
		cin >> n >> k;
		for (int last_digit = 0; last_digit <= 9; last_digit++) {
			for (int nines = 0; nines <= 17; nines++) {
				ll num = 0;
				for (int i = 0; i < nines; i++) {
					num *= 10;
					num += 9;
				}
				num *= 10;
				num += last_digit;
				ll s = 0;
				for (int i = 0; i <= k; i++)
					s += f(num + i);
				// n = s + d(k + 1)
				if (n - s < 0 || (n - s) % (k + 1)) continue;
				ll d = (n - s) / (k + 1);
				ll x = 10;
				while (x <= num) x *= 10;
				if (d < 9) {
					ll newans = num + x * d;
					update(ans, newans);
					continue;
				}
				ll tmp = x * 8;
				x *= 10;
				d -= 8;
				ll val = d % 9;
				for (int i = 0; i < d / 9; i++) {
					val *= 10;
					val += 9;
				}
				ll newans = num + x * val + tmp;
				//cout << num << ' ' << tmp << ' ' << x << ' ' << val << ' ' << newans << '\n';
				update(ans, newans);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}