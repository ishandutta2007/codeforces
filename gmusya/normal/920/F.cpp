#include <iostream>
#include <vector>
#include <set>

#define ll long long
#define endl '\n'

using namespace std;

vector <ll> f;

void add(ll i, ll val) {
	while (i < f.size()) {
		f[i] += val;
		i |= (i + 1);
	}
}

ll pref(ll i) {
	ll res = 0;
	while (i != -1) {
		res += f[i];
		i = (i & (i + 1)) - 1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 1e6 + 1;
	vector <bool> all(n, true);
	vector <ll> pr, lp(n), d(n), kek(n, 1);
	for (ll i = 2; i < n; i++) {
		if (lp[i] == 0) {
			pr.push_back(i);
			lp[i] = i;
			kek[i] = 2;
			d[i] = 1;
		}
		for (ll j = 0; j < pr.size() && pr[j] <= i && pr[j] * i < n; j++) {
			lp[pr[j] * i] = pr[j];
			if (lp[i] == pr[j])
				d[pr[j] * i] = d[i] + 1;
			else
				d[pr[j] * i] = 1;
		}
	}
	for (ll i = 2; i < n; i++) {
		ll hm = 1;
		for (ll x = 0; x < d[i]; x++)
			hm *= lp[i];
		kek[i] = (d[i] + 1) * (kek[i / hm]);
	}
	ll m, q;
	cin >> m >> q;
	vector <ll> a(m);
	f.resize(m);
	for (ll i = 0; i < m; i++) {
		cin >> a[i];
		add(i, a[i]);
	}
	set <ll> s;
	for (ll i = 0; i < m; i++)
		if (a[i] > 2)
			s.insert(i);
	vector <ll> answer;
	for (ll i = 0; i < q; i++) {
		ll t;
		cin >> t;
		if (t == 1) {
			ll l, r;
			cin >> l >> r;
			l--;
			r--;
			ll pos = l;
			while (pos <= r && s.lower_bound(pos) != s.end()) {
				pos = *s.lower_bound(pos);
				if (pos > r)
					break;
				add(pos, kek[a[pos]] - a[pos]);
				a[pos] = kek[a[pos]];
				if (a[pos] <= 2)
					s.erase(pos);
				pos++;
			}
		}
		if (t == 2) {
			ll l, r;
			cin >> l >> r;
			answer.push_back(pref(r - 1) - pref(l - 2));
		}
	}
	for (auto now : answer)
		cout << now << endl;
	return 0;
}