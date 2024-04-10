#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		ll ans = [&]() -> ll {
			int N; ll X; cin >> N >> X;
			ll mx = 0;
			bool hasX = false;
			for (int i = 0; i < N; i++) {
				ll a; cin >> a;
				if (a == X) hasX = true;
				mx = max(mx, a);
			}
			if (hasX) return 1;
			return max(2ll, (X + mx - 1) / mx);
		}();
		cout << ans << '\n';
	}

	return 0;
}