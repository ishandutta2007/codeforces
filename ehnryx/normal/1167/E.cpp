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

const int N = 1e6+1;
int a[N], v[N], u[N];

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n, x;
	cin >> n >> x;

	set<int> seen;
	memset(u, INF, sizeof u);
	for (int i=0; i<n; i++) {
		cin >> a[i];
		auto it = seen.upper_bound(a[i]);
		if (it != seen.end()) {
			u[a[i]] = min(u[a[i]], *it);
			v[a[i]] = max(v[a[i]], *seen.rbegin());
		}
		seen.insert(a[i]);
	}

	set<int> left, right;
	for (int i=1; i<=x; i++) {
		//cerr << i << ": " << v[i] << " " << u[i] << nl;
		if (v[i]) {
			right.insert(i);
		}
	}

	ll ans = 0;
	for (int lb=1; lb<=x; lb++) {
		right.erase(lb);
		int ub = lb;
		if (!right.empty()) {
			ub = max(ub, *right.rbegin());
		}
		if (!left.empty()) {
			if (*left.begin() < lb) break;
			else ub = max(ub, *left.rbegin());
		}
		ans += max(0,x-ub+1);
		//cerr << lb << ": add " << x-ub+1 << " (up to " << ub << ")" << nl;
		if (v[lb]) {
			left.insert(u[lb]);
			left.insert(v[lb]);
		}
	}

	cout << ans << nl;

	return 0;
}