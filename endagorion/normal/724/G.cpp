#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
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
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 110000;
const i64 P = 1000000000 + 7;
vector<pi64> e[maxn];
int vis[maxn];
i64 xs[maxn];

void addToB(vi64 &b, i64 x) {
    ford(i, 60) {
        if (!((x >> i) & 1)) continue;
        if (!b[i]) {
            b[i] = x;
            break;
        }
        x ^= b[i];
    }
}

void dfs(int v, int p, i64 x, vi64 &b, vi64 &ws) {
    ws.pb(x);
    vis[v] = 1;
    xs[v] = x;
    for (auto w: e[v]) {
        i64 u = w.fi, c = w.se;
        if (u == p) continue;
        if (vis[u] == 0) dfs(u, v, x ^ c, b, ws);
        else if (vis[u] == 1) addToB(b, x ^ xs[u] ^ c);
    }
    vis[v] = 2;
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
    forn(i, m) {
        i64 u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        e[u].pb(mp(v, w));
        e[v].pb(mp(u, w));
    }

    i64 total = 0;
    forn(i, n) {
        if (vis[i]) continue;
        vi64 b(60);
        vi64 ws;
        dfs(i, -1, 0, b, ws);
        i64 bs = 1;
        i64 t = ws.size();
        forn(k, 60) if (b[k]) bs *= 2, bs %= P;
        forn(k, 60) {
            bool sc = false;
            forn(i, 60) sc |= (b[i] >> k) & 1;
            i64 bv = (1LL << k) % P;
            if (sc) {
                total += t * (t - 1) / 2 % P * bs % P * (P + 1) / 2 % P * bv;
                total %= P;
            } else {
                i64 z0 = 0, z1 = 0;
                for (i64 x: ws) ++((x >> k) & 1 ? z1 : z0);
                total += z0 * z1 % P * bs % P * bv % P;
                total %= P;
            }
        }
//        cerr << total << '\n';
    }

    if (total < 0) total += P;
    cout << total << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}