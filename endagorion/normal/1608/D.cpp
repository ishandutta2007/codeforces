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

const int maxn = 210000;
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
    if (k < 0 || k > n) return 0;
    i64 num = 1, den = 1;
    forn(i, k) {
        (num *= n - i) %= P;
        (den *= i + 1) %= P;
    }
    return num * deg(den, -1) % P;
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
    int span = 0, off = 0;
    i64 alld = 1;
    vi64 same(2, 1);
    forn(i, n) {
        string s;
        cin >> s;
        forn(z, 2) {
            if (s[z] == '?') ++span;
            else if (s[z] == 'W') ++off;
            else --off;
        }

        i64 res = 0;
        forn(z, 2) {
            if (s[z] != 'W' && s[z ^ 1] != 'B') ++res;
            else same[z] = 0;
        }
        (alld *= res) %= P;
    }

//    cerr << span << ' ' << off << '\n';
//    cerr << cnk(span, (span + off) / 2) << ' ' << alld << '\n';;


    i64 ans = cnk(span, (span + off) / 2) - alld + same[0] + same[1];
    ans %= P;
    if (ans < 0) ans += P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}