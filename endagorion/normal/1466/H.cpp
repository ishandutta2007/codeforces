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

struct TState {
    map<int, int> cs, ns;
    int v;

    bool operator<(const TState &st) const {
        if (cs != st.cs) return cs < st.cs;
        if (ns != st.ns) return ns < st.ns;
        return v < st.v;
    }
};

map<TState, i64> memo;

const int maxn = 41;
i64 fact[maxn], tcaf[maxn], inv[maxn];
int n;
const i64 P = 1000000000 + 7;

i64 cnk(int n, int k) {
    return fact[n] * tcaf[k] % P * tcaf[n - k] % P;
}

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

i64 get_dp(TState st) {
/*    cerr << "CS: ";
    for (auto [x, y]: st.cs) cerr << x << ": " << y << ", ";
    cerr << '\n';
    cerr << "NS: ";
    for (auto [x, y]: st.ns) cerr << x << ": " << y << ", ";
    cerr << '\n';
    cerr << st.v << '\n';
    cerr << "---\n";*/
    if (memo.count(st)) return memo[st];
    auto &res = memo[st];
    res = 0;
    if (st.cs.empty()) {
        if (!st.v) return res = 0;
        TState nst = st;
        nst.ns.swap(nst.cs);
        int lft = 0;
        for (auto &w: st.ns) lft += w.fi * w.se;
        nst.v = 0;
//        cerr << lft << ' ' << fact[n] << ' ' << inv[n - lft] << ' ' << fact[n] * inv[n - lft] % P << '\n';
        i64 coef = deg(fact[n] * inv[n - lft] % P, st.v);
//        cerr << coef << '\n';
        return res = -coef * get_dp(nst) % P;
    }
    assert(!st.cs.empty());

    auto it = --st.cs.end();
    int x = it->fi, y = it->se;
    st.cs.erase(it);
    forn(j, y + 1) {
        TState nst = st;
        nst.v += j * x;
        if (j < y) nst.ns[x] += y - j;
        (res += get_dp(nst) * (j % 2 ? -1 : 1) * cnk(y, j)) %= P;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n;

    fact[0] = 1;
    for1(i, n) fact[i] = i * fact[i - 1] % P;
    forn(i, n + 1) tcaf[i] = deg(fact[i], -1);
    for1(i, n) inv[i] = deg(i, -1);

    vi a(n);
    forn(i, n) cin >> a[i], --a[i];
    map<int, int> cs;
    forn(i, n) {
        if (a[i] == -1) continue;
        int len = 0;
        for (int j = i; a[j] != -1; ) {
            ++len;
            int k = a[j];
            a[j] = -1;
            j = k;
        }
        ++cs[len];
    }

    memo[{{}, {}, 0}] = 1;
    i64 ans = get_dp({cs, {}, 0});
    if (ans < 0) ans += P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}