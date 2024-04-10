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
const i64 P = 1000000000 + 7;
i64 inv[maxn], H[maxn], fact[maxn], tcaf[maxn];
i64 pn[maxn];

i64 cnk(int n, int k) {
    assert(n >= 0 && n < maxn);
    if (k < 0 || k > n) return 0;
    return fact[n] * tcaf[k] % P * tcaf[n - k] % P;
}

i64 icnk(int n, int k) {
    assert(n >= 0 && n < maxn);
    if (k < 0 || k > n) return 0;
    return tcaf[n] * fact[k] % P * fact[n - k] % P;
}

int m, n;

void add(i64 &x, i64 y) {
    (x += y) %= P;
    if (x < 0) x += P;
}

i64 L(vi cs) {
    int k = accumulate(all(cs), 0);
    i64 ans = P - H[k];
    for (int c: cs) for1(j, c) add(ans, cnk(c, j) * pn[j - 1] % P * inv[j] % P * icnk(k, j));
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

    cin >> m >> n;
    map<int, int> cnt;
    forn(i, m) {
        int x;
        cin >> x;
        if (x == -1) continue;
        ++cnt[x];
    }

    vi cs;
    for (auto [x, y]: cnt) cs.pb(y);

    inv[1] = 1;
    fore(i, 2, m) {
        inv[i] = (P - P / i) * inv[P % i] % P;
        assert((i * inv[i] - 1) % P == 0);
    }
    for1(i, m) H[i] = (H[i - 1] + inv[i]) % P;
    fact[0] = tcaf[0] = 1;
    pn[0] = 1;
    for1(i, m) {
        fact[i] = fact[i - 1] * i % P;
        tcaf[i] = tcaf[i - 1] * inv[i] % P;
        pn[i] = pn[i - 1] * n % P;
    }

    cout << m * (L({m}) - L(cs) + P) % P << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}