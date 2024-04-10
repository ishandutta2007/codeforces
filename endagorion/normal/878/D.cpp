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

typedef bitset<1 << 12> bs;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, k, q;
    cin >> n >> k >> q;
    vvi a(k, vi(n));
    forn(i, k) forn(j, n) cin >> a[i][j];
    vvi ord(n, vi(k));
    forn(i, n) {
        iota(all(ord[i]), 0);
        sort(all(ord[i]), [&](int x, int y){return a[x][i] > a[y][i];});
    }

    vector<bs> b(k);
    forn(i, k) forn(m, 1 << k) b[i][m] = (m >> i) & 1;

    forn(qi, q) {
        int type, x, y;
        cin >> type >> x >> y;
        --x; --y;
        if (type == 1) b.pb(b[x] | b[y]);
        if (type == 2) b.pb(b[x] & b[y]);
        if (type == 3) {
            int mask = 0, ptr = 0;
            while (!b[x][mask]) mask |= 1 << ord[y][ptr++];
            --ptr;
            cout << a[ord[y][ptr]][y] << '\n';
        }
    }


#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}