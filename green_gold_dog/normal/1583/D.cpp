#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1'000'000'000'000'000;

template<typename T>
bool assign_min(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_max(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	ll last;
	for (last = n; last > 1; last--) {
		cout << '?' << ' ';
		for (ll i = 0; i < n - 1; i++) {
			cout << 1 << ' ';
		}
		cout << n - last + 2 << '\n';
		cout.flush();
		ll x;
		cin >> x;
		if (x == 0) {
			break;
		}
	}
	vector<ll> arr(n, -1);
	arr.back() = last;
	for (ll i = 1; i <= n; i++) {
		if (i < last) {
			cout << "? ";
			for (ll j = 0; j < n - 1; j++) {
				cout << last - i + 1 << ' ';
			}
			cout << 1 << '\n';
			cout.flush();
			ll x;
			cin >> x;
			x--;
			arr[x] = i;
		}
		if (i > last) {
			cout << "? ";
			for (ll j = 0; j < n - 1; j++) {
				cout << 1 << ' ';
			}
			cout << i - last + 1 << '\n';
			cout.flush();
			ll x;
			cin >> x;
			x--;
			arr[x] = i;
		}
	}
	cout << "! ";
	for (auto i : arr) {
		cout << i << ' ';
	}
}

/*
















*/