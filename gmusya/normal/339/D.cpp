#include <iostream>
#include <vector>

#define ll long long 
using namespace std;

vector <ll> a(132000), t(530000);
vector <ll> power_of_2(20);

void build(ll v, ll tl, ll tr) {
	if (tl == tr) 
		t[v] = a[tl];
	else {
		ll tm = (tl + tr) / 2;
		build(v * 2, tl, tm);
		build(v * 2 + 1, tm + 1, tr);
		ll x = tr - tl + 1;
		bool tf = true;
		for (ll i = 0; i < 20; i += 2)
			if (power_of_2[i] == x)
				tf = false;
		if (tf)
			t[v] = t[v * 2] | t[v * 2 + 1];
		else
			t[v] = t[v * 2] ^ t[v * 2 + 1];
	}
}

void update(ll v, ll tl, ll tr, ll pos, ll val) {
	if (tl == tr)
		t[v] = val;
	else {
		ll tm = (tl + tr) / 2;
		if (pos <= tm)
			update(v * 2, tl, tm, pos, val);
		else
			update(v * 2 + 1, tm + 1, tr, pos, val);
		ll x = tr - tl + 1;
		bool tf = true;
		for (ll i = 0; i < 20; i += 2)
			if (power_of_2[i] == x)
				tf = false;
		if (tf)
			t[v] = t[v * 2] | t[v * 2 + 1];
		else
			t[v] = t[v * 2] ^ t[v * 2 + 1];
	}
}

int main() {
	ll n, m;
	cin >> n >> m;
	power_of_2[0] = 1;
	for (ll i = 1; i < 20; i++)
		power_of_2[i] = power_of_2[i - 1] * 2;
	a.resize(power_of_2[n]);
	for (ll i = 0; i < power_of_2[n]; i++)
		cin >> a[i];
	build(1, 0, power_of_2[n] - 1);
	for (ll i = 0; i < m; i++) {
		ll p, b;
		cin >> p >> b;
		update(1, 0, power_of_2[n] - 1, p - 1, b);
		cout << t[1] << endl;
	}
	return 0;
}