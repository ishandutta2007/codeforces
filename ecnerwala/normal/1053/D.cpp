#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = int(1e9) + 7;

const int MAXV = 2.2e6;
const int V = 2.1e6;
int fac[MAXV];

int N;

int cnt[MAXV];
int has[MAXV];
int best[MAXV];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	for (int i = 2; i <= V; i++) {
		if (fac[i]) continue;
		for (int j = i; j <= V; j += i) {
			fac[j] = i;
		}
	}

	cin >> N;
	for (int i = 0; i < N; i++) {
		int p; cin >> p;
		assert(p <= V);
		assert(fac[p] == p);
		cnt[p]++;
	}

	ll res = 1;
	bool extra = false;

	for (int p = V; p >= 2; p--) {
		if (fac[p] != p) continue;
		if (cnt[p] && !has[p]) {
			cnt[p]--;
			has[p] = 1;
			best[p] = 1;
		}

		if (has[p]) {
			for (int i = 0; i < best[p]; i++) {
				res = res * ll(p) % MOD;
			}
		}

		if (!cnt[p]) continue;
		assert(has[p]);

		if (cnt[p] >= 2) extra = true;
		int v = p-1;
		while(v > 1) {
			int q = fac[v];
			int e = 0;
			while(v % q == 0) v /= q, e++;
			if (e > best[q]) {
				best[q] = e;
				has[q] = 0;
			}
			if (e == best[q]) {
				has[q] ++;
			}
		}
	}

	if (!extra) {
		for (int p = V; p >= 2; p--) {
			if (fac[p] != p) continue;
			if (cnt[p]) {
				// we have guys that went downwards
				assert(has[p]);
				int v = p-1;
				bool good = true;
				while (v > 1) {
					int q = fac[v];
					int e = 0;
					while(v % q == 0) v /= q, e++;
					if (e == best[q] && has[q] == 1) {
						good = false;
						break;
					}
				}
				if (good) {
					extra = true;
					break;
				}
			}
		}
	}

	if (extra) {
		res++;
		res %= MOD;
	}
	cout << res << '\n';

	return 0;
}