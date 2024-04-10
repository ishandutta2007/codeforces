#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

const int N = 2e4+2;
const int K = 100+1;
int a[N];
ll dp[K][N];
int maxl[N], maxr[N];

void solve(int id, int l, int r) {
	if(l == r) {
		dp[id][r] = min(dp[id][r], dp[id-1][r-1] + a[r]);
		return;
	}

	int m = (l+r)/2;
	solve(id, l, m);
	solve(id, m+1, r);

	//cerr << "solving "<<l<<" "<<r<<nl;

	maxl[m] = a[m];
	for(int i=m-1; i>=l; i--) {
		maxl[i] = max(maxl[i+1], a[i]);
	}
	maxr[m+1] = a[m+1];
	for(int i=m+2; i<=r; i++) {
		maxr[i] = max(maxr[i-1], a[i]);
	}

	LineContainer hull;
	for(int i=m+1, j=m; i<=r; i++) {
		while(j >= l && maxl[j] <= maxr[i]) {
			hull.add(j-1, -dp[id-1][j-1]);
			j--;
		}
		if(!hull.empty()) {
			//cerr<<"upd "<<i<<" -> "<<i<<" * "<<maxr[i]<<" + -"<<hull.query(maxr[i])<<nl;
			dp[id][i] = min(dp[id][i], (ll)i*maxr[i] + -hull.query(maxr[i]));
		}
	}

	hull.clear();
	for(int i=r, j=l; i>m; i--) {
		while(j <= m && maxl[j] >= maxr[i]) {
			hull.add(-maxl[j], -(dp[id-1][j-1] - (ll)(j-1)*maxl[j]));
			j++;
		}
		if(!hull.empty()) {
			//cerr<<"upd "<<i<<" -> -"<<hull.query(i)<<nl;
			dp[id][i] = min(dp[id][i], -hull.query(i));
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, k;
	cin >> n >> k;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}

	memset(dp, INF, sizeof dp);
	dp[0][0] = 0;
	for(int j=1; j<=k; j++) {
		solve(j, 1, n);
		for(int i=0; i<=n; i++) {
			//cerr<<j<<" "<<i<<" -> "<<dp[j][i]<<nl;
		}
	}
	cout << dp[k][n] << nl;

	return 0;
}