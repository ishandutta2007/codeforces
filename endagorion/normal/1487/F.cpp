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

vi fromstring(string s) {
    reverse(all(s));
    vi v(s.size());
    forn(i, v.size()) v[i] = s[i] - '0';
    return v;    
}

vi operator*(vi a, vi b) {
    vi c(a.size() + b.size());
    forn(i, a.size()) forn(j, b.size()) c[i + j] += a[i] * b[j];
    forn(i, c.size() - 1) {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    while (!c.empty() && !c.back()) c.pop_back();
    return c;
}

vi operator+(vi a, vi b) {
    vi c(max(a.size(), b.size()) + 1);
    forn(i, c.size()) {
        if (i < (int)a.size()) c[i] += a[i];
        if (i < (int)b.size()) c[i] += b[i];
    }
    forn(i, c.size() - 1) {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    while (!c.empty() && !c.back()) c.pop_back();
    return c;
}

vi operator-(vi a, vi b) {
    vi c(max(a.size(), b.size()) + 1);
    forn(i, c.size()) {
        if (i < (int)a.size()) c[i] += a[i];
        if (i < (int)b.size()) c[i] -= b[i];
    }
    forn(i, c.size() - 1) {
        if (c[i] < 0) c[i] += 10, --c[i + 1];
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    if (c.back() < 0) return {-1};
    while (!c.empty() && !c.back()) c.pop_back();
    return c;
}

int dp[100][1000][3];

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
    vi v = fromstring(s) * fromstring(to_string(9));

    int ans = 1e9;
    fore(d, -450, 450) {
        vi u;
        if (!d) u = v;
        else if (d > 0) u = v + fromstring(to_string(d));
        else u = v - fromstring(to_string(-d));
        if (u[0]) continue;

/*        reverse(all(u));
        cerr << d << ": ";
        for (int x: u) cerr << x;
        cerr << '\n';
        reverse(all(u));*/

        u.pb(0);
        int L = u.size();

        forn(i, L + 1) forn(dd, 1000) forn(c, 3) dp[i][dd][c] = 1e9;
        dp[0][500][1] = 0;
        forn(i, L) fore(dd, 500 - 9 * i, 500 + 9 * i) forn(c, 3) {
            int V = dp[i][dd][c];
            if (V > 1e8) continue;
            int di = u[i] + c - 1;
            fore(x, -9, 9) {
                int ndi = di + x;
                if (ndi % 10) continue;
                uin(dp[i + 1][dd + x][ndi / 10 + 1], V + abs(x) * i);
            }
        }
        if (uin(ans, dp[L][500 - d][1])) {};//cerr << d << ' ' << ans << '\n';
    }

    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}