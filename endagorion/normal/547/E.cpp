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

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

struct TNode {
    int suf, ssuf, term;
    int tr[27];

    TNode()
        : suf(-1)
        , ssuf(-1)
        , term(0)
    {
        forn(i, 27) tr[i] = -1;
    }
};

const int MAXT = 500000;
const int MAXN = 400000;
TNode aho[MAXT];
int ac = 1;

int add(const string &s) {
    int v = 0;
    for (char c: s) {
        if (aho[v].tr[c - 'a'] == -1) {
            aho[v].tr[c - 'a'] = ac++;
        }
        v = aho[v].tr[c - 'a'];
    }
    aho[v].term = 1;
    return v;
}

void build_suf() {
    vi q;
    q.pb(0);
    int cur = 0;
    aho[0].ssuf = 0;
    while (cur < q.size()) {
        int v = q[cur++];
        forn(i, 27) {
            int u = aho[v].tr[i];
            if (u == -1) continue;
            int w;
            for (w = aho[v].suf; w >= 0 && aho[w].tr[i] == -1; w = aho[w].suf) {}
            aho[u].suf = (w == -1 ? 0 : aho[w].tr[i]);
            w = aho[u].suf;
            aho[u].ssuf = (aho[w].term ? w : aho[w].ssuf);
            q.pb(u);
        }
    }
}

void pass(int &v, char c) {
    while (v > 0 && aho[v].tr[c - 'a'] == -1) v = aho[v].suf;
    if (aho[v].tr[c - 'a'] != -1) v = aho[v].tr[c - 'a'];
}

vi e[MAXN];
int tin[MAXN], tout[MAXN];

int tt = 0;

void dfs(int v) {
    tin[v] = tt++;
    for (int u: e[v]) dfs(u);
    tout[v] = tt;
}

struct TEvent {
    int v, mul, id;

    TEvent(int v = 0, int mul = 0, int id = 0)
        : v(v)
        , mul(mul)
        , id(id)
    {
    }
};

int fenw[MAXT];

int fenw_sum(int x) {
    int s = 0;
    for (; x >= 0; x &= x + 1, --x) s += fenw[x];
    return s;
}   

void fenw_add(int x, int i) {
    for (; x < MAXT; x |= x + 1) fenw[x] += i;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N, Q;
    cin >> N >> Q;
    vector<string> s(N);
    vi end(N);
    forn(i, N) {
        cin >> s[i];
        end[i] = add(s[i]);
    }
    build_suf();
    forn(i, ac) {
        if (aho[i].term) e[aho[i].ssuf].pb(i);
    }
    
    dfs(0);
    
    string t;
    vi pref(N + 1);
    forn(i, N) {
        t += s[i] + (char)('z' + 1);
        pref[i + 1] = pref[i] + s[i].size() + 1;
    }

    vi ans(Q);
    vector< vector<TEvent> > evs(t.size() + 1);
    forn(q, Q) {
        int l, r, k;
        cin >> l >> r >> k;
        --k;
        evs[pref[l - 1]].pb(TEvent(end[k], -1, q));
        evs[pref[r]].pb(TEvent(end[k], 1, q));
    }

    int v = 0;
    vi res;
    t += (char)('z' + 1);
    forn(i, t.size()) {
        for (auto ev: evs[i]) {
            ans[ev.id] += ev.mul * (fenw_sum(tout[ev.v] - 1) - fenw_sum(tin[ev.v] - 1));
        }
        char c = t[i];
        pass(v, c);
        int u = aho[v].term ? v : aho[v].ssuf;
        fenw_add(tin[u], 1);
    }

    forn(q, Q) cout << ans[q] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}