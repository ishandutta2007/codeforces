#include <bits/stdc++.h>
typedef long long ll;

const ll INF = 9'000'000'000'000'000'000;

template<typename T>
bool assign_max(T& a, T b) {
	if (b > a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_min(T& a, T b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t = 0;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		ll n;
		cin >> n;
		vector<ll> arr(n);
		ll ce = 0, cne = 0, num = 0, nn = 0;
		for (ll i = 0; i < n; i++) {
			cin >> arr[i];
			if (i != 0 && i != n - 1) {
				ce += arr[i] == 1;
				cne += arr[i] > 0;
				if (arr[i] > 0) {
					num = arr[i];
					nn = i;
				}
			}
		}
		ll ans = 0;
		if ((cne == 1 && (num % 2 == 1)) || (cne == ce)) {
			if (num > 3 && nn > 1 && nn < n - 2) {
				cout << (num + 1) / 2 + 2 << '\n';
				continue;
			}
			cout << -1 << '\n';
			continue;
		}
		for (ll i = 1; i < n - 1; i++) {
			ans += (arr[i] + 1) / 2;
		}
		cout << ans << '\n';
	}
}
/*
















*/