#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll N, M;
ll modN(ll a) {
	a %= N;
	if (a < 0) a += N;
	return a;
}
ll simulateN(ll st) {
	for (ll t = N; t > 0; t--) {
		if (st < M) {
			st += t;
		} else {
			st -= t;
		}
		st = modN(st);
	}
	return st;
}

ll S;
ll T;

const int MAXN = 1.1e5;
ll dest[MAXN];
ll tmp[MAXN];
ll vis[MAXN];

ll go() {
	while (T % N) {
		if (S < M) {
			S += T;
		} else {
			S -= T;
		}
		S = modN(S);
		T--;
	}

	assert(T % N == 0);
	T /= N;

	if (T == 0) return S;

	if (N-1 - M * (M+1) / 2 <= M) {
		// we're in the large M case, where we're guaranteed to get to M or M-1
		S = simulateN(S);
		T --;
		assert(S == M || S == M-1);

		ll mNext = simulateN(M);
		ll m1Next = simulateN(M-1);
		assert(mNext == M || mNext == M-1);
		assert(m1Next == M || m1Next == M-1);

		if (mNext == M-1 && m1Next == M) {
			// we'll just alternate
			if (T % 2 == 0) return S;
			else return M + (M-1) - S;
		}

		// otherwise, one of them is a fixed point,
		// it takes at most 1 step to get to the fixed point
		if (T == 0) return S;
		assert(T);

		if (S == M) S = mNext;
		else if (S == M-1) S = m1Next;
		else assert(false);
		T--;

		return S;
	} else {
		// we're in the small M case
		for (ll i = 0; i < N; i++) {
			dest[i] = i;
		}

		ll offset = 0;
		for (ll t = 1; t <= N; t++) {
			// destination of i is stored at dest[i-offset]
			for (ll i = 0; i < M; i++) {
				tmp[i] = dest[modN(i + t - offset)];
			}
			offset += t;
			offset %= N;
			for (ll i = 0; i < M; i++) {
				dest[modN(i - offset)] = tmp[i];
			}
		}
		assert(dest[modN(0 - offset)] == simulateN(0));
		for (ll i = 0; i < N; i++) {
			tmp[i] = dest[modN(i-offset)];
		}
		for (ll i = 0; i < N; i++) {
			dest[i] = tmp[i];
		}

		memset(vis, -1, sizeof(vis));
		while (T > 0) {
			if (vis[S] != -1) {
				assert(vis[S] > T);
				// the cycle length is
				ll cycLen = (vis[S] - T);
				T %= cycLen;
				if (T == 0) break;
			}
			assert(T > 0);
			vis[S] = T;
			S = dest[S];
			T--;
		}
		assert(T == 0);
		return S;
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M >> S >> T;
	S--;
	bool flipped = false;
	if (M * 2 > N) {
		S = N - 1 - S;
		M = N - M;
		flipped = true;
	}

	ll res = go();
	if (flipped) {
		res = N - 1 - res;
	}
	cout << res + 1 << '\n';

	return 0;
}