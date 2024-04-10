#include <bits/stdc++.h>

 
using namespace std;


#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int n,k;
int last[300];
char t[1100000];
int dp[3100000];
const int mod = 1000000007;

void solve() {
	scanf("%d %d", &n, &k);
	scanf("%s", t);

	dp[0] = 1;
	int m = 0;
	for (int i = 0; t[i]!='\0'; i++) {
		int tc = t[i];
		if (last[tc] == 0) dp[i+1] = (dp[i]*2)%mod; 
		else dp[i+1] = (((dp[i]*2 - dp[last[tc]-1]) % mod) + mod) % mod;
		last[tc] = i+1;
		m++;
	}

	REP(i, n) {
		int best = 'a';
		for (int p = 'a'; p < 'a'+k; p++) {
			if (last[p] < last[best]) {
				best = p;
			}
		}

		if (last[best] == 0) dp[i+m+1] = (dp[i+m]*2)%mod;
		else dp[i+m+1] = (((dp[i+m]*2 - dp[last[best]-1]) % mod) + mod) % mod;
		last[best] = i+m+1;
	}

	printf("%d\n", dp[n+m]);
}

int main() {
    solve();
}


#include <vector>