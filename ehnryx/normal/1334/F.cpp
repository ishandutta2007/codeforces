//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma")
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
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 5e5 + 7;
int a[N], c[N], b[N];
ll dp[N];

struct BIT {
	ll bit[N];
	BIT() {
		memset(bit, 0, sizeof bit);
	}
	void insert(int x, int v) {
		for(++x; x<N; x+=x&-x) {
			bit[x] += v;
		}
	}
	ll query(int x) {
		ll res = 0;
		for(++x; x>0; x-=x&-x) {
			res += bit[x];
		}
		return res;
	}
	ll query_range(int l, int r) {
		return query(r) - query(l-1);
	}
};

BIT all, neg;

ll query(int v) {
	return all.query_range(v+1, N-2) + neg.query_range(0, v);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	for(int i=1; i<=n; i++) {
		cin >> c[i];
	}
	a[n+1] = n+1;
	c[n+1] = 0;

	int m;
	cin >> m;
	unordered_map<int,int> pre;
	for(int i=1; i<=m; i++) {
		cin >> b[i];
		pre[b[i]] = b[i-1];
	}
	b[m+1] = n+1;
	pre[b[m+1]] = b[m];

	ll ans = INFLL;
	memset(dp, INF, sizeof dp);
	dp[0] = 0;
	for(int i=1; i<=n+1; i++) {
		if(!pre.count(a[i])) {
			all.insert(a[i], c[i]);
			if(c[i] < 0) neg.insert(a[i], c[i]);
			continue;
		} else {
			int v = pre[a[i]];
			ll val = dp[v] + query(v);
			if(a[i] == b[m+1]) ans = min(ans, val);
			all.insert(a[i], c[i]);
			if(c[i] < 0) neg.insert(a[i], c[i]);
			dp[a[i]] = min(dp[a[i]], val - query(a[i]));
		}
	}

	if(ans < INFLL/2) {
		cout << "YES" << nl;
		cout << ans << nl;
	} else {
		cout << "NO" << nl;
	}

	return 0;
}