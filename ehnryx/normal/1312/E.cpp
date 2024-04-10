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
const ld EPS = 1e-11;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 500 + 1;
int a[N];
int dp[N][N];
int stk[N];

int calc(int l, int r) {
	int id = 0;
	for(int i=l; i<=r; i++) {
		int cur = a[i];
		while(cur == stk[id]) {
			cur++;
			id--;
		}
		stk[++id] = cur;
	}
	assert(id > 0);
	return id;
}

int solve(int l, int r) {
	if(l == r) return 1;
	if(dp[l][r] != -1) return dp[l][r];
	int res = calc(l, r);
	for(int i=l; i<r; i++) {
		res = min(res, solve(l, i) + solve(i+1, r));
	}
	return dp[l][r] = res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	memset(dp, -1, sizeof dp);
	cout << solve(1, n) << nl;

	return 0;
}