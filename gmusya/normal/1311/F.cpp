#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#define ll long long

using namespace std;

ll n;

vector <ll> used;
vector <ll> t;

void add(ll i, ll val, vector <ll> &t) {
	while (i < n) {
		t[i] += val;
		i |= (i + 1);
	}
}

ll pref(ll i, vector <ll> &t) {
	ll res = 0;
	while (i != -1) {
		res += t[i];
		i = (i & (i + 1)) - 1;
	}
	return res;
}

int main() {
	cin >> n;
	vector <ll> a(n), b(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	for (ll i = 0; i < n; i++)
		cin >> b[i];
	t.resize(n), used.resize(n);
	vector <ll> c(n);
	for (ll i = 0; i < n; i++)
		c[i] = b[i];
	sort(c.begin(), c.end());
	unordered_map <ll, ll> m;
	for (ll i = 0; i < n; i++)
		m[c[i]] = i;
	vector <pair <ll, ll>> arr(n);
	for (ll i = 0; i < n; i++)
		arr[i] = { a[i], b[i] };
	sort(arr.begin(), arr.end());

	ll d = 0;
	for (ll i = 0; i < n; i++) {
		ll x = arr[i].first;
		ll v = arr[i].second;
		d += pref(m[v], used) * x - pref(m[v], t);
		add(m[v], 1, used);
		add(m[v], x, t);
	}
	cout << d;
	return 0;
}