#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
const ll INF = 1e18;
int BASE;
ll f[11][64][1024];

void preprocess() {
	for (BASE = 2; BASE <= 10; ++BASE) {
		f[BASE][0][0] = 1;
		int it = 0;
		ll pow = 1;
		while (pow <= INF / BASE) {
			for (int mask = 0; mask < 1 << BASE; ++mask)
				for (int k = 0; k < BASE; ++k)
					f[BASE][it+1][mask^1<<k] += f[BASE][it][mask];
			++it, pow *= BASE;
		}
	}
}

ll solve(ll x) {
	int it = 0, cur = 1, mask = 2;
	ll res = 0, pow = 1;
	while (pow <= x / (cur + 1)) {
		res += f[BASE][it][mask];
		if (cur == BASE - 1) {
			cur = 1, mask = 2;
			++it, pow *= BASE;
		} else {
			mask ^= 1 << cur++;
			mask ^= 1 << cur;
		}
	}
	while (x -= cur * pow, --it, pow /= BASE) {
		cur = 0, mask ^= 1;
		while ((cur + 1) * pow <= x) {
			res += f[BASE][it][mask];
			mask ^= 1 << cur++;
			mask ^= 1 << cur;
		}
	}
	return (res += !mask);
}

int main() {
	preprocess();
	int Q; scanf("%d", &Q);
	for (int i = 0; i < Q; ++i) {
		ll L, R; scanf("%d%lld%lld", &BASE, &L, &R);
		printf("%lld\n", solve(R) - solve(L-1));
	}
}