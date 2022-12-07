#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int h, w;
char s[505][505];
int hor[505][505] = {};
int ver[505][505] = {};

int main() {
    scanf("%d%d", &h, &w);
    REP(i, h) scanf("%s", s[i]);
    REP(i, h) REP(j, w - 1) {
        if (s[i][j] == '.' && s[i][j + 1] == '.') hor[i + 1][j + 1] = 1;
    }
    REP(i, h - 1) REP(j, w) {
        if (s[i][j] == '.' && s[i + 1][j] == '.') ver[i + 1][j + 1] = 1;
    }
    for (int i = 1; i <= h; ++i) for (int j = 1; j <= w; ++j) {
        hor[i][j] += hor[i - 1][j] + hor[i][j - 1] - hor[i - 1][j - 1];
        ver[i][j] += ver[i - 1][j] + ver[i][j - 1] - ver[i - 1][j - 1];
    }
    int q;
    scanf("%d", &q);
    REP(i, q) {
        int y, x, yy, xx;
        scanf("%d%d%d%d", &y, &x, &yy, &xx);
        int ans = hor[yy][xx - 1] - hor[y - 1][xx - 1] - hor[yy][x - 1] + hor[y - 1][x - 1];
        ans += ver[yy - 1][xx] - ver[y - 1][xx] - ver[yy - 1][x - 1] + ver[y - 1][x - 1];
        printf("%d\n", ans);
    }
    return 0;
}