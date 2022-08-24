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

const i64 P = 998244353;
const int maxn = 1100000;
i64 fact[maxn], tcaf[maxn], inv[maxn];

i64 deg(i64 x, i64 d) {
    d %= P - 1;
    if (d < 0) d += P - 1;
    i64 y = 1;
    while (d) {
        if (d & 1) (y *= x) %= P;
        d /= 2;
        (x *= x) %= P;
    }
    return y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    fact[0] = 1;
    for1(i, maxn - 1) fact[i] = i * fact[i - 1] % P;
    tcaf[maxn - 1] = deg(fact[maxn - 1], -1);
    ford(i, maxn - 1) tcaf[i] = tcaf[i + 1] * (i + 1) % P;
    forn(i, maxn - 1) {
        inv[i] = deg(i, -1);
//        if (i) assert(1LL * i * inv[i] % P == 1);
    }

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vi a(n);
        for (int &x: a) cin >> x;
        if (a == vi(n, a[0])) {
            cout << 1 << '\n';
            continue;
        }
        vi64 cnt(n);
        for (int x: a) ++cnt[x - 1];
        map<i64, i64> ccnt;
        for (int x: cnt) if (x) ++ccnt[x];
        vector<pi64> vccnt(all(ccnt));
        i64 G = 0;
        forn(i, n) G = __gcd(G, cnt[i]);

        vi64 byPer(n + 1), cByPer(n + 1);
        for1(i, n) {
            if (G % i) continue;
            byPer[i] = fact[n / i];
            for (auto [l, c]: vccnt) {
                (byPer[i] *= deg(tcaf[l / i], c)) %= P;
            }
            i64 ex = 0;
            int p = i;
            for (auto [l, c]: vccnt) {
                i64 R = 1;
                i64 lp = l / p, np = n / p;
                (R *= lp) %= P;
                (R *= (np - lp)) %= P;
                (R *= inv[np]) %= P;
                (R *= inv[np - 1]) %= P;
                (R *= n) %= P;
                (ex += c * R) %= P;
            }
            cByPer[i] = byPer[i] * ex % P;
//            cerr << i << ' ' << byPer[i] << '\n';
        }
//        for1(i, n) if (byPer[i]) cerr << i << ' ' << byPer[i] << ' ' << cByPer[i] << '\n';

        vi pers;
        ford(i, n + 1) {
            if (!i) break;
            fore(j, 2, n / i) {
                (byPer[i] += P - byPer[i * j]) %= P;
                (cByPer[i] += P - cByPer[i * j]) %= P;
            }
        }
//        for1(i, n) if (byPer[i]) cerr << i << ' ' << byPer[i] << ' ' << cByPer[i] << '\n';

        i64 TP = 0, TS = 0;
        for1(i, n) {
            (byPer[i] *= inv[n / i]) %= P;
            (cByPer[i] *= inv[n / i]) %= P;
            if (byPer[i]) {
                (TP += byPer[i]) %= P;
                (TS += cByPer[i]) %= P;
            }
        }

        i64 ans = TS;
        (ans *= deg(TP, -1)) %= P;
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}