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

const int L = 32;
int cnt[L];
ll dp[L];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		int d, m;
		cin >> d >> m;
		int len = 32 - __builtin_clz(d);
		for(int i=0; i<len; i++) {
			int pre = (1 << i) - 1;
			int nxt = min((1 << (i+1)) - 1, d);
			cnt[i+1] = nxt - pre;
		}
		ll sum = 0;
		dp[0] = 1;
		for(int i=1; i<=len; i++) {
			dp[i] = 0;
			for(int j=0; j<i; j++) {
				dp[i] += dp[j];
			}
			dp[i] = dp[i] % m * cnt[i] % m;
			sum += dp[i];
		}
		cout << sum % m << nl;
	}

	return 0;
}