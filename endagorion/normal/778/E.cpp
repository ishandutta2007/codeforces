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

int dc[10];

int eval_suf(const string &s, int i, int carry) {
    if (i >= (int)s.size() && !carry) return 0;
    int sd = (i < (int)s.size() ? s[i] - '0' : 0) + carry;
    return dc[sd % 10] + eval_suf(s, i + 1, sd / 10);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    string A;
    cin >> A;
    reverse(all(A));
    int n;
    cin >> n;
    vector<string> s(n);
    forn(i, n) {
        cin >> s[i];
        reverse(all(s[i]));
        if (s[i].size() < A.size()) s[i].resize(A.size(), '0');
    }

    forn(d, 10) cin >> dc[d];

    vi ord(n);
    iota(all(ord), 0);
    vi dp(n + 1, -2e9);
    dp[0] = 0;
    forn(i, A.size()) {
        vvi bynd(10);
        for (int x: ord) bynd[s[x][i] - '0'].pb(x);
        vi ptr(10);
        vi ndp(n + 1, -2e9);
        forn(j, n + 1) {
            forn(d, 10) {
                if (A[i] != '?' && A[i] - '0' != d) continue;
                if (i + 1 == (int)A.size() && !d) continue;
                int nj = 0, nval = dp[j];
                forn(nd, 10) forn(z, 2) {
                    int sd = d + nd + z;
                    int grsz = (z ? ptr[nd] : (int)bynd[nd].size() - ptr[nd]);
                    if (sd >= 10) {
                        nval += grsz * dc[sd - 10];
                        nj += grsz;
                    } else nval += grsz * dc[sd];
                }
                uax(ndp[nj], nval);
            }
            if (j < n) ++ptr[s[ord[j]][i] - '0'];
        }
        dp = ndp;
        ord.clear();
        ford(nd, 10) for (int x: bynd[nd]) ord.pb(x);
    }

    int ans = -2e9;
    int rest = 0;
    forn(i, n) rest += eval_suf(s[i], A.size(), 0);
    forn(j, n + 1) {
        uax(ans, dp[j] + rest);
        if (j < n) {
            rest -= eval_suf(s[ord[j]], A.size(), 0);
            rest += eval_suf(s[ord[j]], A.size(), 1);
        }
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}