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

int dp[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    for1(l, 100) {
        vi gr;
        forn(i, l - 1) gr.pb(dp[i] ^ dp[l - i - 2]);
        sort(all(gr));
        gr.erase(unique(all(gr)), gr.end());
        gr.pb(1e9);
        int G = 0;
        while (gr[G] == G) ++G;
        dp[l] = G;
    }

//    forn(l, 2001) cerr << l << ' ' << dp[l] << '\n';

//    fore(l, 100 + 34, 1000) assert(dp[l] == dp[l - 34]);
//    return 0;

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cr = count(all(s), 'R'), cb = n - cr;
        if (cr != cb) {
            cout << (cr > cb ? "Alice" : "Bob") << '\n';
            continue;
        }
        int nim = 0;
        int L = 0;
        while (L < n) {
            int R = L;
            while (R + 1 < n && s[R + 1] != s[R]) ++R;
            int len = R - L + 1;
            while (len > 100) len -= 34;
            nim ^= dp[len];
            L = R + 1;
        }
//        cerr << dif << ' ' << nim << '\n';
        cout << (nim ? "Alice" : "Bob") << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}