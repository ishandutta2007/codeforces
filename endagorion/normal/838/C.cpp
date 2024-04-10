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

i64 P;

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

const int maxn = (1 << 18) + 1;
i64 fact[maxn], tcaf[maxn];

i64 cnk(int n, int k) {
    return fact[n] * tcaf[k] % P * tcaf[n - k] % P;
}

void add(int &x, i64 y) {
    if (y) x = (x + y) % P;
}

template<class T>
void rec(T a, T b, T c, int i) {
    if (!i) {
        add(*c, 1LL * *a * *b);
        return;
    }
    int j = i >> 1;
    rec(a, b, c, j);
    rec(a + i, b, c + i, j);
    rec(a, b + i, c + i, j);
}

vi operator*(vi &a, vi &b) {
    vi c(a.size());
    rec<vi::iterator>(a.begin(), b.begin(), c.begin(), a.size() / 2);
    return c;
}

vi get_prod(vi bits, int k) {
    int K = 1 << bits.size();
    vi x(K);
    forn(i, K) {
        int s = 0;
        forn(j, bits.size()) if ((i >> j) & 1) s += bits[j];
        x[i] = tcaf[s];
    }

    vi y;

    cerr << K << '\n';

    while (k) {
        if (k & 1) y = (y.empty() ? x : y * x);
        k /= 2;
        if (k) x = x * x;
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

    int n, k;
    cin >> n >> k >> P;

    i64 allS = deg(k, n);
    i64 bad = 0;
    if (n % 2 == 0) {
        int N = 1;
        while (N <= n) N *= 2;

        cerr << N << '\n';

        fact[0] = 1;
        for1(i, N - 1) fact[i] = i * fact[i - 1] % P;
        tcaf[N - 1] = deg(fact[N - 1], -1);
        ford(i, N - 1) tcaf[i] = tcaf[i + 1] * (i + 1) % P;

        vi bits;
        forn(i, 18) if ((n >> i) & 1) bits.pb(1 << i);

        auto dp = get_prod(bits, k);

        bad = dp.back() * fact[n] % P;
    }

    i64 ans = allS - bad;
    ans %= P;
    if (ans < 0) ans += P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}