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
#define MOD 998244353LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

ll calc(string str, char c) {
	ll tmp = 0, ret = 0;
	REP(i, str.length()) {
		if(str[i] == c) tmp++;
		else tmp = 0;
		ret = max(ret, tmp);
	}
	return ret;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	vector<string> p(n);
	REP(i, n) cin >> p[i];
	vector<vector<ll>> dp(n, vector<ll>(26, 0));
	REP(i, 26) dp[0][i] = calc(p[0], 'a' + i);
	FOR(i, 1, n) REP(j, 26) {
		dp[i][j] = calc(p[i], 'a' + j);
		if(dp[i - 1][j]) dp[i][j] = max(dp[i][j], 1ll);
		if(p[i][0] != 'a' + j && p[i][(ll)p[i].length() - 1] != 'a' + j) continue;
		if(calc(p[i], 'a' + j) == (ll)p[i].length()) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j] + (dp[i - 1][j] + 1) * (ll)p[i].length());
		} else {
			ll tmp = 0;
			REP(k, p[i].length()) {
				if(p[i][k] == 'a' + j) tmp++;
				else break;
			}
			for(ll k = p[i].length() - 1; k >= 0; k--) {
				if(p[i][k] == 'a' + j) tmp++;
				else break;
			}
			if(dp[i - 1][j]) dp[i][j] = max(dp[i][j], tmp + 1);
		}
	}
	ll ans = 0;
	REP(i, 26) ans = max(ans, dp[n - 1][i]);
	cout << ans << endl;
	return 0;
}

/* --------------------------------------- */