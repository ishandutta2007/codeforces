#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

int dp[110][2][2], n;
char s[MN]; string str1, str2;

int solve(int p, int o1, int o2) {
    if(p == n) return 0;
    if(dp[p][o1][o2] != -1) return dp[p][o1][o2];

    int ret = solve(p + 1, str1[p+1] == 'X', str2[p+1] == 'X');

    if((!o1 || !o2) && str1[p+1] == '0' && str2[p+1] == '0')
        ret = max(ret, solve(p + 1, 1, 1) + 1);

    if(!o1 && !o2 && str1[p+1] == '0')
        ret = max(ret, solve(p + 1, 1, str2[p+1] == 'X') + 1);

    if(!o1 && !o2 && str2[p+1] == '0')
        ret = max(ret, solve(p + 1, str1[p+1] == 'X', 1) + 1);

    return dp[p][o1][o2] = ret;
}

int main() {
    scanf("%s", s); str1 = s; n = str1.size();
    scanf("%s", s); str2 = s;
    str1 += 'X'; str2 += 'X';

    memset(dp, -1, sizeof dp);

    printf("%d\n", solve(0, str1[0] == 'X', str2[0] == 'X'));
    return 0;
}