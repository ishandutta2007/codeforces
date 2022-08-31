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

ld esum(ld l1, ld l2) {
    if (l1 < l2) swap(l1, l2);
    if (l2 < -1e8) return l1;
    return l1 + log(1 + exp(l2 - l1));
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
    vector<ld> fl(2001);
    for1(i, 2000) fl[i] = fl[i - 1] + log(i);
    int P = 1000;
    while (T--) {
        int n = 250;
        vi a(n);
        forn(i, n) cin >> a[i];
        int N = *min_element(all(a)), M = *max_element(all(a));
        ld maxl = -1e9;
        vector<ld> pprob(P + 1, -1e9), uprob(P + 1, -1e9);
        int lp = 1;
        fore(p, lp, P) {
            if (M > p || N < -p) continue;
            uprob[p] = -n * log(2 * p + 1);
        }
        fore(p, lp, P) {
            if (N < -p) continue;
            pprob[p] = 0.0;
            for (int x: a) pprob[p] += (x + p) * log(p) - p - fl[x + p];
        }
/*        vector<ld> tprob(P + 1, -1e9);
        fore(p, lp, P) tprob[p] = esum(pprob[p], uprob[p]);

        int rp = 0;
        ld bestl = -1e9;
        fore(p, lp, P) {
            int q = p / 0.95;
            int rb = q;
            uin(q, P);
            ld l = -1e9;
            while (q >= lp && q >= p / 1.05) l = esum(l, tprob[q--]);
            if (uax(bestl, l)) rp = p;
        }
        cout << rp << '\n';*/

        ld pp = -1e9, up = -1e9;
        fore(p, lp, P) {
            pp = esum(pp, pprob[p]);
            up = esum(up, uprob[p]);
        }

//        cerr << pp << ' ' << up << '\n';
        cout << (pp > up ? "poisson" : "uniform") << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}