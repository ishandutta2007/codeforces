#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
using namespace std;
#define FOR(i,a,n) for(int i=(a),_n=(n); i <= _n; ++i)
#define FORD(i,a,n) for(int i=(a),_n=(n); i >= _n; --i)
#define REP(i,n) FOR(i,0,(n)-1)
#define RI(i,n) FOR(i,1,(n))
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#ifdef LOCAL
#define deb(x) { cerr << #x << " = " << x << "\n"; }
#else
#define deb(x)
#define cerr if(false) cout
#endif
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5, nax = 505;

int licz[nax];
ll dp[nax][nax];

int main()
{
	int n, m;
	ll mod;
	scanf("%d%d%lld", &n, &m, &mod);
	deb(n);
	cerr << "dupa";
	REP(_, m) {
		char s[nax];
		scanf("%s", s);
		REP(i, n) if(s[i] == '1') licz[i]++;
	}
	{
		int jed = 0, dwa = 0;
		REP(i, n) {
			if(licz[i] == 1) jed++;
			if(licz[i] == 0) dwa++;
		}
		dp[jed][dwa] = 1;
	}
	FOR(row, m + 1, n) {
		REP(jed, n + 2) if(jed % 2 == 0) {
			int dwa = n - row + 1 - jed / 2;
			if(dwa >= 0 && dp[jed][dwa]) {
				dp[jed][dwa] %= mod;
				if(jed >= 2) dp[jed-2][dwa] += dp[jed][dwa] * jed * (jed-1LL) / 2LL;
				if(jed >= 1 && dwa >= 1) dp[jed][dwa-1] += dp[jed][dwa] * jed * dwa;
				if(dwa >= 2) dp[jed + 2][dwa - 2] += dp[jed][dwa] * dwa * (dwa-1LL) / 2LL;
			}
		}
	}
	printf("%lld\n", dp[0][0] % mod);
	return 0;
}