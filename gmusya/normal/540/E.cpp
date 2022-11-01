#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define ll long long
#define endl '\n'

using namespace std;

ll n = 400003;
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
	map <ll, ll> a;
	ll n;
	cin >> n;
	for (ll i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		ll xn, yn;
		if (a.find(x) == a.end())
			xn = x;
		else
			xn = a[x];
		if (a.find(y) == a.end())
			yn = y;
		else
			yn = a[y];
		a[x] = yn;
		a[y] = xn;
	}
	vector <pair <ll, ll>> x;
	for (auto now : a) {
		x.push_back({ now.second, now.first });
		if (a[now.first + 1] == 0) {
			x.push_back({ now.first + 1, now.first + 1 });
			a.erase(now.first + 1);
		}
	}
	sort(x.begin(), x.end());
	for (ll i = 0; i < x.size(); i++)
		x[i].first = i;
	for (ll i = 0; i < x.size(); i++)
		swap(x[i].first, x[i].second);
	sort(x.begin(), x.end());
	vector <ll> w(x.size());
	for (ll i = 0; i < x.size() - 1; i++)
		w[i] = x[i + 1].first - x[i].first;
	ll ans = 0;
	for (ll i = 0; i < x.size(); i++) {
		add(x[i].second, w[i]);
		ans += (pref(400002) - pref(x[i].second)) * w[i];
	}
	cout << ans;
	return 0;
}