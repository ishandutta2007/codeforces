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

int n, m;
const int maxn = 4100;
i64 a[maxn];

vi64 solve(int L, int R) {
    if (R == L) {
        vi64 res = {0};
        return res;
    }

    int M = L;
    fore(i, L, R - 1) if (a[i] < a[M]) M = i;
    auto lh = solve(L, M), rh = solve(M + 1, R);
    vi64 res(min(m + 1, (int)(lh.size() + rh.size())));
    forn(lsz, lh.size()) forn(rsz, rh.size()) forn(z, 2) {
        if (lsz + rsz + z > m) continue;
        i64 sc = lh[lsz] + rh[rsz] - 2 * lsz * rsz * a[M];
        if (z) sc += a[M] * (m - 1 - 2 * (lsz + rsz));
        uax(res[lsz + rsz + z], sc);
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

    cin >> n >> m;
    forn(i, n) cin >> a[i];
    cout << solve(0, n)[m] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}