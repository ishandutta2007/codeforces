#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(int)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	REP(i, n) cin >> a[i];
	sort(ALL(a));
	vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));
	FOR(i, 1, n + 1) FOR(j, 1, k + 1) {
		dp[i][j] = dp[i - 1][j];
		auto ite = lower_bound(ALL(a), a[i - 1] - 5);
		ll idx = ite - a.begin();
		ll tmp = i - idx;
		dp[i][j] = max(dp[i][j], tmp + dp[idx][j - 1]);
	}
	ll ans = 0;
	REP(i, k + 1) ans = max(ans, dp[n][i]);
	cout << ans << endl;
	return 0;
}
/* --------------------------------------- */