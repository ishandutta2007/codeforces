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

const int maxn = 110000;
string ans;
vi e[maxn];
int h[maxn];
int H;
vi inter[maxn], leaf[maxn], allh[maxn];
int hsz[maxn];
vi hbysz[maxn];

void dfs(int v) {
    ++hsz[h[v]];
    uax(H, h[v] + 1);
    (e[v].empty() ? leaf : inter)[h[v]].pb(v);
    allh[h[v]].pb(v);
    for (int u: e[v]) {
        h[u] = h[v] + 1;
        dfs(u);
    }
}

int bp[maxn];
pii lsz[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, x;
    cin >> n >> x;
    ans = string(n, 'b');
    for1(i, n - 1) {
        int p;
        cin >> p;
        --p;
        e[p].pb(i);
    }
    dfs(0);
    forn(i, H) {
//        cerr << i << ' ' << hsz[i] << '\n';
        hbysz[hsz[i]].pb(i);
    }

    bp[0] = 1;
    for1(s, n) {
        int C = hbysz[s].size();
        if (!C) continue;
//        cerr << s << ' ' << C << '\n';
        vi last(s, -1e9);
        forn(i, n + 1) {
            if (!bp[i] && i - last[i % s] <= C * s) {
                bp[i] = 1;
                lsz[i] = mp(s, (i - last[i % s]) / s);
//                cerr << i << ' ' << s << ' ' << (i - last[i % s]) / s << '\n';
            }
            if (bp[i] && lsz[i].fi != s) last[i % s] = i;
        }
    }

    if (bp[x]) {
        for (; x; ) {
            auto [s, c] = lsz[x];
            forn(i, c) {
                int h = hbysz[s][i];
                for (int v: allh[h]) ans[v] = 'a';
            }
            x -= s * c;
        }
        cout << H << '\n' << ans << '\n';
        return 0;
    }

    forn(h, H) {
        if (!x) break;
        if (x < inter[h].size()) continue;
        for (int v: inter[h]) {
            ans[v] = 'a';
            --x;
        }
        for (int v: leaf[h]) {
            if (!x) break;
            ans[v] = 'a';
            --x;
        }
    }
    assert(!x);
    cout << H + 1 << '\n' << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}