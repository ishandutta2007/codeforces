#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXX = 2.1e5;
const int MAXY = 2.1e5;
const int MAXK = 2.1e5;
const int MAXQ = 2.1e5;

int X, Y, K, Q;
map<int, set<int>> treasure;
int B[MAXQ];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> X >> Y >> K >> Q;
	for (int i = 0; i < K; i++) {
		int r, c; cin >> r >> c;
		treasure[r].insert(c);
	}
	for (int i = 0; i < Q; i++) {
		cin >> B[i];
	}
	sort(B, B + Q);

	treasure[1].insert(1);

	int deltaX = treasure.rbegin()->first - 1;
	map<int, ll> dp;
	dp[*treasure[1].rbegin()] = deltaX + (*treasure[1].rbegin() - 1);
	treasure.erase(1);

	for (const auto& row : treasure) {
		map<int, ll> ndp;
		int lo = *(row.second.begin());
		int hi = *(row.second.rbegin());
		ndp[hi] = ndp[lo] = 1e18;
		for (auto it : dp) {
			int p = it.first;
			ll val = it.second;
			for (int ind = int(lower_bound(B, B + Q, p) - B), z = 0; z < 2; z++, ind--) {
				if (0 <= ind && ind < Q) {
					ll vhi = val + abs(B[ind] - p) + abs(B[ind] - lo) + abs(lo - hi);
					ndp[hi] = min(ndp[hi], vhi);
					ll vlo = val + abs(B[ind] - p) + abs(B[ind] - hi) + abs(lo - hi);
					ndp[lo] = min(ndp[lo], vlo);
				}
			}
		}
		dp = ndp;
	}
	ll ans = 1e18;
	for (auto it : dp) {
		ans = min(ans, it.second);
	}
	cout << ans << '\n';

	return 0;
}