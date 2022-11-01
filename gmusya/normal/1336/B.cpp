#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

typedef long long ll;

using namespace std;

const ll INF = 3e18;

const ll min3(ll a, ll b, ll c) {
	ll k = a;
	if (k > b) k = b;
	if (k > c) k = c;
	return k;
}

ll sqr(ll val) {
	return val * val;
}

ll solve(vector <ll> &a, vector <ll> &b, vector <ll> &c) {
	int na = a.size(), nb = b.size(), nc = c.size();
	ll ans = INF;
	for (int i = 0; i < b.size(); i++) {
		if (a[0] > b[i] || b[i] > c[nc - 1]) continue;
		ll x = *(--upper_bound(a.begin(), a.end(), b[i]));
		ll y = b[i];
		ll z = *(lower_bound(c.begin(), c.end(), b[i]));
		ans = min(ans, sqr(x - y) + sqr(x - z) + sqr(y - z));
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int nr, ng, nb;
		cin >> nr >> ng >> nb;
		vector <ll> r(nr), g(ng), b(nb);
		for (int i = 0; i < nr; i++)
			cin >> r[i];
		for (int i = 0; i < ng; i++)
			cin >> g[i];
		for (int i = 0; i < nb; i++)
			cin >> b[i];
		sort(r.begin(), r.end());
		sort(g.begin(), g.end());
		sort(b.begin(), b.end());
		ll ans = INF;
		ans = min(ans, solve(r, g, b));
		ans = min(ans, solve(r, b, g));
		ans = min(ans, solve(b, r, g));
		ans = min(ans, solve(b, g, r));
		ans = min(ans, solve(g, b, r));
		ans = min(ans, solve(g, r, b));
		cout << ans << endl;
	}
	return 0;
}