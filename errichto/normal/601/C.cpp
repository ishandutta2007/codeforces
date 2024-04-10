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
const int nax = 1e5 + 5;

ld dp[105][nax];
ld pre[105][nax];

int main() {
	int dyscy, oni;
	scanf("%d%d", &dyscy, &oni);
	if(oni == 1) {
		puts("1");
		return 0;
	}
	dp[0][0] = 1;
	REP(i, nax) pre[0][i] = 1;
	int total = 0;
	RI(dy, dyscy) {
		int ja;
		scanf("%d", &ja);
		total += ja;
		FOR(i, 1, dyscy * oni) {
			dp[dy][i] = pre[dy-1][i-1];
			if(i-oni-1 >= 0) dp[dy][i] -= pre[dy-1][i-oni-1];
			if(i - ja >= 0) dp[dy][i] -= dp[dy-1][i-ja];
			dp[dy][i] /= oni - 1;
			pre[dy][i] = dp[dy][i] + pre[dy][i-1];
		}
	}
	ld ans = 0;
	FOR(i, 0, total - 1) ans += dp[dyscy][i];
	printf("%.11lf\n", 1 + (double) ans * (oni - 1));
	return 0;
}