#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

inline ld easy(ld x) {
	return atan2(1,x);
}

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n, d;
	cin >> n >> d;

	int a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	const int cap = 3500;

	int m;
	cin >> m;

	for (int i=0; i<m; i++) {
		int x;
		cin >> x;

		int* r = lower_bound(a, a+n, x);
		if (r == a) {
			cout << easy(*r-x) << nl;
		} else if (r == a+n) {
			cout << easy(x-(*(r-1)+1)) << nl;
		} else {
			int* l = r-1;
			ld ans = easy(min(*r-x, x-(*l+1)));
			for (int j=0; j<cap; j++) {
				int left = x-(*l+1);
				int right = *r-x;
				if (abs(left-right) <= 1) {
					ans = max(ans, 2 * easy(max(left, right)));
					break;
				} else if (left < right) {
					if (l-- == a) break;
				} else {
					if (++r == a+n) break;
				}
			}
			cout << ans << nl;
		}
	}

	return 0;
}