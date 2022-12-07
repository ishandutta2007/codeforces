#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k, s;
int a[150];
int d[151][12001];
const int INF = 1e9;

int main() {
    scanf("%d%d%d", &n, &k, &s);
    REP(i, n) scanf("%d", a + i);
    s = min(s, 12000);
    REP(i, k + 1) REP(j, s + 1) d[i][j] = INF;
    d[0][0] = 0;
    REP(i, n) {
        for (int j = min(i, k - 1); j >= 0; --j) {
            int mx = s + 1 - i + j;
            int dif = i - j;
            REP(p, mx) {
                d[j + 1][p + dif] = min(d[j + 1][p + dif], d[j][p] + a[i]);
            }
        }
    }
    int ans = INF;
    REP(i, s + 1) ans = min(ans, d[k][i]);
    printf("%d\n", ans);
    return 0;
}