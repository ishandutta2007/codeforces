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
	ll t;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		ll s, n;
		cin >> s >> n;
		multiset<ll> ms;
		ll d = 1;
		if (n == 1) {
			cout << s << '\n';
			continue;
		}
		while (n != 1 && s != 0) {
			if (s % 10 != 0) {
				ll now = s % 10;
				if (s >= 10) {
					for (ll i = 0; now > 0 && n != 2; i++) {
						ms.insert(d);
						now--;
						n--;
					}
					if (now != 0) {
						ms.insert(now * d);
						n--;
					}
				} else {
					for (ll i = 0; now > 0 && n != 1; i++) {
						ms.insert(d);
						now--;
						n--;
					}
					if (now != 0) {
						ms.insert(now * d);
						n--;
					}
				}
			}
			s /= 10;
			d *= 10;
		}
		if (n != 0 && s != 0) {
			ms.insert(s * d);
			n--;
		}
		ll ce = 0;
		while (n > 0) {
			ll now = *ms.begin();
			ms.erase(ms.begin());
			if (now == 1) {
				ce++;
				continue;
			}
			ll ns = now / 10;
			while (now != ns && n != 0) {
				ms.insert(ns);
				now -= ns;
				n--;
			}
			ms.insert(now);
		}
		for (ll i = 0; i < ce; i++) {
			cout << 1 << ' ';
		}
		for (auto i : ms) {
			cout << i << ' ';
		}
		cout << '\n';
	}
}

/*
















*/