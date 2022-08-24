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
int a[maxn];
int nxt[maxn];
int occ[maxn];

int ans_seg(int L, int R) {
    map<int, int> cnt;
    fore(i, L, R - 1) ++cnt[a[i]];
    int mf = 0;
    for (auto w: cnt) uax(mf, w.se);
    return R - L - mf;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, q;
    cin >> n >> q;
    assert(q == 0);
    forn(i, n) cin >> a[i];
    
    forn(i, n) nxt[i] = -1;
    forn(i, maxn) occ[i] = -1;
    ford(i, n) {
        nxt[i] = occ[a[i]];
        occ[a[i]] = i;
    }

    int ans = 0;
    int L = 0, R = 0;
    forn(i, n) {
        uax(R, nxt[i]);
        if (R <= i) ans += ans_seg(L, i + 1), L = R = i + 1;
    }
    cout << ans << '\n';


#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}