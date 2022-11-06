#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<ll, ll> lp;

ll n, m, a[200][200];
bool pake[200];

int main() {
	cin >> n >> m;
	for (ll i = 1; i <= m; i++) {
		for (ll j = 1; j <= n; j++) {
			cin >> a[j][i];
		}
	}
	ll ans = m;
	vector<ll> vans;
	for (ll i = 1; i < n; i++) {
		memset(pake, false, sizeof(pake));
		ll tmp = m;
		ll x = 0;
		vector<lp> v;
		for (ll j = 1; j <= m; j++) {
			if (a[i][j] >= a[n][j]) {
				x += a[i][j]-a[n][j];
				pake[j] = true;
				tmp--;
			} else {
				v.pb({a[i][j]-a[n][j], j});
			}
		}
		sort(v.rbegin(), v.rend());
		for (lp vi : v) {
			if (x+vi.fi >= 0) {
				pake[vi.se] = true;
				x+=vi.fi;
				tmp--;
			}
		}
		if (tmp <= ans) {
			ans = tmp;
			vans.clear();
			for (ll j = 1; j <= m; j++) {
				if (!pake[j]) vans.pb(j);
			}
		}
	}
	cout << ans << "\n";
	for (int i = 0; i < ans; i++) {
		if (i > 0) cout << " ";
		cout << vans[i];
	}
	cout << "\n";
	return 0;
}