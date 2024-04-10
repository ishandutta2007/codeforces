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

const int maxn = 110000;
const int maxb = 17, maxa = 1 << maxb;
const i64 P = 998244353;
vi e[maxn];
int gr[maxn];
i64 a[maxa];

i64 deg(i64 x, i64 d) {
    if (d < 0) d += P - 1;
    i64 y = 1;
    while (d) {
        if (d & 1) (y *= x) %= P;
        d /= 2;
        (x *= x) %= P;
    }
    return y;
}

int get_gr(int v) {
    if (gr[v] != -1) return gr[v];
    vi ch(e[v].size() + 1);
    for (int u: e[v]) {
        int g = get_gr(u);
        if (g >= ch.size()) continue;
        ch[g] = 1;
    }
    gr[v] = 0;
    while (ch[gr[v]]) ++gr[v];
    return gr[v];
}

void conv() {
    i64 half = (P + 1) / 2;
    forn(i, maxb) forn(j, maxa) if (!((j >> i) & 1)) {
        i64 x = a[j], y = a[j ^ (1 << i)];
        a[j] = (x + y) % P;
        a[j ^ (1 << i)] = (x - y) % P;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m;
    cin >> n >> m;
    forn(i, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].pb(v);
    }

    forn(i, n) gr[i] = -1;
    a[0] = n + 1;
    forn(i, n) {
        (a[get_gr(i)] -= 1) %= P;
    }

//    forn(i, maxa) cerr << a[i] << ' ';
//    cerr << '\n';
    conv();
//    forn(i, maxa) cerr << a[i] << ' ';
//    cerr << '\n';
    forn(i, maxa) {
        assert(a[i]);
        a[i] = deg(a[i], -1);
    }
    conv();
/*    forn(i, maxa) {
        if (a[i] < 0) a[i] += P;
        cerr << a[i] << ' ';
    }
    cerr << '\n';*/

    i64 ans = 1 - a[0] * deg(2, -maxb) % P;
    ans %= P;
    if (ans < 0) ans += P;

    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}