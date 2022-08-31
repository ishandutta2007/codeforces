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

map<int, vector<string> > store[5][5];

int a[5][5], b[5][5];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m;

void dfs(int x, int y) {
    if (min(x, y) < 0 || min(n - x, m - y) <= 0) return;
    if (!a[x][y]) return;
    a[x][y] = 0;
    forn(d, 4) dfs(x + dx[d], y + dy[d]);
}

void brute() {
    forn(mask, 1 << (n * m)) {
        if (!mask) continue;
        forn(i, n * m) a[i / m][i % m] = b[i / m][i % m] = (mask >> i) & 1;
        int cs = 0;
        forn(i, n - 1) forn(j, m - 1) {
            int s = 0;
            forn(di, 2) forn(dj, 2) s += a[i + di][j + dj];
            if (s == 4) cs += 4;
            if (s == 3) cs += 1;
        }
        forn(i, n * m) if (a[i / m][i % m]) {
            dfs(i / m, i % m);
            break;
        }
        forn(i, n) forn(j, m) if (a[i][j]) cs = -1;
        if (cs != -1 && !store[n][m].count(cs)) {
            vector<string> res(n, string(m, '.'));
            forn(i, n) forn(j, m) if (b[i][j]) res[i][j] = '*';
            store[n][m][cs] = res;
        }
    }
}

vector<string> transpose(const vector<string> &f) {
    int n = f.size(), m = f[0].size();
    vector<string> tf(m, string(n, '.'));
    forn(i, n) forn(j, m) tf[j][i] = f[i][j];
    return tf;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    for (n = 3; n <= 4; ++n) for (m = 3; m <= 4; ++m) {
        brute();
    }

    int T;
    cin >> T;
    forn(ti, T) {
        if (ti) cout << '\n';
        int n, m, k;
        cin >> n >> m >> k;
        if (max(n, m) <= 4) {
            if (store[n][m].count(k)) {
                forn(i, n) cout << store[n][m][k][i] << '\n';
            } else cout << -1 << '\n';
            continue;
        }
        bool sw = n > m;
        if (sw) swap(n, m);
        int allc = 4 * (n - 1) * (m - 1);
        bool ok = k <= allc;
        ok &= allc - k != 1;
        ok &= allc - k != 2;
        ok &= allc - k != 4;
        ok &= allc - k != 5;
        ok &= n == 3 || allc - k != 8;
        if (!ok) {
            cout << -1 << '\n';
            continue;
        }
        vector<string> res(n, string(m, '.'));
        if (allc - k == 8) {
            forn(i, n) forn(j, m - 1) res[i][j] = '*';
        } else {
            int li = -1, lj = -1;
            forn(i, n) forn(j, m) {
                if (li >= 0) break;
                int extra;
                if (!i) extra = 0;
                else if (!j) extra = 1;
                else if (j + 1 == m) extra = 3;
                else extra = 4;
                if (extra > k) {
                    li = i; lj = j;
                    break;
                }
                res[i][j] = '*';
                k -= extra;
            }
            assert(k < 4);
//            cout << li << ' ' << lj << '\n';
            if (k == 1) {
                if (lj + 1 < m) res[li][m - 1] = '*';
                else {
                    assert(li + 1 < n && lj >= 2);
                    res[li + 1][0] = '*';
                }
            } else if (k == 2) {
                if (lj + 2 < m) res[li][lj + 1] = '*';
                else {
                    assert(li + 1 < n && lj >= 3);
                    res[li + 1][1] = '*';
                }
            } else if (k == 3) {
                if (lj + 3 < m) {
                    res[li][m - 1] = res[li][m - 3] = '*';
                } else {
                    assert(li + 1 < n);
                    if (lj >= 4) res[li + 1][0] = res[li + 1][2] = '*';
                    else if (lj + 1 < m && lj >= 3) res[li][m - 1] = res[li + 1][1] = '*';
                    else if (lj + 2 < m && lj >= 2) res[li + 1][0] = res[li][m - 2] = '*';
                    else assert(false);
                }
            }
        }
        if (sw) res = transpose(res);
        for (auto s: res) cout << s << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}