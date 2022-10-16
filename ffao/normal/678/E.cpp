#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)


int elem[51];
int mk[51];
double p[51][51];
double dp[51][51];
int n;

void solve() {
	scanf("%d", &n);
	REP(i,n) REP(j,n) scanf("%lf", &p[i][j]);

	elem[0] = 0;
	dp[0][0] = 1;
	mk[0] = 1;

	for (int ne = 1; ne < n; ne++) {
		elem[ne] = -1;
		REP(i, n) if (!mk[i]) {
			dp[ne][i] = dp[ne-1][elem[ne-1]] * p[elem[ne-1]][i] + dp[ne-1][i] * p[i][elem[ne-1]];
			if (elem[ne] == -1 || dp[ne][elem[ne]] < dp[ne][i]) elem[ne] = i;
		}

		mk[elem[ne]] = 1;
	}

	printf("%.15f\n", dp[n-1][elem[n-1]]);
}

int main() {
    solve();
}