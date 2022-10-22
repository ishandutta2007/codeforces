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

	ll a, b;
	cin >> a >> b;

	int lim;
	set<int> sfa, sfb;

	lim = sqrt(a);
	cerr << "lim: " << lim << nl;
	for (int i = 1; i <= lim; i++) {
		if (a % i == 0) sfa.insert(i);
	}

	lim = sqrt(b);
	cerr << "lim: " << lim << nl;
	for (int i = 1; i <= lim; i++) {
		if (b % i == 0) sfb.insert(i);
	}

	ll ans = 0;
	lim = sqrt(a+b);
	cerr << "lim: " << lim << nl;
	for (int i = 1; i <= lim; i++) {
		if ((a+b) % i == 0) {
			if (min(a/(*prev(sfa.upper_bound(i))), b/(*prev(sfb.upper_bound(i)))) <= (a+b)/i) {
				ans = 2*i + 2*(a+b)/i;
			}
		}
	}
	cout << ans << nl;

	return 0;
}