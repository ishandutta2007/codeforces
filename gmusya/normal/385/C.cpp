#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

const ll MAXN = 1e7 + 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector <ll> lp(MAXN), pos(MAXN), pr;
	for (ll i = 2; i < MAXN; i++) {
		if (!lp[i]) pr.push_back(i), lp[i] = i, pos[i] = pr.size();
		else pos[i] = pos[i - 1];
		for (ll j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] < MAXN; j++) lp[i * pr[j]] = pr[j];
	}
	ll n;
	cin >> n;
	vector <ll> a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];
	vector <ll> q(pr.size() + 10);
	for (ll i = 0; i < n; i++) {
		while (a[i] != 1) {
			ll x = lp[a[i]];
			q[pos[x]]++;
			while (a[i] % x == 0)
				a[i] /= x;
		}
	}
	vector <ll> pre(pr.size() + 10);
	for (ll i = 1; i <= pr.size(); i++)
		pre[i] = pre[i - 1] + q[i];
	ll m;
	cin >> m;
	while (m--) {
		ll l, r;
		cin >> l >> r;
		l = min(l, MAXN - 1);
		r = min(r, MAXN - 1);
		cout << pre[pos[r]] - pre[pos[l - 1]] << endl;
	}
	return 0;
}