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

const int N = 1<<20;
int st[2*N];

void insert(int i, int v=1) {
	st[i+=N] += v;
	for(i/=2; i; i/=2) {
		st[i] = st[2*i] + st[2*i+1];
	}
}

int query(int k) {
	int i = 1;
	while(i < N) {
		if(st[2*i] >= k) {
			i = 2*i;
		} else {
			k -= st[2*i];
			i = 2*i+1;
		}
	}
	return i - N;
}

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		int a;
		cin >> a;
		insert(a);
	}

	for(int j=0; j<m; j++) {
		int v;
		cin >> v;
		if(v > 0) {
			insert(v);
		} else {
			insert(query(-v), -1);
		}
	}

	int ans = query(1);
	if(ans > n) {
		cout << 0 << nl;
	} else {
		cout << ans << nl;
	}

	return 0;
}