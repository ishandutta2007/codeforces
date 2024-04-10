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

const int maxn = 501;
string f[maxn];
ui64 reach[maxn][maxn];
int itn[maxn][maxn];
int itc = 0;

const int maxq = 610000;
int ans[maxq];

struct TQuery {
    int x1, y1, x2, y2, id;

    void read() {
        cin >> x1 >> y1 >> x2 >> y2;
        --x1; --y1; --x2; --y2;
    }
};

int n, m;

void dnc(int ls, int rs, const vector<TQuery> &qs) {
    if (qs.empty()) return;
    int ms = (ls + rs) / 2;
    int lx = max(0, ms - (m - 1));
    int rx = min(n - 1, ms);
    vector< vector<TQuery> > grs(3);
    for (auto q: qs) {
        int type;
        if (q.x2 + q.y2 < ms) type = 0;
        else if (q.x1 + q.y1 > ms) type = 2;
        else type = 1;
        grs[type].pb(q);
    }
    for (int x = lx; x <= rx; x += 64) {
        int x0 = x, x1 = min(rx, x0 + 63);
        int sx0 = x0, sx1 = x1;
        ++itc;
        forn(i, x1 - x0 + 1) {
            itn[x0 + i][ms - x0 - i] = itc;
            reach[x0 + i][ms - x0 - i] = (f[x0 + i][ms - x0 - i] == '.' ? 1ULL << i : 0ULL);
        }
        for (int s = ms - 1; s >= ls; --s) {
            int nx0 = x0 - 1, nx1 = x1;
            uax(nx0, 0); uin(nx1, s);
            for (int x = nx0; x <= nx1; ++x) {
                auto &v = reach[x][s - x] = 0;
                itn[x][s - x] = itc;
                if (f[x][s - x] == '#') continue;
                if (x >= x0) v |= reach[x][s - x + 1];
                if (x + 1 <= x1) v |= reach[x + 1][s - x];
//                cerr << x << ' ' << s - x << ' ' << v << '\n';
            }
            x0 = nx0; x1 = nx1;
        }
        x0 = sx0, x1 = sx1;
        for (int s = ms + 1; s <= rs; ++s) {
            int nx0 = x0, nx1 = x1 + 1;
            uin(nx1, n - 1); uax(nx0, s - (m - 1));
            for (int x = nx0; x <= nx1; ++x) {
                auto &v = reach[x][s - x] = 0;
                itn[x][s - x] = itc;
                if (f[x][s - x] == '#') continue;
                if (x - 1 >= x0) v |= reach[x - 1][s - x];
                if (x <= x1) v |= reach[x][s - x - 1];
//                cerr << x << ' ' << s - x << ' ' << v << '\n';
            }
            x0 = nx0; x1 = nx1;
        }
        for (auto q: grs[1]) {
            if (itn[q.x1][q.y1] != itc) continue;
            if (itn[q.x2][q.y2] != itc) continue;
            if (reach[q.x1][q.y1] & reach[q.x2][q.y2]) ans[q.id] = 1;
        }
    }
    dnc(ls, ms - 1, grs[0]);
    dnc(ms + 1, rs, grs[2]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n >> m;
    forn(i, n) cin >> f[i];
    int q;
    cin >> q;
    vector<TQuery> qs(q);
    forn(i, q) {
        qs[i].read();
        qs[i].id = i;
    }

    dnc(0, n + m - 2, qs);
    forn(i, q) cout << (ans[i] ? "Yes" : "No") << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}