#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int d, n, m;
PII z[200000];
int x[200000], p[18][200000];
int sz[200001];

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &d, &n, &m);
    REP(i, m) scanf("%d%d", &z[i].first, &z[i].second);
    sort(z, z + m);
    REP(i, m) x[i] = z[i].first, p[0][i] = z[i].second;
    REP(i, 17) REP(j, m - (2 << i) + 1) {
        p[i + 1][j] = min(p[i][j], p[i][j + (1 << i)]);
    }
    int cur = 0;
    for (int i = 1; i <= m; ++i) {
        while ((2 << cur) < i) ++cur;
        sz[i] = cur;
    }
    d -= n;
    int i = 0, j = lower_bound(x, x + m, n + 1) - x;
    LL ans = 0;
    for (int pos = 0; pos < d; ) {
        if (i == j) {
            printf("-1\n");
            return 0;
        }
        int upto = d;
        if (j < m) upto = min(upto, x[j] - n);
        upto = min(upto, x[i]);
        int s = sz[j - i];
        int best = min(p[s][i], p[s][j - (1 << s)]);
        ans += (LL)best * (upto - pos);
        pos = upto;
        while (i < m && pos == x[i]) ++i;
        while (j < m && pos == x[j] - n) ++j;
    }
    cout << ans << endl;
    return 0;
}