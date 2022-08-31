#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 50;
int pal[2][maxn][maxn][maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vvi a(n, vi(n, -1));
    a[0][0] = 1;
    a[n - 1][n - 1] = 0;
    forn(i, n) forn(j, n) {
        if ((i + j) % 2) continue;
        if (a[i][j] != -1) continue;
        forn(z, 3) {
            int ii = i - z, jj = j - (2 - z);
            if (ii < 0 || jj < 0) continue;
            cout << "? " << ii + 1 << ' ' << jj + 1 << ' ' << i + 1 << ' ' << j + 1 << endl;
            int res;
            cin >> res;
            a[i][j] = a[ii][jj] ^ res ^ 1;
            break;
        }
    }

    a[1][0] = 2;
    cout << "? 2 1 2 3" << endl;
    int res;
    cin >> res;
    a[1][2] = 2 ^ res ^ 1;
    cout << "? 1 2 2 3" << endl;
    cin >> res;
    a[0][1] = a[1][2] ^ res ^ 1;
    forn(i, n) forn(j, n) {
        if ((i + j) % 2 == 0) continue;
        if (a[i][j] != -1) continue;
        forn(z, 3) {
            int ii = i - z, jj = j - (2 - z);
            if (ii < 0 || jj < 0) continue;
            cout << "? " << ii + 1 << ' ' << jj + 1 << ' ' << i + 1 << ' ' << j + 1 << endl;
            int res;
            cin >> res;
            a[i][j] = a[ii][jj] ^ res ^ 1;
            break;
        }
    }

    forn(z, 2) {
        vvi b = a;
        forn(i, n) forn(j, n) if (b[i][j] >= 2) b[i][j] ^= 2 ^ z;
        forn(i, n) forn(j, n) {
            pal[z][i][j][i][j] = 1;
            if (i + 1 < n) pal[z][i][j][i + 1][j] = b[i][j] == b[i + 1][j];
            if (j + 1 < n) pal[z][i][j][i][j + 1] = b[i][j] == b[i][j + 1];
        }
        forn(i, n) forn(j, n) ford(ii, i + 1) ford(jj, j + 1) {
            if (!pal[z][ii][jj][i][j]) continue;
            forn(c1, 2) forn(c2, 2) {
                int x = ii, y = jj, xx = i, yy = j;
                --(c1 ? x : y);
                ++(c2 ? xx : yy);
                if (min(x, y) < 0 || max(xx, yy) >= n) continue;
                if (b[x][y] != b[xx][yy]) continue;
                pal[z][x][y][xx][yy] = 1;
            }
        }
    }

    int x1 = -1, y1, x2, y2;
    forn(i, n) forn(j, n) forn(ii, i + 1) forn(jj, j + 1) {
        if (i + j - ii - jj < 2) continue;
        if (pal[0][ii][jj][i][j] != pal[1][ii][jj][i][j]) {
            x1 = ii, y1 = jj, x2 = i, y2 = j;
        }
    }
    assert(x1 != -1);

    cout << "? " << x1 + 1 << ' ' << y1 + 1 << ' ' << x2 + 1 << ' ' << y2 + 1 << endl;
    cin >> res;
    int z = res == pal[0][x1][y1][x2][y2] ? 2 : 3;
    forn(i, n) forn(j, n) if (a[i][j] >= 2) a[i][j] ^= z;

    cout << "!\n";
    forn(i, n) {
        forn(j, n) cout << a[i][j];
        cout << '\n';
    }


#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}