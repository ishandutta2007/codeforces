#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, q, c;
int a[11][101][101] = {};

int main() {
    scanf("%d%d%d", &n, &q, &c);
    ++c;
    forn(i, n) {
        int x, y, s;
        scanf("%d%d%d", &x, &y, &s);
        ++a[s][x][y];
    }
    forn(i, c) for (int j = 1; j <= 100; ++j) for (int k = 1; k <= 100; ++k) {
        a[i][j][k] += a[i][j - 1][k] + a[i][j][k - 1] - a[i][j - 1][k - 1];
    }
    forn(_, q) {
        int t, x, y, xx, yy;
        scanf("%d%d%d%d%d", &t, &x, &y, &xx, &yy);
        int ans = 0;
        forn(i, c) {
            int sum = a[i][xx][yy] - a[i][x - 1][yy] - a[i][xx][y - 1] + a[i][x - 1][y - 1];
            int mul = (i + t) % c;
            ans += sum * mul;
        }
        printf("%d\n", ans);
    }
    return 0;
}