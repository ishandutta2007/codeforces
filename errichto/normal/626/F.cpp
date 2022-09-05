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
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;
const int mod = 1e9 + 7;

int t[nax];
int dp[2][205][2005]; // how many open; cost so far

void add(int & a, int b) {
	a += b;
	if(a >= mod) a -= mod;
}
int mul(int a, int b) {
	return (ll) a * b % mod;
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	RI(i, n) scanf("%d", &t[i]);
	sort(t + 1, t + n + 1);
	int which = 0;
	dp[which][0][0] = 1;
	RI(iii, n) {
		assert(which == 0);
		if(iii > 1) {
			// take from which^1
			FOR(open, 0, 100) FOR(cost, 0, 1000)
				dp[which][open][cost] = 0;
			int diff = t[iii] - t[iii-1];
			FOR(open, 0, 100) FOR(cost, 0, 1000) {
				if(cost + diff * open > k) break;
				//assert(open == 0 && cost == 0);
				//printf("%d\n", dp[which^1][open][cost]);
				dp[which][open][cost + diff*open] = dp[which^1][open][cost];
			}
			FOR(open, 0, 100) FOR(cost, 0, 1000)
				dp[which^1][open][cost] = 0;
				
		}
		FOR(open, 0, 100) FOR(cost, 0, 1000) if(dp[which][open][cost]) {
			int x = dp[which][open][cost];
			add(dp[which^1][open][cost], x); // one-person group
			add(dp[which^1][open+1][cost], x);
			if(open > 0) {
				int tmp = mul(open, x);
				add(dp[which^1][open-1][cost], tmp);
				add(dp[which^1][open][cost], tmp);
			}
		}
		//if(iii == 2) printf("> %d\n", dp[which^1][1][1]);
	}
	which ^= 1;
	//FOR(z,0,5) printf("%d: %d\n", z, dp[which][0][z]);
	int ans = 0;
	FOR(cost, 0, k) add(ans, dp[which][0][cost]);
	printf("%d\n", ans);
	return 0;
}