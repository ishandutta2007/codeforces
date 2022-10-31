#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, k, dp[10][2][1<<10], p10[11];
string str; char s[110];

ll solve(int i, int greater, int mask) {
	if(__builtin_popcount(mask) > k) return INT_MAX;
	if(i == str.size()) return 0;
	ll &x = dp[i][greater][mask];
	if(x != -1) return x;
	x = INT_MAX;
	for(int j = greater ? 0 : (str[i] - '0'); j <= 9; j++) {
		x = min(x, p10[str.size()-i-1]*j + solve(i + 1, greater|(j>str[i]-'0'), mask | (1 << j)));
		if(x < INT_MAX) break;
	}
	return x;
}

int main() {
	p10[0] = 1; for(int i = 1; i <= 10; i++) p10[i] = 10LL * p10[i-1];
    scanf("%lld", &t);
    st:
    scanf("%s %lld", &s, &k); str = s;
    memset(dp, -1, sizeof dp);
    printf("%lld\n", solve(0, 0, 0));
    if(--t) goto st;
    return 0;
}