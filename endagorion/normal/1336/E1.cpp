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

typedef bitset<36> bs;
const i64 P = 998244353;

void add(vector<bs> &v, bs b) {
    if (b.none()) return;
    int i = b._Find_first();
    for (auto &r: v) {
        int j = r._Find_first();
        if (i == j) {
            b ^= r;
            if (b.none()) return;
            i = b._Find_first();
            continue;
        }
        if (i < j) {
            swap(r, b);
            swap(i, j);
        }
    }
    if (b.any()) v.pb(b);
}

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
    vector<bs> v;
    i64 M = 1;
    forn(i, n) {
//        cerr << i << ' ';
        i64 x;
        cin >> x;
        bs b;
        forn(j, m) if ((x >> j) & 1) b[j] = 1;
        add(v, b);
    }

    ford(i, v.size()) {
        int x = v[i]._Find_first();
        forn(j, i) if (v[j][x]) v[j] ^= v[i];
    }

    forn(i, n - v.size()) (M *= 2) %= P;
    vi64 ans(m + 1);
//    cerr << M << ' ' << v.size() << '\n';
    if (v.size() < 20) {
        forn(mask, 1 << v.size()) {
            bs b;
            forn(i, v.size()) if ((mask >> i) & 1) b ^= v[i];
            ++ans[b.count()];
        }
    } else {
        vi isM(m);
        for (auto r: v) isM[r._Find_first()] = 1;
        vi notMain;
        forn(i, m) if (!isM[i]) notMain.pb(i);

        vvi64 dp(m + 1, vi64(1 << notMain.size()));
        dp[0][0] = 1;
        for (auto b: v) {
            int mask = 0;
            forn(j, notMain.size()) mask += b[notMain[j]] << j;

            ford(j, m) forn(x, 1 << notMain.size()) (dp[j + 1][x ^ mask] += dp[j][x]) %= P;
        }

        forn(j, m + 1) forn(x, 1 << notMain.size()) if (dp[j][x]) (ans[j + __builtin_popcount(x)] += dp[j][x]) %= P;
    }

    forn(i, m + 1) cout << ans[i] * M % P << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}