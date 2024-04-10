#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int tt, n, k;
char s[3][111];

bool isTrain(char c) {
    return c >= 'A' && c <= 'Z';
}

int mx;

void dfs(int y, int x) {
    mx = max(mx, x);
    if (x > 105) return;
    s[y][x] = 's';
    if (isTrain(s[y][x + 1])) return;
    if (s[y][x + 3] == '.') {
        if (!isTrain(s[y][x + 2])) {
            dfs(y, x + 3);
        }
    }
    if (y > 0 && s[y - 1][x + 3] == '.') {
        if (!isTrain(s[y - 1][x + 1]) && !isTrain(s[y - 1][x + 2])) {
            dfs(y - 1, x + 3);
        }
    }
    if (y < 2 && s[y + 1][x + 3] == '.') {
        if (!isTrain(s[y + 1][x + 1]) && !isTrain(s[y + 1][x + 2])) {
            dfs(y + 1, x + 3);
        }
    }
}

int main() {
    scanf("%d", &tt);
    REP(test, tt) {
        scanf("%d%d", &n, &k);
        REP(i, 3) scanf("%s", s[i]);
        REP(i, 3) for (int j = n; j < 111; ++j) {
            s[i][j] = '.';
        }
        mx = 0;
        REP(i, 3) if (s[i][0] == 's') {
            dfs(i, 0);
        }
        if (mx > 100) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}