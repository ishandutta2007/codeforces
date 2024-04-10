#include <iostream>
#include <vector>
#include <unordered_map>

#define ll long long

using namespace std;

const ll P = 909091;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll MAXN = 1e5+1;
	vector <bool> all(MAXN, true);
	vector <ll> pr, lp(MAXN);
	vector <ll> pos(MAXN);
	for (ll i = 2; i < MAXN; i++) {
		if (lp[i] == 0) {
			pos[i] = pr.size();
			pr.push_back(i);
			lp[i] = i;
		}
		for (ll j = 0; j < pr.size() && pr[j] <= i && pr[j] * i < MAXN; j++) 
			lp[pr[j] * i] = pr[j];
	}
	vector <ll> p(pr.size());
	p[0] = 1;
	for (ll i = 1; i < pr.size(); i++)
		p[i] = p[i - 1] * P;
	ll n, k;
	cin >> n >> k;
	vector <ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	vector <vector <pair <ll, ll>>> d(n);
	for (ll i = 0; i < n; i++) {
		ll x = a[i];
		while (x != 1) {
			ll cnt = 0;
			ll div = lp[x];
			while (x % div == 0) {
				cnt++;
				x /= div;
			}
			if (cnt % k)
				d[i].push_back({ div, cnt % k });
		}
	}
	ll ans = 0;
	unordered_map <ll, ll> cnt;
	for (ll i = 0; i < n; i++) {
		ll h = 0;
		for (auto now : d[i])
			h = (h + p[pos[now.first]] * now.second);
		ll obrh = 0;
		for (auto now : d[i])
			obrh = (obrh + p[pos[now.first]] * (k - now.second));
		ans += cnt[obrh];
		cnt[h]++;
	}
	cout << ans;
	return 0;
}