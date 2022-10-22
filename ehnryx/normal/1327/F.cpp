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
const ll MOD = 998244353;
const ld EPS = 1e-11;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1 << 19;
int st[2*N];
void insert(int l, int r, int x) {
	for(l+=N, r+=N+1; l<r; l/=2, r/=2) {
		if(l&1) st[l++] |= x;
		if(r&1) st[--r] |= x;
	}
}
int query(int x) {
	int v = 0;
	for(x+=N; x>0; x/=2) {
		v |= st[x];
	}
	return v;
}

int li[N], ri[N], xi[N];
int base[N];

bool skip[N];
vector<int> other[N];
ll dp[N], pre[N];

ll solve(int n, int m, int b) {
	for(int i=1; i<=n; i++) {
		if(base[i] & 1<<b) {
			skip[i] = true;
		} else {
			skip[i] = false;
		}
		other[i].clear();
	}

	for(int i=0; i<m; i++) {
		if((xi[i] & 1<<b) == 0) {
			other[ri[i]].push_back(li[i]);
		}
	}

	pre[1] = 1;
	int left = 0;
	for(int i=1; i<=n+1; i++) {
		if(skip[i]) {
			dp[i] = 0;
		} else {
			dp[i] = (pre[i] - pre[left]) % MOD;
		}
		pre[i+1] = (pre[i] + dp[i]) % MOD;
		for(int j : other[i]) {
			left = max(left, j);
		}
	}
	return (dp[n+1] + MOD) % MOD;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, k, m;
	cin >> n >> k >> m;
	for(int i=0; i<m; i++) {
		cin >> li[i] >> ri[i] >> xi[i];
		insert(li[i], ri[i], xi[i]);
	}
	for(int i=1; i<=n; i++) {
		base[i] = query(i);
	}

	ll ans = 1;
	for(int i=0; i<k; i++) {
		ans = ans * solve(n, m, i) % MOD;
	}
	cout << ans << nl;

	return 0;
}