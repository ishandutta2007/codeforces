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

const int maxn = 50000;
vector<pair<int*, int> > chs;

int savep;

void change(int &x, int y) {
    if (x == y) return;
    chs.pb(mp(&x, x));
    x = y;
}

void undo() {
    auto &p = chs.back();
    *p.fi = p.se;
    chs.pop_back();
}

void save() {
//    cerr << "saved\n";
    savep = chs.size();
}

void restore() {
//    cerr << "restored\n";
    while (chs.size() > savep) undo();
}

                          
struct Trie {
    static const int maxl = 21 * maxn;
    int tr[maxl][2];
    int minkey[maxl];
    int tc;

    Trie() {
        reset();
    }

    int newNode() {
        int node = tc;
        change(tc, tc + 1);
        forn(z, 2) change(tr[node][z], 0);
        change(minkey[node], 1e9);
        return node;
    }
        
    void reset() {
        tc = 1;
        newNode();
    }

    int get_tr(int v, int b) {
        int &t = tr[v][b];
        if (!t) change(t, newNode());
        return tr[v][b];
    }

    void add(int x, int key) {
        int v = 1;
        ford(b, 20) {
            if (key < minkey[v]) change(minkey[v], key);
            int bit = (x >> b) & 1;
            v = get_tr(v, bit);
        }
        if (key < minkey[v]) change(minkey[v], key);
    }

    int maxxor(int x, int ubkey) {
        int v = 1;
        int res = x;
        ford(b, 20) {
            int bit = (x >> b) & 1;
            bit ^= 1;
            if (!tr[v][bit] || minkey[tr[v][bit]] > ubkey) bit ^= 1;
            res ^= (bit << b);
            v = tr[v][bit];
        }
//        cerr << x << ' ' << ubkey << ' ' << res << '\n';
        return res;
    }
};

Trie rbyl, lbyr;
int maxans;

int f(int x) {
    int z = x & 3;
    if (z == 0) return x;
    if (z == 1) return 1;
    if (z == 2) return x ^ 1;
    return 0;
}

void push(int x) {
    rbyl.add(f(x), -x);
    lbyr.add(f(x - 1), x);
    int res = max(rbyl.maxxor(f(x - 1), -x), lbyr.maxxor(f(x), x));
    if (res > maxans) change(maxans, res);
//    cerr << "pushed " << x << ", new maxans " << maxans << '\n';
}

void reset() {
//    cerr << "resetting\n";
    chs.clear();
    rbyl.reset(); lbyr.reset();
    maxans = -1;
}

int a[maxn];
const int BUBEN = 500;

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
    forn(i, n) cin >> a[i];

    vector< vector< vector<pii> > > qs(n / BUBEN + 2, vector<vector<pii>> (n + 1));
    vi ans(m, -1);
    forn(i, m) {
        int l, r;
        cin >> l >> r;
        --l;
        int bi = (l + BUBEN - 1) / BUBEN;
        if (bi * BUBEN >= r) {
            reset();
            fore(i, l, r - 1) push(a[i]);
            ans[i] = maxans;
        } else qs[(l + BUBEN - 1) / BUBEN][r].pb(mp(l, i));
    }

    forn(i, qs.size()) {
        int L = i * BUBEN, l0 = L;
        reset();
        for (int r = L + 1; r <= n; ++r) {
            int x = a[r - 1];
            push(x);

            for (auto [l, qi]: qs[i][r]) {
                save();
                while (L > l) {
                    int x = a[--L];
                    push(x);
                }

                ans[qi] = maxans;
//                cerr << "Q " << qi << ' ' << ans[qi] << '\n';
                restore();
                L = l0;
            }
        }
    }

    forn(i, m) cout << ans[i] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}