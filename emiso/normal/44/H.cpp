#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN], dp[55][11][2];
char s[MN]; string str;

ll solve(int i, int last, int dif) {
    dif |= (last != str[i-1] - '0');
    if(i == n) return dif;
    ll &x = dp[i][last][dif];
    if(x != -1) return x;

    int sum = last + (str[i] - '0');
    x = solve(i + 1, sum / 2, dif);
    if(sum & 1) x += solve(i + 1, sum / 2 + 1, dif);

    return x;
}

int main() {
    scanf("%s", s);
    str = s; n = str.size();

    memset(dp, -1, sizeof dp);
    for(int i = 0; i <= 9; i++)
        ans += solve(1, i, 0);

    printf("%lld\n", ans);
    return 0;
}