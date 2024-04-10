//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
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
const ll MOD = 998244353;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1<<18;
ll st[2*N], z[2*N];

void push(int i) {
	if(z[i]) {
		st[2*i] += z[i];
		st[2*i+1] += z[i];
		z[2*i] += z[i];
		z[2*i+1] += z[i];
		z[i] = 0;
	}
}

void pull(int i) {
	st[i] = min(st[2*i], st[2*i+1]);
}

void update(int l, int r, int v, int i=1, int s=0, int e=N-1) {
	if(r<s || e<l) return;
	if(l<=s && e<=r) {
		st[i] += v;
		z[i] += v;
		return;
	}
	push(i);
	int m = (s+e) / 2;
	update(l, r, v, 2*i, s, m);
	update(l, r, v, 2*i+1, m+1, e);
	pull(i);
}

ll query(int l, int r, int i=1, int s=0, int e=N-1) {
	if(r<s || e<l) return INFLL;
	if(l<=s && e<=r) {
		return st[i];
	}
	push(i);
	int m = (s+e) / 2;
	return min(query(l, r, 2*i, s, m), query(l, r, 2*i+1, m+1, e));
}

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	vector<int> cost(n), a(n);
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	for(int i=0; i<n; i++) {
		cin >> cost[i];
		update(a[i], n, cost[i]);
	}

	ll ans = INFLL;
	for(int i=0; i<n-1; i++) {
		update(a[i], n, -cost[i]);
		update(0, a[i]-1, cost[i]);
		ans = min(ans, query(0, n));
	}
	cout << ans << nl;

	return 0;
}