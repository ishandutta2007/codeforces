#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
char s[500][505];
int a[500][500];
const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};
int cnt[250001] = {};
bool was[250001] = {};

int cm;
void dfs(int y, int x) {
    a[y][x] = cm;
    REP(i, 4) {
        int yy = y + dy[i];
        int xx = x + dx[i];
        if (yy < 0 || yy >= n || xx < 0 || xx >= n) continue;
        if (a[yy][xx] == -1) {
            dfs(yy, xx);
        }
    }
}

int cur = 0;
inline void mark(int x) {
    if (!was[x]) {
        was[x] = true;
        cur += cnt[x];
    }
}

int main() {
    scanf("%d%d", &n, &k);
    REP(i, n) scanf("%s", s[i]);
    REP(i, n) REP(j, n) {
        a[i][j] = s[i][j] == '.' ? -1 : -2;
    }
    cm = 0;
    REP(i, n) REP(j, n) if (a[i][j] == -1) {
        dfs(i, j);
        ++cm;
    }
    REP(i, n) REP(j, n) if (a[i][j] == -2) {
        a[i][j] = cm;
    }
    REP(i, n) REP(j, n) ++cnt[a[i][j]];
    int ans = 0;
    REP(p, n - k + 1) {
        REP(i, k) REP(j, k) --cnt[a[p + i][j]];
        REP(q, n - k + 1) {
            cur = 0;
            was[cm] = true;
            if (p != 0) REP(i, k) mark(a[p - 1][q + i]);
            if (p != n - k) REP(i, k) mark(a[p + k][q + i]);
            if (q != 0) REP(i, k) mark(a[p + i][q - 1]);
            if (q != n - k) REP(i, k) mark(a[p + i][q + k]);

            ans = max(ans, cur);

            if (p != 0) REP(i, k) was[a[p - 1][q + i]] = false;
            if (p != n - k) REP(i, k) was[a[p + k][q + i]] = false;
            if (q != 0) REP(i, k) was[a[p + i][q - 1]] = false;
            if (q != n - k) REP(i, k) was[a[p + i][q + k]] = false;

            if (q == n - k) break;
            REP(i, k) ++cnt[a[p + i][q]];
            REP(i, k) --cnt[a[p + i][q + k]];
        }
        REP(i, k) REP(j, k) ++cnt[a[p + i][n - 1 - j]];
    }
    printf("%d\n", ans + k * k);
    return 0;
}