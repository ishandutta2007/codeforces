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

const int maxn = 110000, B = 800;
vi byrow[maxn];
int dp[2][B + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, k;
    cin >> n >> k;
    forn(i, k) {
        int r, c;
        cin >> r >> c;
        --r; --c;
        byrow[r - c].pb(c);
    }

    forn(i, n) sort(rall(byrow[i]));
    int cur = 0, nxt = 1;
    for1(i, B) dp[cur][i] = 1e9;
    ford(i, n) {
        int ptr = 0;
        forn(j, B + 1) dp[nxt][j] = 1e9;

/*        cerr << i << '\n';
        forn(j, min(B + 1, n - i)) {
            if (dp[cur][j] > 1e8) cerr << "- ";
            else cerr << dp[cur][j] << ' ';
        }
        cerr << '\n';*/

        int minv = *min_element(dp[cur], dp[cur] + B + 1);
        int rs = byrow[i].size();
        dp[nxt][0] = minv + 3 * rs;
        for1(j, B) {
            while (ptr < (int)byrow[i].size() && byrow[i][ptr] == n - i - j) ++ptr;
            dp[nxt][j] = minv + 2 + j * (j + 1) / 2;
            if (j > 1) uin(dp[nxt][j], dp[cur][j - 1] + j);
            dp[nxt][j] += 3 * (rs - ptr);
        }

        swap(cur, nxt);
    }

    cout << *min_element(dp[cur], dp[cur] + B + 1) <<'\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}