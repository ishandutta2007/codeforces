#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int m, di;
char buf[2005];
int a[2000], b[2000];
int d[2][2][2001][2000];
const int MOD = 1e9 + 7;

inline void modAdd(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

int main() {
    scanf("%d%d", &m, &di);
    scanf("%s", buf);
    int n = strlen(buf);
    REP(i, n) a[i] = buf[i] - '0';
    scanf("%s", buf);
    REP(i, n) b[i] = buf[i] - '0';
    d[0][0][0][0] = 1;
    REP(p, 2) REP(q, 2) REP(i, n) REP(j, m) if (d[p][q][i][j]) {
        int mn = 0, mx = 9;
        int forb = di;
        if (i & 1) {
            mn = mx = di;
            forb = -1;
        }
        for (int dig = mn; dig <= mx; ++dig) {
            if (dig == forb) continue;
            if (!p && dig < a[i]) continue;
            if (!q && dig > b[i]) continue;
            int np = p || dig > a[i];
            int nq = q || dig < b[i];
            int nj = (10 * j + dig) % m;
            modAdd(d[np][nq][i + 1][nj], d[p][q][i][j]);
        }
    }
    int ans = 0;
    REP(i, 2) REP(j, 2) modAdd(ans, d[i][j][n][0]);
    printf("%d\n", ans);
    return 0;
}