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

const int maxn = 1100000;
const i64 P = 998244353;
i64 atmost[maxn], ex[maxn];

i64 c2(i64 x) {
    return x * (x + 1) / 2 % P;
}

i64 c3(i64 x) {
//    assert((P + 1) % 3 == 0);
    return c2(x) * (x + 2) % P * (P + 1) / 3 % P;
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
    cin >> n;
    atmost[0] = ex[0] = 1;
    for1(i, n) {
        ex[i] = ex[i - 1];
        ex[i] += c2(atmost[i - 1]);
        if (i >= 2) ex[i] -= c2(atmost[i - 2]);
        ex[i] %= P;
        atmost[i] = atmost[i - 1] + ex[i];
        atmost[i] %= P;
//        cerr << i << ' ' << ex[i] << ' ' << atmost[i] << '\n';
    }

    i64 ans = 0;
    for1(i, n) {
        ans += ex[i - 1] * (ex[n - i] - (n - i ? ex[n - i - 1] : 0LL));
        ans %= P;
    }
    ans += 2 * (c2(atmost[n - 1]) - (n > 1 ? c2(atmost[n - 2]) : 0LL));
    ans += 2 * (c3(atmost[n - 1]) - (n > 1 ? c3(atmost[n - 2]) : 0LL));
    ans %= P;
    if (ans < 0) ans += P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}