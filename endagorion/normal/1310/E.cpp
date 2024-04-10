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

const int maxn = 2100;
int n;

bool ok(vi &a, int k) {
    if (!k) return true;
    if (accumulate(all(a), 0) > n) return false;
    if (k == 1) return true;
//    cerr << k << ": ";
//    for (int x: a) cerr << x << ' ';
//    cerr << '\n';
    vi b;
    ford(i, a.size()) {
        forn(j, a[i]) b.pb(a.size() - i);
    }
    return ok(b, k - 1);
}

int rec(vi &a, int k, int lb) {
    int ans = ok(a, k);
    if (!ans) return 0;
//    for (int x: a) cerr << x << ' ' ;
//    cerr << '\n';
    while (1) {
        a.pb(lb);
        int res = rec(a, k, lb);
        a.pop_back();
        if (!res) break;
        ans += res;
        ++lb;
    }
    return ans;
}

const int P = 998244353;
int dp[maxn][maxn];

void add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
}

pii addx(pii w, int x) {
    w.fi += w.se + x;
    w.se += x;
    return w;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int k;
    cin >> n >> k;
    if (k > 2) {
        vi a;
        cout << rec(a, k, 1) - 1 << '\n';
    } else if (k == 1) {
        dp[0][1] = 1;
        forn(s, n + 1) for1(l, n) {
            add(dp[s][l + 1], dp[s][l]);
            if (s + l <= n) add(dp[s + l][l], dp[s][l]);
        }
        int ans = 0;
        for1(s, n) add(ans, dp[s][n]);
        cout << ans << '\n';
    } else {
        int ans = 0;
        dp[0][0] = 1;
        for1(x, n) {
            forn(b, n - x + 1) fore(a, b, n - b - x) {
                int aa = a, bb = b;
                aa += bb + x;
                bb += x;
                add(ans, dp[b][a]);
                add(dp[bb][aa], dp[b][a]);
            }
        }
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}