#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
char s[55][55];
char op[111];

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int a[4];

int main() {
    scanf("%d%d", &n, &m);
    forn(i, n) scanf("%s", s[i]);
    scanf("%s", op);
    int len = strlen(op);
    forn(i, 4) a[i] = i;
    int sx = 0, sy = 0;
    forn(i, n) forn(j, m) if (s[i][j] == 'S') {
        sx = i;
        sy = j;
    }
    int ans = 0;
    do {
        int x = sx;
        int y = sy;
        forn(i, len) {
            int dir = a[op[i] - '0'];
            x += dx[dir];
            y += dy[dir];
            if (x < 0 || x >= n) break;
            if (y < 0 || y >= m) break;
            if (s[x][y] == '#') break;
            if (s[x][y] == 'E') break;
        }
        if (x >= 0 && x < n && y >= 0 && y < m && s[x][y] == 'E') {
            ++ans;
        }
    } while (next_permutation(a, a + 4));
    cout << ans << endl;
    return 0;
}