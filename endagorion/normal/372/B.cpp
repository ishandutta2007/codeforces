#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

char f[50][50];

int s[50][50];
int d[50][50][50][50];

int get(int lx, int rx, int ly, int ry) {
    if (lx >= rx || ly >= ry) {
        return 0;
    }                         
    int &res = d[lx][rx][ly][ry];
    if (res >= 0) {
        return res;
    }
    res = (s[rx][ry] - s[lx][ry] - s[rx][ly] + s[lx][ly] == 0) ? 1 : 0;
    forn(slx, 2) forn(srx, 2) forn(sly, 2) forn(sry, 2) {
        if (slx + srx + sly + sry == 0) {
            continue;
        }
        int m[5] = {0, 1, -1, 1, -1};
        res += get(lx + slx, rx - srx, ly + sly, ry - sry) * m[slx + srx + sly + sry];
    }
//    cerr << lx << ' ' << rx << ' ' << ly << ' ' << ry << ' ' << res << '\n';
    return res;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N, M, Q;
    scanf("%d%d%d", &N, &M, &Q);
    for (int i = 0; i < N; ++i) {
        scanf("%s", f[i]);
    }
    forn(i, N) forn(j, M) {
        s[i + 1][j + 1] = (f[i][j] - '0') + s[i + 1][j] + s[i][j + 1] - s[i][j];
    }
    forn(i, N + 1) forn(j, N + 1) forn(k, M + 1) forn(l, M + 1) d[i][j][k][l] = -1;
    forn(i, Q) {
        int lx, ly, rx, ry;
        scanf("%d%d%d%d", &lx, &ly, &rx, &ry);
        --lx; --ly;
        printf("%d\n", get(lx, rx, ly, ry));
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}