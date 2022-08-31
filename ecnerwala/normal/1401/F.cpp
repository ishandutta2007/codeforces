#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, Q; cin >> N >> Q;
	int S = (1 << N);
	vector<int64_t> seg(2 * S);
	for (int i = 0; i < S; i++) cin >> seg[S+i];
	for (int i = S-1; i; --i) seg[i] = seg[2*i] + seg[2*i+1];

	int msk = 0;
	while (Q--) {
		int t; cin >> t;
		if (t == 1) {
			int x; int64_t v; cin >> x >> v; x--;
			x ^= msk;
			int64_t delta = v - seg[S+x];
			for (int a = S+x; a; a >>= 1) seg[a] += delta;
		} else if (t == 2) {
			// reverse
			int k; cin >> k;
			msk ^= (1 << k) - 1;
		} else if (t == 3) {
			// flip
			int k; cin >> k;
			msk ^= (1 << k);
		} else if (t == 4) {
			int l, r; cin >> l >> r; l--; // half-open
			int64_t ans = 0;
			for (int a = S+l, b = S+r, m = msk; a < b; a >>= 1, b >>= 1, m >>= 1) {
				if (a & 1) ans += seg[(a++)^m];
				if (b & 1) ans += seg[(--b)^m];
			}
			cout << ans << '\n';
		} else assert(false);
	}

	return 0;
}