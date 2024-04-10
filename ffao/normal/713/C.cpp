#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
 

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)


int n;
int a[3100];
int b[3100];

long long dp[3100][3100];

void solve() {
	scanf("%d", &n);
	REP(i,n) scanf("%d", &a[i]);

	REP(i,n) b[i] = a[i]-i;
	sort(b,b+n);

	for (int idx = n-1; idx >= 0; idx--) {
		for (int val = n-1; val >= 0; val--) {
			dp[idx][val] = abs( a[idx] - (b[val] + idx) ) + dp[idx+1][val];
			if (val < n-1) dp[idx][val] = min(dp[idx][val], dp[idx][val+1]);
		}
	}

	printf("%lld\n", dp[0][0]);
}


int main() {
    solve();
}