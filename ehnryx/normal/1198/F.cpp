#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// DON'T USE THESE MACROS DURING ICPC PRACTICE
#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
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

const int N = 1e5+1;
int a[N], b[N];
bool dp[1<<18];
pii pre[1<<18];

bool solve_small(int n) {
	for (int bm=1; bm<1<<n; bm++) {
		int g1=0, g2=0;
		For(i,n) {
			if (bm&1<<i) {
				g1 = __gcd(g1, a[i]);
				b[i] = 1;
			} else {
				g2 = __gcd(g2, a[i]);
				b[i] = 2;
			}
		}
		if (g1==1 && g2==1) return true;
	}
	return false;
}

vector<int> get_primes(int v) {
	vector<int> res;
	for (int i=2; i<4e4; i++) {
		if (v%i == 0) {
			res.push_back(i);
			for (v/=i; v%i == 0; v/=i);
		}
	}
	if (v>1) res.push_back(v);
	return res;
}

bool solve_large(int s, int t, int n) {
	vector<int> ps = get_primes(a[s]);
	vector<int> pt = get_primes(a[t]);
	int sz = ps.size();
	int tz = pt.size();
	vector<int> cs(sz,0), ct(tz,0);
	vector<int> check;
	For(i,n) {
		if (i==s || i==t) continue;
		bool ok = false;
		for (int j=0; j<sz; j++) {
			if (cs[j]<2*9 && a[i]%ps[j] != 0) {
				ok = true;
				cs[j]++;
			}
		}
		for (int j=0; j<tz; j++) {
			if (ct[j]<2*9 && a[i]%pt[j] != 0) {
				ok = true;
				ct[j]++;
			}
		}
		if (ok) {
			check.push_back(i);
		}
	}

	memset(dp, false, sizeof dp);
	dp[0] = true;
	for (int i : check) {
		for (int bm=(1<<(sz+tz))-1; bm>=0; bm--) {
			if (dp[bm]) {
				int nxt1 = bm;
				int nxt2 = bm;
				for (int j=0; j<sz; j++) {
					if (a[i]%ps[j] != 0) nxt1 |= 1<<j;
				}
				for (int j=0; j<tz; j++) {
					if (a[i]%pt[j] != 0) nxt2 |= 1<<(sz+j);
				}
				if (!dp[nxt1]) {
					dp[nxt1] = true;
					pre[nxt1] = pii(bm, i);
				}
				if (!dp[nxt2]) {
					dp[nxt2] = true;
					pre[nxt2] = pii(bm, -1);
				}
			}
		}
		if (dp[(1<<(sz+tz))-1]) {
			fill(b, b+n, 2);
			b[s] = 1;
			for (int m=(1<<(sz+tz))-1; m>0; m=pre[m].first) {
				if (pre[m].second != -1) b[pre[m].second] = 1;
			}
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	For(i,n) {
		cin >> a[i];
	}

	if (n<20) {
		if (solve_small(n)) {
			cout << "YES" << nl;
			For(i,n) {
				cout << b[i] << " ";
			}
			cout << nl;
		} else {
			cout << "NO" << nl;
		}
		return 0;
	}

	// solve large
	FOR(i,1,9) {
		if (solve_large(0, i, n)) {
			cout << "YES" << nl;
			For(j,n) {
				cout << b[j] << " ";
			}
			cout << nl;
			return 0;
		}
	}
	cout << "NO" << nl;

	return 0;
}