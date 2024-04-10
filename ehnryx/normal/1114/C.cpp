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

	ll n, b;
	cin >> n >> b;

	ll ans = INFLL;
	int lim = sqrt(b);
	for (int i=2; i<=lim; i++) {
		if (b%i == 0) {
			int pcnt = 0;
			while (b%i == 0) {
				b /= i;
				pcnt++;
			}
			ll cnt = 0;
			for (ll k=n; k>0; k/=i) {
				cnt += k/i;
			}
			ans = min(ans, cnt/pcnt);
		}
	}
	if (b>1) {
		ll cnt = 0;
		for (ll k=n; k>0; k/=b) {
			cnt += k/b;
		}
		ans = min(ans, cnt);
	}
	cout << ans << nl;

	return 0;
}