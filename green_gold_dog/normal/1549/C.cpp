#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
		ll n, m;
		cin >> n >> m;
		ll ans = n;
		vector<ll> arr(n, 0);
		for (ll i = 0; i < m; i++) {
			ll v, u;
			cin >> v >> u;
			v--;
			u--;
			if (arr[min(v, u)] == 0) {
				ans--;
			}
			arr[min(v, u)]++;
		}
		ll q;
		cin >> q;
		for (ll i = 0; i < q; i++) {
			ll tu;
			cin >> tu;
			if (tu == 3) {
				cout << ans << '\n';
			} else {
				ll u, v;
				cin >> u >> v;
				u--;
				v--;
				if (tu == 1) {
					if (arr[min(v, u)] == 0) {
						ans--;
					}
					arr[min(v, u)]++;
				} else {
					if (arr[min(v, u)] == 1) {
						ans++;
					}
					arr[min(v, u)]--;
				}
			}
		}
}