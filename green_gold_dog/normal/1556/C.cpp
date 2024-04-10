#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1'000'000'000'000'000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	ll ans = 0;
	for (ll i = 1; i < n; i += 2) {
		ll sum = 0, s = -arr[i];
		ll now = arr[i], last = i - 1;
		for (ll j = i - 1; j >= 0; j -= 2) {
			sum += arr[j];
			s += arr[j + 1];
			if (sum >= s) {
				ll b = min(sum, s);
				sum -= b;
				s -= b;
				b = min(now, sum);
				now -= b;
				sum -= b;
				ans += b;
				if (j != i - 1) {
					ans++;
				}
				if (sum > 0) {
					break;
				}
			}
		}
	}
	cout << ans;
}

/*
















*/