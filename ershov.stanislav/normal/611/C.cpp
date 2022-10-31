#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 100;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int maxn = 550;

int h, w;
char s[maxn][maxn];
pair<int, int> dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int can[4][maxn][maxn];

bool ok(int i, int j) {
    return i >= 0 && i < h && j >= 0 && j < w;
}

int main() {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%d%d", &h, &w);
    for (int i = 0; i < h; i++) {
        scanf(" %s", s[i]);
    }
    for (int t = 0; t < 4; t++) {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                int ni = i + dir[t].fs;
                int nj = j + dir[t].sc;
                if (s[i][j] == '.' && ok(ni, nj) && s[ni][nj] == '.') {
                    can[t][i + 1][j + 1] = 1;
                }
                can[t][i + 1][j + 1] += can[t][i + 1][j] + can[t][i][j + 1] - can[t][i][j];
            }
        }
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int r1, c1, r2, c2;
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
        int ans = 0;
        for (int t = 0; t < 4; t++) {
            int nr1 = max(r1, r1 - dir[t].fs);
            int nr2 = min(r2, r2 - dir[t].fs);
            int nc1 = max(c1, c1 - dir[t].sc);
            int nc2 = min(c2, c2 - dir[t].sc);
            ans += can[t][nr2][nc2] - can[t][nr1 - 1][nc2] - can[t][nr2][nc1 - 1] + can[t][nr1 - 1][nc1 - 1];
        }
        assert(ans % 2 == 0);
        printf("%d\n", ans / 2);
    }
    return 0;
}