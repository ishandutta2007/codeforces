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

const int maxn = 1000002;

vi e[maxn];
int d[20][maxn];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    ios::sync_with_stdio(false);
    int N;
    scanf("%d", &N);
    forn(i, N) {
        int j;
        scanf("%d", &j);
        --j;
        e[j].pb(i + 1);
    }
    forn(i, 20) forn(j, N + 2) d[i][j] = N + 2;
    for (int i = N; i > 0; --i) {
        d[0][i] = i;
        for (int j = 1; j < 20; ++j) {
            int m11 = N + 1, m12 = N + 1, m21 = N + 1, m22 = N + 1;
            forn(x, e[i].size()) {
                int u = e[i][x];
                d[j][i] = min(d[j][i], d[j][u]);
                if (d[j - 1][u] < d[j - 1][m11]) {
                    m12 = m11;
                    m11 = u;
                } else if (d[j - 1][u] < d[j - 1][m12]) {
                    m12 = u;
                }
/*                if (d[j - 2][u] < d[j - 2][m21]) {
                    m22 = m21;
                    m21 = u;
                } else if (d[j - 2][u] < d[j - 2][m22]) {
                    m22 = u;
                }*/
            }
//            d[j][i] = min(d[j][i], max(d[j - 1][m11], m21 == m11 ? d[j - 2][m22] : d[j - 2][m21]));
//'            d[j][i] = min(d[j][i], max(d[j - 2][m21], m11 == m21 ? d[j - 1][m12] : d[j - 1][m11]));
            d[j][i] = min(d[j][i], d[j - 1][m12]);
        }
    }
    vector<int> ans(20, N + 2);
    forn(i, e[0].size()) {
        int u = e[0][i];
        forn(j, 20) ans[j] = min(ans[j], d[j][u]);
    }
    int x = 0;
    forn(i, N) {
        while (i + 1 >= ans[x]) ++x;
        printf("%d ", x);
    }
    printf("\n");

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}