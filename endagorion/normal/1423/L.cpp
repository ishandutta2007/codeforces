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
typedef unsigned long long ui64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

ui64 rand64() {
    ui64 x = 0;
    forn(i, 64) {
        x <<= 1;
        x += ui64(rand() % 2);
    }
    return x;
}

const int maxn = 1000, maxk = 30;
ui64 a[maxn], b[maxk];
ui64 pxor[1 << (maxk / 2)];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, s, q;
    cin >> n >> s >> q;
    forn(i, n) a[i] = rand64();
    forn(i, s) {
        int c;
        cin >> c;
        forn(j, c) {
            int x;
            cin >> x;
            --x;
            b[i] ^= a[x];
        }
    }

    unordered_map<ui64, int> sz;
    int lh = min(20, s), rh = s - lh;
    forn(mask, 1 << lh) {
        ui64 x = 0;
        forn(j, lh) if ((mask >> j) & 1) x ^= b[j];
        if (!sz.count(x)) sz[x] = 1e9;
        uin(sz[x], __builtin_popcount(mask));
    }

    forn(mask, 1 << rh) forn(j, rh) if ((mask >> j) & 1) pxor[mask] ^= b[lh + j];

    while (q--) {
        ui64 x = 0;
        int c;
        cin >> c;
        while (c--) {
            int p;
            cin >> p;
            --p;
            x ^= a[p];
        }

        int ans = 1e9;
        forn(mask, 1 << rh) {
            ui64 y = x ^ pxor[mask];
            if (sz.count(y)) uin(ans, __builtin_popcount(mask) + sz[y]);
        }
        if (ans > 1e8) ans = -1;
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}