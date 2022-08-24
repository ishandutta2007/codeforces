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
typedef unsigned long long ui64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

vector<ui64> st, sm_st;
map<ui64, int> en, sm_en;
vector< vector<int> > tr;
vi col;
vi cantr[64];

ui64 add(ui64 m, int z) {
    forn(i, 64) if ((m >> i) & 1) m |= 1ULL << (i ^ z);
    return m;
}

int badd(int i, int j) {
    ui64 m = st[j];
    forn(k, 64) {
        if (!((m >> k) & 1)) continue;
        if (tr[i][k] == -1) continue;
        i = tr[i][k];
    }
    return i;
}

int dfs(ui64 m) {
    if (en.count(m)) return en[m];
    int num = en[m] = st.size();
    st.pb(m);
    if (!(m >> 32)) {
        sm_en[m] = sm_st.size();
        sm_st.pb(m);
    }
    tr.pb(vector<int>(64, -1));
    forn(z, 64) {
        if ((m >> z) & 1) continue;
        tr[num][z] = dfs(add(m, z));
        cantr[z].pb(num);
    }
    return num;
}

const int maxn = 110000;
vector<pii> e[maxn];
int vis[maxn];
int x[maxn];

void dfsG(int v, int p, vi &cnt, int &b) {
    vis[v] = 1;
    for (auto [u, w]: e[v]) {
        if (u == p) continue;
        if (vis[u] == 2) continue;
        if (vis[u] == 1) {
            if (u == 0) ++cnt[x[v] ^ w];
            else if (b != -1) {
                int c = x[v] ^ x[u] ^ w;
//                cerr << v << ' ' << p << ' ' << u << ' ' << b << ' ' << c << ' ';
                if ((st[b] >> c) & 1) b = -1;
                else b = tr[b][c];
//                cerr << b << '\n';
            }
            continue;
        }
        x[u] = x[v] ^ w;
        dfsG(u, v, cnt, b);
    }
    vis[v] = 2;
}

const i64 P = 1000000000 + 7;

i64 dp[3000], ndp[3000];
int isnon0[3000];
int vdp[3000], vndp[3000];

int V = 0;

i64 &get_ndp(int i) {
    if (vndp[i] != V) {
        ndp[i] = 0;
        vndp[i] = V;
    }
    return ndp[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    dfs(1);
    col.resize(st.size());

    vi sms;
    forn(i, st.size()) {
        if (!((st[i] >> 32))) sms.pb(i);
        col[i] = en[st[i] & ((1ULL << 32) - 1)];
    }

    int n, m;
    cin >> n >> m;
    forn(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        e[u].pb({v, w});
        e[v].pb({u, w});
    }

    dp[0] = 1;
    isnon0[0] = 1;
    vi non0 = {0};
    vis[0] = 1;

    for (auto [v, w]: e[0]) {
        if (vis[v]) continue;
        vi cnt(32);
        x[v] = w;
        int b = 0;
        cnt[0] = 1;
        dfsG(v, 0, cnt, b);
        if (b == -1) {
//            cerr << v << ' ' << b << '\n';
            continue;
        }
/*        cerr << v << ' ' << bitset<64>(st[b]) << '\n';
        forn(j, 32) cerr << cnt[j] << ' ';
        cerr << '\n';*/
        ++V;
        vi nnon0;
        for (int i: non0) {
            if ((st[i] & st[b]) != 1) continue;
            int ni = badd(i, b);
            if (vndp[ni] != V) nnon0.pb(ni);
            (get_ndp(ni) += dp[i]) %= P;
        }

        forn(k, 32) {
            if (!cnt[k]) continue;
            for (int i: nnon0) {
                int ni = tr[i][32 + k];
                if (ni == -1) continue;
                if (vndp[ni] != V) nnon0.pb(ni);
                (get_ndp(ni) += ndp[i] * cnt[k]) %= P;
            }
        }

        for (int i: nnon0) {
            if (!(st[i] >> 32)) continue;
//            cerr << bitset<64>(st[i]) << ' ' << ndp[i] << '\n';
            int to = col[i];
            if (!isnon0[to]) {
                non0.pb(to);
                isnon0[to] = 1;
            }
            (dp[to] += ndp[i]) %= P;
        }
    }

    i64 ans = 0;
    forn(i, st.size()) (ans += dp[i]) %= P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}