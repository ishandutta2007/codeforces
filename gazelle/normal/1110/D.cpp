#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<iomanip>
#include<math.h>
#include<bitset>
#include<cassert>
#include<random>
#include<time.h>
#include<functional>
using namespace std;
using ll=long long;
using ld=long double;
using pint=pair<int,int>;
using pll=pair<ll,ll>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;
	vector<ll> c(1000010, 0);
	REP(i, n) {
		ll a;
		cin >> a;
		c[a]++;
	}
	vector<vector<vector<ll>>> dp(1000010, vector<vector<ll>>(5, vector<ll>(3, 0)));
	FOR(i, 1, 1000005) REP(j, 5) REP(k, 3) {
		if(c[i] - j >= 2 && c[i + 1] - k >= 2 && c[i + 2] >= 2) {
			dp[i + 1][k + 2][2] = max(dp[i + 1][k + 2][2], dp[i][j][k] + (c[i] - j - 2) / 3 + 2);
		}
		if(c[i] - j >= 1 && c[i + 1] - k >= 1 && c[i + 2] >= 1) {
			dp[i + 1][k + 1][1] = max(dp[i + 1][k + 1][1], dp[i][j][k] + (c[i] - j - 1) / 3 + 1);
		}
		dp[i + 1][k][0] = max(dp[i + 1][k][0], dp[i][j][k] + (c[i] - j) / 3);
	}
	ll ans = 0;
	REP(i, 1000010) REP(j, 5) REP(k, 3) ans = max(ans, dp[i][j][k]);
	cout << ans << endl;
	return 0;
}

/* --------------------------------------- */