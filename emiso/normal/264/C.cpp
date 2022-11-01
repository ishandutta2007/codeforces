#include <bits/stdc++.h>

using namespace std;
typedef pair<long long, int> state;
typedef long long ll;

int n, q, v[100010], c[100010];
long long dp[100010][2], a, b;

int main() {
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    while(q--) {
        scanf("%lld %lld", &a, &b);
        int m0 = -1, m1 = -1;

        for(int i = 0; i <= n; i++)
            dp[i][0] = dp[i][1] = LLONG_MIN;

        long long ans = 0;
        for(int i = n-1; i >= 0; i--) {
            ll &x0 = dp[c[i]][0], &x1 = dp[c[i]][1], nxt = 0;

            if(x1 >= 0) nxt = x1;
            if(m0 >= 0 && c[i] != c[m0]) {
                nxt = max(nxt, dp[c[m0]][0]);
            } else if(m1 >= 0 && c[i] != c[m1]) {
                nxt = max(nxt, dp[c[m1]][0]);
            }

            { /// same = 0
                ll tmp = b * v[i] + nxt;
                if(tmp > x0) {
                    x0 = tmp;
                    if(m0 >= 0 && c[m0] == c[i]) m0 = i;
                    else if(m1 >= 0 && c[m1] == c[i]) m1 = i;
                    else if(m0 == -1) m0 = i;
                    else if(m1 == -1 || x0 > dp[c[m1]][0]) m1 = i;
                    if(m0 >= 0 && m1 >= 0 && dp[c[m0]][0] < dp[c[m1]][0]) swap(m0, m1);
                }

                if(m0 == -1) assert(m1 == -1);
                if(m0 >= 0 && m1 >= 0) {
                    assert(dp[c[m0]][0] >= dp[c[m1]][0]);
                    assert(c[m0] != c[m1]);
                }

                ans = max(ans, tmp);
            } {
                ll tmp = a * v[i] + nxt;
                x1 = max(x1, tmp);
            }
        }

        printf("%lld\n", ans);
    }

    return 0;
}