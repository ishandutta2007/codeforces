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
i64 a[maxn];
int pc[maxn];
i64 minpref[maxn], maxpref[maxn];
int minprefpc[maxn], maxprefpc[maxn];
int eqpsum[maxn];

int cnt[61][2][2];

i64 dnc(int L, int R) {
    if (R - L <= 1) return R - L;
    int M = (L + R) / 2;
    i64 minx = 1e18, maxx = -1e18;
    int minp = -1, maxp = -1;
    forn(i, 61) forn(x, 2) forn(y, 2) cnt[i][x][y] = 0;
    int minptr = M, maxptr = M;
    i64 ans = 0;
    minpref[M] = 1e18;
    maxpref[M] = -1e18;
    eqpsum[M] = 0;
    fore(i, M, R - 1) {
        minpref[i + 1] = minpref[i];
        minprefpc[i + 1] = minprefpc[i];
        if (uin(minpref[i + 1], a[i])) minprefpc[i + 1] = pc[i];

        maxpref[i + 1] = maxpref[i];
        maxprefpc[i + 1] = maxprefpc[i];
        if (uax(maxpref[i + 1], a[i])) maxprefpc[i + 1] = pc[i];

        eqpsum[i + 1] = eqpsum[i] + int(minprefpc[i + 1] == maxprefpc[i + 1]);
    }

    for (int i = M - 1; i >= L; --i) {
        if (uin(minx, a[i])) minp = pc[i];
        if (uax(maxx, a[i])) maxp = pc[i];
        while (minptr < R && a[minptr] >= minx) {
            ++cnt[minprefpc[minptr + 1]][0][0];
            ++cnt[maxprefpc[minptr + 1]][0][1];
            ++minptr;
        }
        while (maxptr < R && a[maxptr] <= maxx) {
            ++cnt[minprefpc[maxptr + 1]][1][0];
            ++cnt[maxprefpc[maxptr + 1]][1][1];
            ++maxptr;
        }
        if (minp == maxp) ans += min(minptr, maxptr) - M;
        if (minptr <= maxptr) ans += cnt[maxp][1][0] - cnt[maxp][0][0];
        else ans += cnt[minp][0][1] - cnt[minp][1][1];
        ans += eqpsum[R] - eqpsum[max(minptr, maxptr)];
//        cerr << i << ' ' << minx << ' ' << maxx << ' ' << minptr << ' ' << maxptr << ' ' << ans << '\n';
    }
    ans += dnc(L, M) + dnc(M, R);
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
    forn(i, n) {
        cin >> a[i];
        pc[i] = __builtin_popcountll(a[i]);
    }

    cout << dnc(0, n) << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}