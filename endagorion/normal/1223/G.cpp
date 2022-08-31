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

const int maxa = 510000;
i64 a[maxa + 1], pa[maxa + 1];
int prv[maxa + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n;
    forn(i, n) {
        int x;
        cin >> x;
        ++a[x];
    }
    for1(i, maxa) {
        pa[i] = pa[i - 1] + a[i - 1];
        prv[i] = (a[i - 1] ? i - 1 : prv[i - 1]);
    }
    i64 ans = 0;

    for1(y, maxa) {
        i64 N = 0;
        vi ints;
        forn(i, maxa) {
            int L = i * y, R = (i + 1) * y;
            uin(R, maxa);
            N += i * (pa[R] - pa[L]);
            int x = prv[R];
            if (x >= L) {
                int y = a[x] > 1 ? x : prv[x];
                if (y >= L) ints.pb(y);
                ints.pb(x);
            }
            if (R >= maxa) break;
        }

        reverse(all(ints));
        ints.pb(-1);
        vi best(2, -1);
        int x = maxa, ptr = 0;
        i64 lx = 0;
        while (1) {
            int nx = ints[ptr];
            if (x % 2) uax(nx, x - 1);
            forn(z, 2) {
                if (best[z] == -1) continue;
                int cx = best[z];
                int d = cx - (x - 1);
                d = (d - 1) / y + 1;
                cx -= d * y;
                uax(nx, cx);
            }
            x = nx;
            if (x < 2) break;
            if (x == ints[ptr]) {
                int v = ints[ptr];
                forn(z, 2) {
                    if (v == -1) break;
                    bool sw = best[z] == -1 || v % y > best[z] % y;
                    if (sw) swap(v, best[z]);
//                    cerr << y << ' ' << x << ' ' << z << ' ' << sw << ' ' << v << ' ' << best[z] << '\n';
                }
                ++ptr;
            }
//            cerr << y << ' ' << x << ' ' << best[0] << ' ' << best[1] << '\n';
            if (best[0] != -1 && x % 2 == 0 && x > 2) {
                i64 cut = max(0, (x - best[0] % y + y - 1) / y);
                uax(lx, min(1LL * x / 2, N - cut));
            }
            if (best[1] != -1) {
                i64 cut = 0;
                forn(z, 2) cut += max(0, (x - best[z] % y + y - 1) / y);
                if (uax(lx, min(1LL * x, N - cut))) {}; //cerr << y << ' ' << x << ' ' << N << ' ' << cut << ' ' << best[0] << ' ' << best[1] << '\n';
            }
        }
        if (lx > 1) uax(ans, 1LL * lx * y);
//        cerr << y << ' ' << ans << '\n';
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}