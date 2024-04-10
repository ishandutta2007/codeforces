#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 1.1e6;
int N;
ll K;

ll V[MAXN];
ll U[MAXN];

ll numMatches(ll msk) {
	ll res = 0;
	for (int i = 0, j = 0; i < N && j < N; ) {
		ll val = min(V[i], U[j]) & msk;
		ll nv = 0;
		while (i < N && (V[i] & msk) == val) {
			nv++;
			i++;
		}
		ll nu = 0;
		while (j < N && (U[j] & msk) == val) {
			nu++;
			j++;
		}
		res += nv * nu;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cerr.tie(0);
	cin >> N >> K;
	for (int i = 1; i < N; i++) {
		int p; ll w; cin >> p >> w;
		p--;
		assert(0 <= p && p < i);
		V[i] = V[p] ^ w;
	}
	sort(V, V + N);

	for (int i = 0; i < N; i++) {
		U[i] = V[i];
	}

	assert(numMatches(0) == ll(N) * ll(N));

	ll res = 0;
	for (ll msk = 0, z = 61; z >= 0; z--) {
		ll bit = (1ll << z);
		ll matches = numMatches(msk | bit);
		if (matches < K) {
			// we need to flip it
			res |= bit;
			K -= matches;

			for (int i = 0; i < N; ) {
				ll val = U[i] & msk;
				int st = i;
				int en = st;
				while (en < N && (U[en] & msk) == val) {
					en++;
				}
				int md = st;
				while (md < en && (U[md] & bit) == 0) {
					md++;
				}
				for (int a = st; a < en; a++) {
					U[a] ^= bit;
				}
				if (st < md && md < en) {
					reverse(U + st, U + md);
					reverse(U + md, U + en);
					reverse(U + st, U + en);
				}

				i = en;
			}
		}
		msk |= bit;
	}
	cout << res << '\n';

	return 0;
}