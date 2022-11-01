#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vector<ll> a(n);
	REP(i,n) cin >> a[i];
	const ll modulo = 998244353LL;
	vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(2, vector<ll>(201, 0)));
	vector<ll> acm0(201,0);
	vector<ll> acm1(201,0);
	REP(i,n) {
		REP(j,2) FOR(k,1,201) {
			if(a[i] != -1 && a[i] != k) continue;
			if(i == 0) {
				if(j == 1) continue;
				dp[i][j][k] = 1;
			} else {
				if(j == 0) {
					dp[i][j][k] += acm0[k - 1];
					dp[i][j][k] += acm1[k - 1];
				} else {
					dp[i][j][k] += acm0[k] - acm0[k - 1];
					dp[i][j][k] += acm1[200] - acm1[k - 1];
				}
			}
			dp[i][j][k] %= modulo;
		}
		acm0[0] = 0;
		acm1[0] = 0;
		FOR(j,1,201) {
			acm0[j] = acm0[j - 1] + dp[i][0][j];
			acm1[j] = acm1[j - 1] + dp[i][1][j];
			acm0[j] %= modulo;
			acm1[j] %= modulo;
		}
	}
	ll ans = 0;
	FOR(i,1,201) ans += dp[n - 1][1][i];
	cout << (ans % modulo + modulo) % modulo << endl;
	return 0;
}