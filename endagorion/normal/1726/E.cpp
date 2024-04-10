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

const int maxn = 310000;
const i64 P = 998244353;
i64 fact[maxn], tcaf[maxn], d2[maxn], inv[maxn], f2[maxn];
i64 invol[maxn];

i64 cnk(int n, int k) {
    assert(k >= 0 && k <= n);
    return fact[n] * tcaf[k] % P * tcaf[n - k] % P;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    inv[1] = 1;
    fore(i, 2, maxn - 1) inv[i] = P - P / i * inv[P % i] % P;
    fact[0] = tcaf[0] = d2[0] = 1;
    f2[0] = f2[1] = 1;
    invol[0] = 1;
    for1(i, maxn - 1) {
        fact[i] = i * fact[i - 1] % P;
        tcaf[i] = inv[i] * tcaf[i - 1] % P;
        d2[i] = 2 * d2[i - 1] % P;
        if (i > 1) f2[i] = i * f2[i - 2] % P;

        invol[i] = invol[i - 1];
        if (i > 1) (invol[i] += (i - 1) * invol[i - 2]) %= P;
    }

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        i64 ans = 0;
        forn(k, n / 4 + 1) {
            int sing = n - 4 * k;
            assert(sing >= 0);
            i64 ways = cnk(n - 2 * k, 2 * k) * (k ? f2[2 * k - 1] : 1LL) % P * d2[k] % P;
//            cerr << n << ' ' << k << ' ' << ways << ' ' << invol[sing] << '\n';
//            cerr << cnk(n - 2 * k, 2 * k) << ' ' << f2[
            (ans += ways * invol[sing]) %= P;
        }
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}