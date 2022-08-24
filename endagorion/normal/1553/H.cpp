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

const int maxn = 1 << 19, maxv = 20 * maxn;
int tr[maxv][2], a[maxv];
bool suf[maxv];
int ans[20][maxn];
int tc = 2;

int k;

int get_tr(int v, int b) {
    if (!tr[v][b]) tr[v][b] = tc++;
    return tr[v][b];
}

void add(int x) {
    int v = 1;
    ford(i, k) v = get_tr(v, (x >> i) & 1);
    suf[v] = 1;
    a[v] = x;
}

vvi go(int v, int d) {
    if (!v) return {{}, {}};
    if (suf[v]) return {{a[v]}, {a[v]}};
    auto resl = go(tr[v][0], d - 1), resr = go(tr[v][1], d - 1);
    if (!resl[0].empty() && !resr[0].empty()) {
        forn(i, resl[0].size()) {
            int x = resl[1][i] ^ i, y = resr[0][i] ^ i;
            uin(ans[d][i], y - x);
//            cerr << d << ' ' << i << ' ' << ans[d][i] << '\n';
        }
        forn(i, resl[0].size()) {
            int x = resr[1][i] ^ i ^ (1 << (d - 1)), y = resl[0][i] ^ i ^ (1 << (d - 1));
            uin(ans[d][(1 << (d - 1)) + i], y - x);
//            cerr << 1 << ' ' << d << ' ' << (1 << (d - 1)) + i << ' ' << ans[d][(1 << (d - 1)) + i] << ' ' << x << ' ' << y << '\n';
        }
    }
    vvi ans(2, vi(1 << d));
    if (resl[0].empty()) forn(i, 1 << d) {
        int b = i >> (d - 1);        
        ans[0][i] = resr[0][i & ((1 << (d - 1)) - 1)];
        ans[1][i] = resr[1][i & ((1 << (d - 1)) - 1)];
    } else if (resr[0].empty()) forn(i, 1 << d) {
        int b = i >> (d - 1);        
        ans[0][i] = resl[0][i & ((1 << (d - 1)) - 1)];
        ans[1][i] = resl[1][i & ((1 << (d - 1)) - 1)];
    } else forn(i, 1 << d) {
        int b = i >> (d - 1);
        ans[0][i] = (b ? resr[0] : resl[0])[i & ((1 << (d - 1)) - 1)];
        ans[1][i] = (b ? resl[1] : resr[1])[i & ((1 << (d - 1)) - 1)];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n >> k;
    forn(i, n) {
        int x;
        cin >> x;
        add(x);
    }
    forn(b, k + 1) forn(i, 1 << b) ans[b][i] = 1e9;
    go(1, k);
    forn(b, k) forn(i, 1 << b) {
//        if (ans[b][i] < 1e8) cerr << b << ' ' << i << ' ' << ans[b][i] << '\n';
        forn(z, 2) uin(ans[b + 1][i + (z << b)], ans[b][i]);
    }
    forn(i, 1 << k) cout << ans[k][i] << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}