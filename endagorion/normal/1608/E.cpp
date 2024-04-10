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

vector<pii> byx[4][3], byy[4][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    vector< vector<pii> > a(3);
    int n;
    cin >> n;
    forn(i, n) {
        pii p;
        int c;
        cin >> p.fi >> p.se >> c;
        --c;
        a[c].pb(p);
    }

    forn(z, 4) {
        forn(c, 3) {
            byx[z][c] = a[c];
            sort(all(byx[z][c]));
            byy[z][c] = a[c];
            sort(all(byy[z][c]), [&](pii a, pii b){return a.se < b.se;});

            for (auto &p: a[c]) {
                swap(p.fi, p.se);
                p.se = -p.se;
            }
        }
    }

    int L = 0, R = n / 3 + 1;
    while (R - L > 1) {
        int M = (L + R) / 2;
        bool ok = false;

        forn(z, 4) forn(c, 3) {
            int lx = byx[z][c][M - 1].fi + 1;
            vector< vector<pii> > b(2);
            forn(d, 2) {
                int cc = (c + 1 + d) % 3;
                for (auto p: byy[z][cc]) if (p.fi >= lx) b[d].pb(p);
            }
            if (b[0].size() < M || b[1].size() < M) continue;
            forn(z, 2) ok |= b[z][M - 1].se < b[z ^ 1].end()[-M].se;

            forn(d, 2) {
                int lxx = lx;
                bool good = true;
                forn(e, 2) {
                    int cc = (c + 1 + (d ^ e)) % 3;
                    auto it1 = lower_bound(all(byx[z][cc]), mp(lxx, -1));
                    if (byx[z][cc].end() - it1 < M) {
                        good = false;
                        break;
                    }
                    lxx = (it1 + M - 1)->fi + 1;
                }
                if (good) ok = true;
            }
        }
        (ok ? L : R) = M;
    }
    cout << 3 * L << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}