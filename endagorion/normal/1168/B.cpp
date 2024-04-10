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

    string s;
    cin >> s;
    int n = s.size();
    i64 ans = 0;
    fore(l, 9, n) ans += n - l + 1;
    vi lb(n, 9);
    forn(i, n) for1(d, 3) {
        if (i + 2 * d >= n) continue;
        if (s[i] == s[i + d] && s[i] == s[i + 2 * d]) uin(lb[i], 2 * d + 1);
    }
    ford(i, n - 1) uin(lb[i], lb[i + 1] + 1);
    forn(i, n) if (lb[i] < 9) ans += max(0, min(9, n - i + 1) - lb[i]);
    cout << ans << '\n';

/*    i64 ans2 = 0;
    forn(r, n + 1) forn(l, r) {
        bool can = false;
        fore(i, l, r - 1) for1(d, (r - i - 1) / 2) if (s[i] == s[i + d] && s[i] == s[i + 2 * d]) can = true;
        if (can) ++ans2;
    }
    cout << ans2 << '\n';*/

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}