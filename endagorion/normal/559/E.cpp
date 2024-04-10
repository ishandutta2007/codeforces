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

const int maxn = 300;
const i64 P = 1234567891;
int a[maxn], l[maxn];
vi xs;
int rel[maxn][maxn][3], ins[maxn][maxn];
i64 d2[maxn];
i64 comp[maxn][maxn];

i64 dp[maxn];

i64 anyc(int L, int R) {
    if (rel[L][R][2]) return 0;
    return d2[rel[L][R][0]];
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
    d2[0] = 1;
    forn(i, n) d2[i + 1] = d2[i] * 2 % P;

    forn(i, n) {
        cin >> a[i] >> l[i];
        fore(d, -1, 1) xs.pb(a[i] + d * l[i]);
    }
    sort(all(xs));
    xs.erase(unique(all(xs)), xs.end());
    int V = xs.size();

    forn(R, V) forn(L, R + 1) forn(i, n) {
        if (a[i] < xs[L] || a[i] > xs[R]) continue;
        ++ins[L][R];
        int cr = 0;
        if (a[i] - l[i] < xs[L]) ++cr;
        if (a[i] + l[i] > xs[R]) ++cr;
        ++rel[L][R][cr];
    }

    forn(R, V) ford(L, R + 1) {
        comp[L][R] = anyc(L, R);
        fore(i, L, R - 1) (comp[L][R] -= comp[L][i] * anyc(i + 1, R)) %= P;
        if (comp[L][R] < 0) comp[L][R] += P;
//        cerr << xs[L] << ' ' << xs[R] << ' ' << anyc(L, R) << ' ' << comp[L][R] << '\n';
//        if (comp[L][R]) cerr << xs[L] << ' ' << xs[R] << ' ' << comp[L][R] << '\n';
/*        forn(z, 3) cerr << rel[L][R][z] << ' ';
        cerr << '\n';
        cerr << d2[rel[L][R][0]] << '\n';*/
    }

    forn(R, V) {
        if (comp[0][R]) dp[R] = xs[R] - xs[0];
        if (R) uax(dp[R], dp[R - 1]);
        forn(L, R) if (comp[L + 1][R]) uax(dp[R], dp[L] + xs[R] - xs[L + 1]);
//        cerr << xs[R] << ' ' << dp[R] << '\n';
    }
    cout << dp[V - 1] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}