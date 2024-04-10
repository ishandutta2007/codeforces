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

const i64 P = 998244353;

i64 deg(i64 x, i64 d) {
    if (d < 0) d += P - 1;
    i64 y = 1;
    while (d) {
        if (d & 1) (y *= x) %= P;
        (x *= x) %= P;
        d /= 2;
    }
    return y;
}

struct TRes {
    i64 ans;
    i64 pl, sr;
    bool ch;

    TRes operator+(const TRes &r) const {
//        cerr << ans << ' ' << pl << ' ' << sr << ' ' << ch << '\n';
//        cerr << r.ans << ' ' << r.pl << ' ' << r.sr << ' ' << r.ch << '\n';
        i64 nans = (ans + r.ans) % P;
        if (r.ch) (nans += sr * r.pl) %= P;
        i64 npl = pl * (ch ? 1LL : r.pl) % P;
        i64 nsr = (r.sr + (r.ch ? 0LL : r.pl * sr)) % P;
//        cerr << nans << ' ' << npl << ' ' << nsr << ' ' << (ch | r.ch) << '\n';
//        cerr << "---\n";
        return {nans, npl, nsr, ch || r.ch};
    }
};

struct TNode {
    int L, R;
    int l, r;
    TRes res;
};

#define dn TNode &n = t[node]

const int maxt = 510000;
TNode t[maxt];
int tc = 0;
i64 p[maxt];
int ch[maxt];

void relax(int node) {
    dn;
    n.res = t[n.l].res + t[n.r].res;
}

TRes init(int i) {
    if (ch[i]) return {0, 1, deg(p[i], -1), 1};
    return {0, deg(p[i], -1), deg(p[i], -1), 0};
}

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, {}};
    if (R - L == 1) n.res = init(L);
    else {  
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
        relax(node);
    }
    return node;
}

void change(int node, int i) {
    dn;
    if (i < n.L || i >= n.R) return;
    if (n.R - n.L == 1) {
        ch[i] ^= 1;
        n.res = init(i);
        return;
    }
    change(n.l, i);
    change(n.r, i);
    relax(node);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, q;
    cin >> n >> q;
    forn(i, n) {
        cin >> p[i];
        (p[i] *= deg(100, -1)) %= P;
    }
    ch[0] = ch[n] = 1;
    int root = buildTree(0, n + 1);

    forn(i, q) {
        int x;
        cin >> x;
        change(root, --x);
        i64 ans = t[root].res.ans;
        if (ans < 0) ans += P;
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}