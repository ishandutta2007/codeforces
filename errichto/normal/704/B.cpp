#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const ll INF = 2e18L;
const int nax = 5015;

ll x[nax], a[nax], b[nax], c[nax], d[nax];

ll dp[nax], old[nax];

int main() {
	int n, s, e;
	scanf("%d%d%d", &n, &s, &e);
	RI(i, n) scanf("%lld", &x[i]);
	RI(i, n) scanf("%lld", &a[i]);
	RI(i, n) scanf("%lld", &b[i]);
	RI(i, n) scanf("%lld", &c[i]);
	RI(i, n) scanf("%lld", &d[i]);
	if(s > e) {
		cerr << "cerr swap\n";
		swap(s, e);
		swap(a, c);
		swap(b, d);
	}
	REP(i, nax) dp[i] = INF;
	dp[0] = 0;
	x[0] = x[1];
	RI(i, n) {
		FOR(j, 0, n) {
			int tmp = 2 * j;
			if(s < i && i <= e) ++tmp;
			old[j] = dp[j] + (ll) tmp * (x[i] - x[i-1]);
			dp[j] = INF;
		}
		if(i != 1 && !(s < i && i <= e)) old[0] = INF;
		FOR(j, 0, n) {
			ll me = old[j];
			if(i == s) {
				if(j) mini(dp[j-1], me + c[i]);
				mini(dp[j], me + d[i]);
			}
			else if(i == e) {
				mini(dp[j], me + a[i]);
				mini(dp[j+1], me + b[i]);
			}
			else {
				mini(dp[j], me + a[i] + d[i]);
				if(! (j == 0 && (s < i && i < e)))
					mini(dp[j], me + b[i] + c[i]);
				if(j) mini(dp[j-1], me + a[i] + c[i]);
				mini(dp[j+1], me + b[i] + d[i]);
			}
		}
	}
	printf("%lld\n", dp[0]);
	return 0;
}