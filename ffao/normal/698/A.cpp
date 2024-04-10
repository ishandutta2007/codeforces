#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)


int n;
int c[11000];
int dp[110][10];

int rec(int idx, int prev) {
	if (idx == n) return 0;
	
	int &ret = dp[idx][prev];
	if (ret == -1) {
		ret = n;
		for (int act = 0; act < 3; act++) {
			if ( (act&c[idx])==act && !(act&prev) ) {
				int ic = !act;
				ret = min(ret, ic+rec(idx+1, act));
			}
		}
	}
	return ret;
}

void solve() {
	memset(dp,-1,sizeof(dp));
	scanf("%d", &n);
	REP(i,n) scanf("%d", &c[i]);

	printf("%d\n", rec(0,0));	
}

int main() {
    solve();
}