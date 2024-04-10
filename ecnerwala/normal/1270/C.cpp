#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int  T; cin >> T;
	while (T--) {
		int N; cin >> N;
		ll s = 0, x = 0;
		for (int i = 0; i < N; i++) {
			ll a; cin >> a;
			s += a;
			x ^= a;
		}
		ll v = (1ll << 58) - 4;
		ll lo = x ^ (v>>1);
		ll hi = v - s - lo;
		assert(hi >= 0);
		assert(!(hi & 1));
		hi >>= 1;
		ll ans[3] = {0,0,0};
		for (int i = 0; i < 60; i++) {
			int c = bool(hi & (1ll << i)) * 2 + bool(lo & (1ll << i));
			for (int z = 0; z < c; z++) {
				ans[z] |= (1ll << i);
			}
		}
		//assert(s + ans[0] + ans[1] + ans[2] == 2 * (x ^ ans[0] ^ ans[1] ^ ans[2]));
		cout << 3 << '\n';
		cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
	}

	return 0;
}