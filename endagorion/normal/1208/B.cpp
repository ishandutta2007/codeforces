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
    vi a(n);
    forn(i, n) cin >> a[i];
    int ans = n;
    int R = 0;
    map<int, int> cnt;
    int bad = 0;
    forn(i, n) {
        bad -= (cnt[a[i]] > 1);
        ++cnt[a[i]];
        bad += (cnt[a[i]] > 1);
    }
    forn(L, n) {
        while (R < n && bad > 0) {
            bad -= (cnt[a[R]] > 1);
            --cnt[a[R]];
            bad += (cnt[a[R]] > 1);
            ++R;
        }
        if (!bad) uin(ans, R - L);
        bad -= (cnt[a[L]] > 1);
        ++cnt[a[L]];
        bad += (cnt[a[L]] > 1);
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}