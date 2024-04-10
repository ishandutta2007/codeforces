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

char a[10000];
int c[6000][6000];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N, M;
    scanf("%d%d", &N, &M);
    forn(i, N) {
        scanf("%s", a);
        int b = -1;
        forn(j, M) {
            if (a[j] == '1' && b == -1) {
                b = j;
            }
            if (a[j] == '0' && b != -1) {
                ++c[b][j];
                b = -1;
            }
        }
        if (b != -1) {
            ++c[b][M];
        }
    }
    for (int l = M - 1; l >= 1; --l) {
        for (int i = 0; i + l <= M; ++i) {
            if (i) c[i][i + l] += c[i - 1][i + l];
            if (i + l + 1 <= M) c[i][i + l] += c[i][i + l + 1];
            if (i && i + l + 1 <= M) c[i][i + l] -= c[i - 1][i + l + 1];
        }
    }

    int ans = 0;
    for (int i = 0; i <= M; ++i) {
        for (int j = i; j <= M; ++j) {
//            cout << i << ' ' << j << ' ' << c[i][j] << '\n';
            ans = max(ans, (j - i) * c[i][j]);
        }
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}