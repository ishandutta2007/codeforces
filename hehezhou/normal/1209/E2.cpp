#include <bits/stdc++.h>
using namespace std;
int dp[2100][4100];
int n, m, t;
struct node {
    int a[20], c;
    inline int init(int *x) {
        c = 0;
        for(int i = 1; i <= n; i++) a[i] = x[i], c = max(c, a[i]);
    }
    inline int operator < (const node &b) const {
        return c > b.c;
    }
    inline void out(int *x) {
        for(int i = 1; i <= n; i++) x[i] = a[i];
    }
} nd[2100];
int tmp[4100];
int lg2[4100];
int a[2100][2100];
int now[20];
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++) scanf("%d", a[j] + i);
        for(int i = 1; i <= m; i++) nd[i].init(a[i]);
        sort(nd + 1, nd + 1 + m);
        for(int i = 0; i < n; i++) lg2[1 << i] = i;
        int all = (1 << n) - 1;
        for(int i = 1; i <= min(n, m); i++) {
            nd[i].out(now - 1);
            for(int s = 0; s <= all; s++) {
                tmp[s] = 0;
                for(int d = 0; d < n; d++) {
                    int sum = 0, tt = s;
                    while(tt) {
                        sum += now[(d + lg2[tt & -tt]) % n];
                        tt -= tt & -tt;
                    }
                    tmp[s] = max(tmp[s], sum);
                }
            }
            for(int S = 0; S <= all; S++) {
                dp[i][S] = 0;
                for(int s = S; ; s = (s - 1) & S) {
                    dp[i][S] = max(dp[i][S], dp[i - 1][s] + tmp[S ^ s]);
                    if(s == 0) break;
                }
                // cerr << i << ' ' << S << ' ' << dp[i][S] << endl;
            }
        }
        printf("%d\n", dp[min(n, m)][all]);
    }
}