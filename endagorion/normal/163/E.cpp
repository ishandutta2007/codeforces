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

const int maxn = 110000, maxs = 1100000;
int tr[maxs][26];
int vend[maxn];
int suf[maxs];

int tc = 2;

int get_tr(int v, int c) {
    int &u = tr[v][c];
    if (!u) u = tc++;
    return u;
}

int add(const string &s) {
    int v = 1;
    for (char c: s) v = get_tr(v, c - 'a');
    return v;
}

vi e[maxs];

void build() {
    vi q = {1};
    suf[1] = 1;
    forn(cur, q.size()) {
        int v = q[cur];
        forn(c, 26) {
            if (!tr[v][c]) continue;
            int u = tr[v][c], w;
            for (w = suf[v]; w > 1 && !tr[w][c]; w = suf[w]) {}
            suf[u] = tr[w][c] != 0 && tr[w][c] != u ? tr[w][c] : w;
            e[suf[u]].pb(u);
            q.pb(u);
        }
    }
}

int T;

int tin[maxs], tout[maxs];
int isin[maxn];

void dfs0(int v) {
    tin[v] = T++;
    for (int u: e[v]) dfs0(u);
    tout[v] = T;
}

i64 fenw[maxs];

void fadd(int i, i64 x) {
    for (; i < maxs; i |= i + 1) fenw[i] += x;
}

i64 fsum(int i) {
    i64 s = 0;
    for (; i >= 0; i &= i + 1, --i) s += fenw[i];
    return s;
}

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
        string s;
        cin >> s;
        vend[i] = add(s);
    }

    build();
    for1(v, tc - 1) assert(suf[v] != 0);
    dfs0(1);
    forn(i, k) {
        fadd(tin[vend[i]], 1);
        fadd(tout[vend[i]], -1);
        isin[i] = 1;
    }

    while (n--) {
        char c;
        cin >> c;
        if (c == '?') {
            string text;
            cin >> text;
//            cerr << text << '\n';
            i64 ans = 0;
            int v = 1;
            for (char cc: text) {
                int c = cc - 'a';
                while (v > 1 && !tr[v][c]) v = suf[v];
                if (tr[v][c]) v = tr[v][c];
                ans += fsum(tin[v]);
            }
            cout << ans << '\n';
        } else {
            int id;
            cin >> id;
            --id;
            int v = vend[id];
            int z = c == '+' ? 1 : -1;
            if (isin[id] && c == '+') continue;
            if (!isin[id] && c == '-') continue;
            isin[id] ^= 1;
            fadd(tin[v], z);
            fadd(tout[v], -z);
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}