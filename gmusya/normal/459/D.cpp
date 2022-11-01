#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

ll n = 1e6 + 1;
vector <ll> t(n);

void add(ll i, ll val) {
	while (i < n) {
		t[i] += val;
		i |= (i + 1);
	}
}

ll pref(ll i) {
	ll res = 0;
	while (i != -1) {
		res += t[i];
		i = (i & (i + 1)) - 1;
	}
	return res;
}

int main() {
	ll n;
	cin >> n;
	vector <pair <ll, ll>> b(n);
	for (ll i = 0; i < n; i++) {
		cin >> b[i].first;
		b[i].second = i;
	}

	ll cnt = 0;
	sort(b.begin(), b.end());
	vector <ll> a(n);
	for (ll i = 0; i < n; i++) {
		if (i > 0 && b[i].first != b[i - 1].first)
			cnt++;
		a[b[i].second] = cnt;
	}

	vector <ll> used(n), l(n), r(n);
	for (ll i = 0; i < n; i++) {
		used[a[i]]++;
		l[i] = used[a[i]];
	}
	used.assign(n, 0);
	for (ll i = n - 1; i >= 0; i--) {
		used[a[i]]++;
		r[i] = used[a[i]];
	}
	
	ll ans = 0;
	for (ll i = n - 1; i > 0; i--) {
		add(r[i], 1);
		ans += pref(l[i - 1] - 1);
	}
	cout << ans;
	return 0;
}