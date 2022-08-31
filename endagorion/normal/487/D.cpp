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
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

char f[100011][15];
pii par[100011][15];
bool inter[100011][15];
int lv[100011][15];

int N, M, Q;

void rebuild() {
    for1(j, M) par[0][j] = mp(0, j);
    for1(i, N) {
        par[i][0] = mp(i, 0);
        par[i][M + 1] = mp(i, M + 1);
        for1(j, M) par[i][j] = mp(-2, -2);
        for1(j, M - 1) {
            if (!inter[i][j] && !inter[i][j + 1] && f[i][j] == '>' && f[i][j + 1] == '<') par[i][j] = par[i][j + 1] = mp(-1, -1);
        }
        for1(j, M) {
            if (par[i][j] != mp(-2, -2)) continue;
            if (inter[i][j]) par[i][j] = mp(i, j);
            else if (f[i][j] == '<') par[i][j] = par[i][j - 1];
            else if (f[i][j] == '^') par[i][j] = par[i - 1][j];
        }
        for (int j = M; j > 0; --j) {
            if (par[i][j] != mp(-2, -2)) continue;
            if (!inter[i][j] && f[i][j] == '>') par[i][j] = par[i][j + 1];
        }
    }
}

pii get(int x, int y, int id) {
    while (1) {
        pii p = par[x][y];
        x = p.fi, y = p.se;
        if (p == mp(-1, -1) || lv[x][y] == id) return mp(-1, -1);
//        cerr << x << ' ' << y << ' ' << f[x][y] << ' ' << inter[x][y] << '\n';
        if (!inter[x][y]) return p;
        lv[x][y] = id;
        if (f[x][y] == '^') --x;
        else if (f[x][y] == '<') --y;
        else ++y;
    }
}

struct TQuery {
    char type;
    int x, y;
    char c;

    TQuery()
        : type()
        , x()
        , y()
        , c()
    {
    }

    TQuery(char type, int x, int y, char c)
        : type(type)
        , x(x)
        , y(y)
        , c(c)
    {
    }
};

const int MAXQ = 100000;
const int BLC = 1000;
TQuery qs[MAXQ];

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> N >> M >> Q;
//    scanf("%d%d%d\n", &N, &M, &Q);
    forn(i, N) {
        string s;
        cin >> s;
        forn(j, M) f[i + 1][j + 1] = s[j];
    }
    forn(i, Q) {
//        scanf("%c %d %d", &qs[i].type, &qs[i].x, &qs[i].y);
        cin >> qs[i].type >> qs[i].x >> qs[i].y;
        if (qs[i].type == 'C') cin >> qs[i].c;
    }
    int i = 0;
    while (i < Q) {
//        cerr << i << '\n';
        int j = i;
        int cc = 0;
        forn(x, N + 2) forn(y, M + 2) inter[x][y] = false;
        while (j < Q && cc < BLC) {
            if (qs[j].type == 'C') {
                inter[qs[j].x][qs[j].y] = true;
                ++cc;
            }
            ++j;
        }
        rebuild();
        for (int k = i; k < j; ++k) {
//            if (k % 10 == 0) cerr << k << '\n';
            if (qs[k].type == 'A') {
                pii p = get(qs[k].x, qs[k].y, k + 1);
                cout << p.fi << ' ' << p.se << '\n';
            } else {
                f[qs[k].x][qs[k].y] = qs[k].c;
            }
        }

        i = j;
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}