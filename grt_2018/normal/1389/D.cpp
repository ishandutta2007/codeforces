#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const ll INF = 1e18;
int t, n, k;
pi l, r;

int main() {_
	cin >> t;
	while(t--) {
		cin >> n >> k;
		cin >> l.ST >> l.ND;
		cin >> r.ST >> r.ND;
		if(l.ST > r.ST) swap(l, r);
		ll cur = (ll)max(min(l.ND, r.ND) - max(l.ST, r.ST), 0) * n;
		if(cur >= k) {
			cout << "0\n";
			continue;
		}
		if(r.ST <= l.ND) {
			ll pos = (ll)(max(r.ND, l.ND) - l.ST) * n;
			if(pos >= k) {
				cout << k - cur << "\n";
				continue;
			}
			ll ans = pos - cur;
			k -= pos;
			ans += 2 * k;
			cout << ans << "\n";
			continue;
		}
		int pos = (r.ND - l.ST), x = (r.ST - l.ND);
		ll cost = 0;
		ll ans = INF;
		for(int i = 1; i <= n; ++i) {
			cost += x;
			if(pos >= k) {
				ans = min(ans, cost + k);
				break;
			} else {
				cost += pos;
				k -= pos;
				ans = min(ans, cost + 2 * k);
			}
		}
		cout << ans << "\n";
	}
			
			
}