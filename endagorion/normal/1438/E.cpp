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
i64 a[maxn];

i64 solve(int L, int R, int b) {
    if (b < 0) return 0;
    if (L >= R) return 0;
    vi lorge = {L - 1};
    i64 ans = 0;
    fore(i, L, R - 1) if ((a[i] >> b) & 1) {
        lorge.pb(i);

        {
            i64 s = 0;
            for (int j = i - 1; j >= L && s < (2LL << b); --j) {
                if (i - j > 1 && s == (a[i] ^ a[j])) ++ans;
                s += a[j];
            }
        }
        {
            i64 s = 0;
            for (int j = i + 1; j < R && s < (2LL << b); ++j) {
                if (j - i > 1 && s == (a[i] ^ a[j]) && !((a[j] >> b) & 1)) ++ans;
                s += a[j];
            }
        }
    }
    lorge.pb(R);
    forn(i, lorge.size() - 1) ans += solve(lorge[i] + 1, lorge[i + 1], b - 1);
//    cerr << L << ' ' << R << ' ' << b << ' ' << ans << '\n';
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
    cin >> n;
    forn(i, n) cin >> a[i];
    cout << solve(0, n, 29) << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}