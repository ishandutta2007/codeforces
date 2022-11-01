#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, m, dp[MN][2], st[110][110], lst[110], fst[110];
char s[MN]; string str;

int main() {
    scanf("%d %d", &n, &m);

    for(int i=n-1; i>=0; i--) {
        scanf(" %s", s);
        fst[i] = 999, lst[i] = -1;
        for(int j=0; j< m + 2; j++) {
            st[i][j] = s[j];
            if(s[j] == '1') {
                fst[i] = min(fst[i], j);
                lst[i] = max(lst[i], j);
            }
        }
    }

    dp[n-1][0] = dp[n-1][1] = 0;
    if(lst[n-1] != -1) {
        dp[n-1][0] = lst[n-1];
        dp[n-1][1] = (m + 1) - fst[n-1];
    }

    for(int i = n-2; i >= 0; i--) {
        if(dp[i+1][0]) dp[i][0] = dp[i+1][0] + 1;
        if(dp[i+1][1]) dp[i][1] = dp[i+1][1] + 1;

        if(lst[i] != -1) {
            if(dp[i+1][0]) {
                dp[i][0] = 2 * lst[i] + dp[i+1][0] + 1;
                dp[i][0] = min(dp[i][0], m + 1 + dp[i+1][1] + 1);

                dp[i][1] = 2 * ((m + 1) - fst[i]) + dp[i+1][1] + 1;
                dp[i][1] = min(dp[i][1], m + 1 + dp[i+1][0] + 1);
            }
            else {
                dp[i][0] = lst[i];
                dp[i][1] = (m + 1) - fst[i];
            }
        }


    }

    printf("%d\n",dp[0][0]);
    return 0;
}