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

const int maxn = 2100000;
const i64 P = 998244353;
i64 fact[maxn], tcaf[maxn];

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

i64 cnk(int n, int k) {
    if (k == 0 || k == n) return 1;
    if (k < 0 || k > n) return 0;
    return fact[n] * tcaf[k] % P * tcaf[n - k] % P;
}

i64 hockey(int a, int s) {
    return cnk(a + s + 1, s);
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

    int n;
    cin >> n;

    vi a(n);
    forn(i, n) cin >> a[i];
    sort(all(a));
    priority_queue<pii, vector<pii>, greater<pii> > q;
    forn(i, n) q.push(mp(a[i], i));
    int D = 0;
    i64 ans = 0;
    int last = 0;
    while (1) {
        auto p = q.top();
        q.pop();
        if (p.fi < D) break;
        int lops = p.fi - D;
        i64 res = hockey(n - 2, lops);
        int suf = n - last;
        if (p.se < last && suf <= lops) res -= hockey(n - 2, lops - suf);
        res %= P;
        if (res < 0) res += P;
        (ans += res) %= P;
//        cerr << p.fi << ' ' << p.se << ' ' << D << ' ' << ans << '\n';
//        cerr << lops << ' ' << suf << '\n';
        uax(last, p.se + 1);
        if (last == n) break;
        p.fi += n;
        q.push(p);
        ++D;
    }
    cerr << D << '\n';
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}