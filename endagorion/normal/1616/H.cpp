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

const int maxn = 151000, LOG = 30;
const int maxv = maxn * LOG;

int tr[maxv][2];
int w[maxv];

int tc = 2;

int get_tr(int v, int c) {
    int &t = tr[v][c];
    if (!t) t = tc++;
    return t;
}

void add(int x) {
    int v = 1;
    ford(k, LOG) {
        ++w[v];
        int b = (x >> k) & 1;
        v = get_tr(v, b);
    }
    ++w[v];
}

const i64 P = 998244353;
i64 d2[maxn];
int X;

i64 dp(int v, int u, int i) {
    if (!v) return d2[w[u]];
    if (!u) return d2[w[v]];
    int xb = (X >> i) & 1;
    if (v == u) {
        if (i < 0) return d2[w[v]];
        if (xb) return dp(tr[v][0], tr[v][1], i - 1);
        i64 sum = -1;
        forn(z, 2) sum += dp(tr[v][z], tr[v][z], i - 1);
        return sum % P;
    }
    if (i < 0) return d2[w[v] + w[u]];
    if (xb) {
        i64 ans = 1;
        forn(z, 2) (ans *= dp(tr[v][z], tr[u][z ^ 1], i - 1)) %= P;
        return ans;
    }
    i64 ans = d2[w[v]] + d2[w[u]];
    forn(z, 2) ans += dp(tr[v][z], tr[u][z], i - 1);
    forn(z, 2) {
        ans -= d2[w[tr[v][z]]];
        ans -= d2[w[tr[u][z]]];
    }
    ++ans; ans %= P;
    if (ans < 0) ans += P;
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

    int n;
    cin >> n >> X;

    d2[0] = 1;
    forn(i, n) d2[i + 1] = d2[i] * 2 % P;

    forn(i, n) {
        int x;
        cin >> x;
        add(x);
    }

    cout << (dp(1, 1, LOG - 1) + P - 1) % P << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}