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
const int P = 998244353;
pii dp[2][maxn][maxn];

pii operator+(pii a, pii b) {
    return {(a.fi + b.fi) % P, (a.se + b.se) % P};
}

pii xplus(pii a) {
    return {a.fi, (a.se + a.fi) % P};
}

string s;

pii get_dp(int l, int r, int z) {
    if (l == r) return {1, 0};
    if (dp[z][l][r] != mp(-1, -1)) return dp[z][l][r];
    auto &res = dp[z][l][r];
    res = {0, 0};
    if (!z) {
        if (s[l] != '(') res = res + get_dp(l + 1, r, 0);
        if (s[l] != ')') res = res + get_dp(l + 1, r, 1);
    } else {
        if (s[r - 1] != '(') res = res + xplus(get_dp(l, r - 1, 0));
        if (s[r - 1] != ')') res = res + get_dp(l, r - 1, 1);
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

    cin >> s;
    int n = s.size();
    forn(z, 2) forn(i, n + 1) forn(j, n + 1) dp[z][i][j] = {-1, -1};
    cout << get_dp(0, n, 0).se << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}