#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cassert>
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

const int maxk = 50;
const int maxn = 4 * maxk + 2;
i64 f[maxk + 1];
int e[maxn][maxn];

void addEdge(int x, int y) {
    e[x][y] = e[y][x] = 1;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int K;
    cin >> K;
    f[0] = 1;
    f[1] = 2;
    for (int i = 2; i < maxk; ++i) {
        f[i] = f[i - 1] + f[i - 2];
    }
//    e[0][2] = e[0][3] = 1;
    addEdge(0, 2);
    addEdge(0, 3);
    addEdge(1, 4);
    for (int i = 1; i < maxk; ++i) {
//        e[2 * i + 2][2 * i] = e[2 * i + 2][2 * i + 1] = 1;
        addEdge(3 * i + 2, 3 * (i - 1) + 2);
        addEdge(3 * i + 2, 3 * (i - 1) + 3);
//        e[2 * i + 3][2 * i] = 1;
        addEdge(3 * i + 3, 3 * (i - 1) + 2);

        addEdge(3 * i + 4, 3 * (i - 1) + 4);
    }
    for (int i = maxk - 1; i >= 0; --i) {
        if (K >= f[i]) {
//            e[1][2 * i + 2] = 1;
            addEdge(3 * (maxk - i - 1) + 4, 3 * i + 2);
            K -= f[i];
        }
    }
    assert(K == 0);
//    cout << maxn << 
    printf("%d\n", maxn);
    forn(i, maxn) {
        forn(j, maxn) {
            printf(e[i][j] ? "Y" : "N");
        }
        printf("\n");
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}