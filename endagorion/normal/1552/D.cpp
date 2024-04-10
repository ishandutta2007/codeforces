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

const int maxn = 10;
int a[maxn];
int n;

pii x;

pii rec(int i, int s, pii p) {
    if (s == 0 && (p.fi || p.se)) return p;
    if (i == n) return {-1, -1};
    {
        auto w = rec(i + 1, s, p);
        if (w.fi != -1) return w;
    }

    {
        s += a[i];
        p.fi += 1 << i;
        auto w = rec(i + 1, s, p);
        if (w.fi != -1) return w;
        s -= a[i];
        p.fi -= 1 << i;
    }
    {
        s -= a[i];
        p.se += 1 << i;
        auto w = rec(i + 1, s, p);
        if (w.fi != -1) return w;
        s += a[i];
        p.se -= 1 << i;
    }
    return {-1, -1};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        forn(i, n) cin >> a[i];
        pii p = rec(0, 0, {0, 0});
        if (p.fi < 0) cout << "NO\n";
        else cout << "YES\n";
/*            int x = 0;
            vi b = {x};
            int m1 = p.fi, m2 = p.se;
            forn(i, n) {
                if (((m1 | m2) >> i) & 1) continue;
                x += a[i];
                b.pb(x);
            }
            forn(i, 2) {
                int m = (i ? m2 : m1);
                int y = x;
                forn(j, n) {
                    if ((m >> j) & 1) {
                        y += a[j];
                        b.pb(y);
                    }
                }
            }
            b.pop_back();
            assert(b.size() == n);
            cout << "YES\n";
            for (int x: b) cout << x << ' ';
            cout << '\n';
        }*/
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}