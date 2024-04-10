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
const ll MOD = 998244353;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1e3+1;
const int M = 1e5+1;
ll cnt[M];
int a[N];
ll dp[N][N], sum[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, k;
	cin >> n >> k;
	For(i,n) {
		cin >> a[i];
	}
	sort(a,a+n);

	function<ll(int)> count = [&] (int lb) {
		memset(sum, 0, sizeof sum);
		int pre = 0;
		For(i,n) {
			dp[i][0] = 1;
			while (a[i]-a[pre] >= lb) {
				For(j,k) {
					sum[j] = (sum[j] + dp[pre][j]) % MOD;
				}
				pre++;
			}
			for (int j=1; j<k; j++) {
				dp[i][j] = sum[j-1];
			}
		}
		ll res = 0;
		For(i,n) {
			res += dp[i][k-1];
		}
		return res % MOD;
	};

	ll ans = 0;
	for (int i=M/(k-1); i>0; i--) {
		cnt[i] = count(i);
		ans += (cnt[i]-cnt[i+1])*i % MOD;
	}
	cout << (ans % MOD + MOD) % MOD << nl;

	return 0;
}