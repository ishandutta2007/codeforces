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

const int maxa = 1100000;
int mind[maxa + 1];
vi ps;

map<int, int> factor(vi64 ns) {
    map<int, int> res;
    for (auto n: ns) {
        for (int x = n; x > 1; x /= mind[x]) ++res[mind[x]];
    }
    return res;
}

i64 rec(const vi64 &bad, int i, i64 T) {
    if (i == bad.size()) return T;
    return rec(bad, i + 1, T) - rec(bad, i + 1, T / bad[i]);
}

i64 rec2(const vector<pii> &vsf, int i, i64 M) {
    if (!M) return 0;
    i64 ans = 1;
    for (; i < (int)vsf.size() && vsf[i].fi <= M; ++i) {
        i64 nM = M;
        forn(j, vsf[i].se) {
            nM /= vsf[i].fi;
            if (!nM) break;
            ans += rec2(vsf, i + 1, nM);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    forn(i, maxa + 1) mind[i] = i;
    fore(i, 2, maxa) {
        if (mind[i] == i) ps.pb(i);
        for (int p: ps) {
            if (p > mind[i] || p * i > maxa) break;
            mind[i * p] = p;
        }
    }

    int T;
    cin >> T;
    while (T--) {
        vi64 ns(3), ms(3), ss(3);
        forn(i, 3) cin >> ns[i];
        forn(i, 3) cin >> ms[i];
        forn(i, 3) cin >> ss[i];
        auto nf = factor(ns), mf = factor(ms), sf = factor(ss);
        ++sf[2];
        vector<pii> vsf(all(sf));

        auto product = [](vi64 &f) {
            i64 Q = 1;
            for (auto x: f) Q *= x;
            return Q;
        };
        i64 N = product(ns), M = product(ms), S = 2 * product(ss);
//        cerr << N << ' ' << M << ' ' << S << '\n';
        vi64 bad;
//        cerr << "bad ";
        for (auto [p, d]: nf) {
            if (d > sf[p]) {
                i64 Q = 1;
                forn(i, sf[p] + 1) Q *= p;
                bad.pb(Q);
//                cerr << Q << ' ';
            }
        }
//        cerr << '\n';

        i64 ans1 = rec(bad, 0, M), ans2 = rec2(vsf, 0, N);
//        cerr << ans1 << ' ' << ans2 << '\n';
        i64 ans = ans1 + ans2;
        cout << ans << '\n';
    }
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}