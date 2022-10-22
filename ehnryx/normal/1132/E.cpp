#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	ll w;
	cin >> w;

	ll cnt[9], val[9];
	for (int i=1; i<=8; i++) {
		cin >> cnt[i];
	}

	ll ans = 0;
	while (clock() < 1.970 * CLOCKS_PER_SEC) {
		memset(val, 0, sizeof val);
		ll cur = 0;
		int iters = 0;
		while (iters < 10) {
			int i = rng()%8 + 1;
			if (val[i] < cnt[i]) {
				ll allow = min(cnt[i]-val[i], (w-cur)/i);
				if (cur+allow*i >= w-17) {
					ans = max(ans, cur+allow*i);
				}
				if (allow > 0) {
					ll add = max(2*allow/3, rng()%allow + 1);
					val[i] += add;
					cur += add*i;
					iters = 0;
				} else {
					iters++;
				}
			} else {
				iters++;
			}
		}
		ans = max(ans, cur);
	}
	cout << ans << nl;

	return 0;
}