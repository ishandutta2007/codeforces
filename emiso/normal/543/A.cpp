#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int dp[505][505], dp2[505][505];
int n, m, b, MOD, a[505];

inline int add(int a, int b) {
    int ret = a + b;
    if(ret >= MOD) ret -= MOD;
    return ret;
}

int main() {
	scanf("%d %d %d %d", &n, &m, &b, &MOD);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	dp[0][0] = 1;
	for(int i = 0; i < n; i++)
		for(int M = 1; M <= m; M++)
            for(int B = a[i]; B <= b; B++)
                dp[M][B] = add(dp[M][B], dp[M-1][B - a[i]]);

	int ans = 0;
	for(int qb = 0; qb <= b; qb++) {
		ans += dp[m][qb];
		if(ans >= MOD) ans -= MOD;
	}
	printf("%d\n", ans);
	return 0;
}