#include <iostream>
#include <vector>

#define ll long long

using namespace std;
vector <ll> third_power(39);

int main() {
	ll q;
	cin >> q;
	third_power[0] = 1;
	for (ll i = 1; i < 39; i++)
		third_power[i] = 3 * third_power[i - 1];
	while (q--) {
		ll n;
		cin >> n;
		ll copy_n = n;
		vector <ll> razlozh(39);
		for (ll i = 38; i >= 0; i--) {
			razlozh[i] = copy_n / third_power[i];
			copy_n = copy_n % third_power[i];
		}
		bool tf = true;
		int uk = 0;
		for (ll i = 0; i < 39; i++) {
			if (razlozh[i] >= 2) {
				razlozh[i] = 0;
				razlozh[i + 1]++;
				uk = i;
				tf = false;
			}
		}
		if (tf)
			cout << n << endl;
		else {
			ll ans = 0;
			for (int i = 38; i >= uk; i--)
				ans += razlozh[i] * third_power[i];
			cout << ans << endl;
		}
	}
	return 0;
}