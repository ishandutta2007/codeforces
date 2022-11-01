#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

ll const INF = 1e9;

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, m;
		cin >> n >> m;
		vector <ll> a(n), b(m);
		for (ll i = 0; i < n; i++)
			cin >> a[i];
		for (ll i = 0; i < m; i++)
			cin >> b[i];
		vector <ll> sopostb(n);
		for (ll i = 0; i < m; i++)
			sopostb[b[i] - 1] = i + 1;
		for (ll i = 0; i < n; i++)
			if (sopostb[a[i] - 1] == 0)
				a[i] = INF;
			else
				a[i] = sopostb[a[i] - 1];
		ll ans = 0;
		vector <bool> send(m + 1);
		ll uk = 1;
		ll pos = 0;
		ll cnt = 0;
		ll deleted = 0;
		ll notdeleted = 0;
		for (ll i = 0; i < n; i++) {
			if (a[i] == INF) {
				cnt++;
				continue;
			}
			if (a[i] > uk) {
				send[a[i]] = true;
				notdeleted++;
				ans++;
				continue;
			}
			if (a[i] == uk) {
				ans += (i - deleted) * 2 + 1;
				notdeleted = 0;
				pos = i + 1;
				send[uk] = true;
				while (uk < m + 1 && send[uk]) {
					uk++;
					deleted++;
				}
				continue;
			}
		}
		cout << ans << endl;
	}
	return 0;
}