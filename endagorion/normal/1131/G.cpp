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

const int maxm = 10000001;
int h[maxm];
int lb[maxm], rb[maxm];
i64 dp[maxm];
i64 cost[maxm];
int ptr = 0;

const int maxn = 250001;
vi blh[maxn], blc[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m;
    cin >> n >> m;
    forn(i, n) {
        int sz;
        cin >> sz;
        blh[i].resize(sz);
        blc[i].resize(sz);
        forn(j, sz) cin >> blh[i][j];
        forn(j, sz) cin >> blc[i][j];
    }

    int q;
    cin >> q;
    forn(i, q) {
        int blid;
        i64 mul;
        cin >> blid >> mul;
        --blid;
        int sz = blh[blid].size();
        forn(j, sz) {
            h[ptr] = blh[blid][j];
            cost[ptr] = blc[blid][j] * mul;
            ++ptr;
        }
    }
    assert(ptr == m);

    {
        vector<pii> minst;
        forn(i, m) {
            lb[i] = max(i - h[i] + 1, 0);
            while (!minst.empty()) {
                if (minst.back().fi >= lb[i] || minst.back().se >= lb[i]) {
                    uin(lb[i], minst.back().se);
                    minst.pop_back();
                } else break;
            }
            minst.pb({i, lb[i]});
        }
    }
    {
        vector<pii> minst;
        ford(i, m) {
            rb[i] = min(i + h[i] - 1, m - 1);
            while (!minst.empty()) {
                if (minst.back().fi <= rb[i] || minst.back().se <= rb[i]) {
                    uax(rb[i], minst.back().se);
                    minst.pop_back();
                } else break;
            }
            minst.pb({i, rb[i]});
        }
    }

//    forn(i, m) cerr << lb[i] << ' ' << rb[i] << '\n';

    forn(i, m + 1) dp[i] = 1e18;
    dp[0] = 0;
    vector<pi64> minst = {{0, 0}};
    forn(i, m) {
//        cerr << i << ' ' << dp[i] << '\n';
        uin(dp[rb[i] + 1], dp[i] + cost[i]);
        i64 v = dp[i];
        while (!minst.empty()) {
            if (minst.back().fi >= lb[i] || minst.back().se >= v) {
                uin(v, minst.back().se);
                minst.pop_back();
            } else break;
        }
        uin(dp[i + 1], v + cost[i]);
        minst.pb({i, v});
//        for (auto [x, y]: minst) cerr << x << ' ' << y << ", ";
//        cerr << '\n';
    }
    cout << dp[m] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}