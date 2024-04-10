#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll N, K; cin >> N >> K;
	int L = 63 - __builtin_clzll(N);
	assert((1ll << L) <= N && N < (2ll << L));

	auto numMatch = [&](int l, ll cnd) {
		ll Nval = N >> (L-l);
		if (Nval < cnd) {
			// too small
			return (1ll << (L-l)) - 1;
		} else if (Nval == cnd) {
			return (N ^ ((cnd ^ 1) << (L-l)));
		} else {
			return (1ll << (L-l+1)) - 1;
		}
	};

	auto numPath = [&](int l, ll cnd) {
		assert(l >= 1);
		if (cnd % 2 == 0) {
			return numMatch(l-1, cnd / 2) - 1;
		} else {
			return numMatch(l, cnd);
		}
	};

	int l = 1;
	while (true) {
		if (l > L) break;
		if (numPath(l, (1ll << l)) >= K) {
			// it's good
		} else {
			break;
		}
		l++;
	}
	l--;
	if (l == 0) {
		cout << 1 << '\n';
		exit(0);
	}

	ll ans = (1ll << l);
	for (int i = l-1; i > 0; i--) {
		ll cnd = ans | (1ll << i);
		if (numPath(l, cnd) >= K) {
			ans = cnd;
		} else {
			// do nothing
		}
	}
	ll cnd = ans | 1;
	if (numPath(l, cnd) >= K) {
		ans = cnd;
	} else {
	}
	cout << ans << '\n';

	return 0;
}