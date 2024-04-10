#include <bits/stdc++.h>

#define MN 1010
#define w1 while(1)

#define getstr scanf("%s", s);
#define MOD 1000000007

using namespace std;
typedef long long ll;

int n, a[MN], st[MN], acum[MN][26], mx = -1;
ll dp[1010];
char s[MN];

ll solve(int cut) {
    if(cut == n) return 1;

    if(cut > n) return 0;

    if(dp[cut] != -1)
        return dp[cut];

    bool flag = 1;
    ll x = 0;
    int pos = cut;

    while(flag && pos < n) {
        if(pos == n) break;
        for(int i = 0; i < 26; i++) {
            if(acum[pos][i] - (cut ? acum[cut-1][i] : 0)
               && (pos - cut + 1 > a[i])) {
                flag = 0;
            }

        }
        if(!flag) break;
        mx = max(mx, pos - cut + 1);
        x = (x + solve(pos + 1)) % MOD;
        pos++;
    }
    //if(pos == n) x++;

    return dp[cut] = x;

} ///MOD

int main() {
    scanf("%d ", &n);
    getstr;
    memset(dp, -1, sizeof dp);

    for(int i = 0; i < 26; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++) {
        st[i] = a[s[i] - 'a'];

        for(int c = 0; c < 26; c++) {
            if(i) acum[i][c] = acum[i-1][c];
            acum[i][c] += ((s[i] - 'a') == c);
        }
    }
    solve(0);

    int mn = 1, cut = 0;
    for(int pos=0;pos<n;pos++) {
        int flag = 1;
        for(int i = 0; i < 26; i++) {
            if(acum[pos][i] - (cut ? acum[cut-1][i] : 0)
               && (pos - cut + 1 > a[i])) {
                flag = 0;
            }
        }
        if(!flag) {
            mn++;
            cut = pos;
        }
    }

    printf("%lld\n%d\n%d", dp[0], mx, mn);
    return 0;
}