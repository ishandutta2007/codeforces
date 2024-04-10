#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<math.h>
#include<functional>
#include<bitset>
#include<cassert>
using namespace std;
using lint = long long;
using ld = long double;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
#define MOD 998244353LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(lint i=n;i<(int)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

lint _pow(lint a, lint n) {
	if(n==0) return 1;
	else {
		lint res = 1;
		lint buf = a;
		while(n>0) {
			if(n%2==1) {
				res *= buf;
				res %= MOD;
			}
			buf *= buf;
			buf %= MOD;
			n/=2;
		}
		return res;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> c(n + 10, 0);
	REP(i, n) {
		int a;
		cin >> a;
		c[a]++;
	}
	lint ans = 0;
	vector<lint> dp(n + 10, 0);
	dp[0] = 1;
	vector<lint> rev(n + 10);
	REP(i, n + 10) rev[i] = _pow(i, MOD - 2);
	REP(i, n + 10) {
		if(c[i] == 0) continue;
		if(c[i] >= 2) {
			REP(j, n + 10) {
				lint p = dp[j];
				p *= c[i]; p %= MOD;
				p *= c[i] - 1; p %= MOD;
				p *= rev[n - j]; p %= MOD;
				p *= rev[n - j - 1]; p %= MOD;
				ans += p; ans %= MOD;
			}
		}
		vector<lint> ndp(n + 10, 0);
		REP(j, n + 10) ndp[j] += dp[j];
		FOR(j, 1, n + 10) {
			lint p = dp[j - 1];
			p *= c[i]; p %= MOD;
			p *= rev[n - j + 1]; p %= MOD;
			ndp[j] += p;
			ndp[j] %= MOD;
		}
		dp = ndp;
	}
	cout << ans << endl;
	return 0;
}
/* --------------------------------------- */