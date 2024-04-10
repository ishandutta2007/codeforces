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

const int maxn = 110000, B = 2000;
vi e[maxn];
int par[maxn];
int t[maxn], s[maxn];
int off[maxn];
int bid[maxn];
int bs[2 * B][2 * B + 1];
int bsp[maxn];
int aff[maxn], sp[maxn], spu[maxn];

int BB = 0;
int ans = 0;

int dfs(int v) {
    vi sps;
    s[v] = off[v];
    for (int u: e[v]) {
        int w = dfs(u);
        if (w != -1) sps.pb(w);
        s[v] += s[u];
    }
    ans += int(!off[v] && int(s[v] > t[v]));
    sp[v] = aff[v] || sps.size() > 1;
    if (sp[v]) {
        bid[v] = BB++;
        bsp[v] = B;
        for (int u: sps) spu[u] = v;
    }
    if (!sp[v] && !sps.empty() && !off[v]) {
        int w = sps[0];
//        cerr << v << " -> " << w << '\n';
        int D = s[v] - t[v];
        if (abs(D) <= B) ++bs[bid[w]][D + B];
    }

//    cerr << v << ' ' << sp[v] << '\n';


    if (!sp[v]) return sps.empty() ? -1 : sps[0];
    return v;
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
    for1(i, n - 1) {
        int &p = par[i];
        cin >> p;
        --p;
        e[p].pb(i);
    }

    forn(i, n) cin >> t[i];

    int qi = 0;
    vi anss;
    while (qi < m) {
        int batch = min(B, m - qi);
        qi += batch;
        vi qs(batch);
        forn(i, BB) {
            forn(j, 2 * B + 1) bs[i][j] = 0;
        }
        BB = 0;
        ans = 0;
        forn(i, n) {
            aff[i] = sp[i] = 0;
            spu[i] = -1;
            bid[i] = -1;
        }
        forn(i, batch) {
            cin >> qs[i];
            aff[abs(qs[i]) - 1] = 1;
        }
        dfs(0);
        assert(BB < 2 * B);

/*        forn(v, n) {
            if (!sp[v]) continue;
            int id = bid[v];
            cerr << v << ' ' << id << ' ' << bsp[v] << ": ";
            fore(i, -B, B) if (bs[id][i + B]) cerr << i << ' ' << bs[id][i + B] << ", ";
            cerr << '\n';
        }*/

//        cerr << "ans = " << ans << '\n';
        for (int q: qs) {
            int v = abs(q) - 1, doff = q > 0;
            for (int u = v; u != -1; u = spu[u]) {
//                assert(sp[u]);
                if (!off[u] && s[u] > t[u]) --ans;
                s[u] += doff ? 1 : -1;
                if (v == u) off[u] ^= 1;
                if (!off[u] && s[u] > t[u]) {
                    ++ans;
                }
                int &bp = bsp[u];
                if (doff) {
//                    cerr << u << ": +" << bs[bid[u]][bp] << " @ " << bp - B << '\n';
                    ans += bs[bid[u]][bp];
                    --bp;
                } else {
                    ++bp;
                    ans -= bs[bid[u]][bp];
                }
            }
            anss.pb(ans);
        }
    }

    for (int x: anss) cout << x << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}