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

string s;
const int maxn = 310000;
int par[maxn], dth[maxn];
int outd[maxn];

struct TNode {
    int l, r;
    int x, y;
    int w;
};

TNode t[maxn];
int roots[2 * maxn];
int tc = 1;

#define dn TNode &n = t[node]

int newNode(int x) {
    int node = tc++;
    dn;
    n = {0, 0, x, rand(), 1};
    return node;
}

void relax(int node) {
    dn;
    n.w = 1 + t[n.l].w + t[n.r].w;
}

int merge(int l, int r) {
    if (!l) return r;
    if (!r) return l;
    if (t[l].y < t[r].y) {
        t[l].r = merge(t[l].r, r);
        relax(l);
        return l;
    } else {
        t[r].l = merge(l, t[r].l);
        relax(r);
        return r;
    }
}

pii split(int node, int x) {
    if (!node) return {0, 0};
    dn;
    pii res;
    if (n.x < x) {
        res = split(n.r, x);
        n.r = res.fi;
        relax(node);
        res.fi = node;
    } else {
        res = split(n.l, x);
        n.l = res.se;
        relax(node);
        res.se = node;
    }
    return res;
}

int insert(int node, int x) {
    auto res = split(node, x);
    return merge(res.fi, merge(newNode(x), res.se));
}

int erase(int node, int x) {
    auto res = split(node, x);
    auto res2 = split(res.se, x + 1);
//    cerr << t[res.fi].w << ' ' << t[res2.fi].w << ' ' << t[res2.se].w << '\n';
    assert(res2.fi);
    return merge(res.fi, res2.se);
}

int below(int node, int x) {
    if (!node) return 0;
    dn;
    if (n.x < x) return t[n.l].w + 1 + below(n.r, x);
    return below(n.l, x);
}

i64 fenw[maxn];

void fadd(int i, i64 x) {
    for (; i < maxn; i |= i + 1) fenw[i] += x;
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

    int n, q;
    cin >> n >> q >> s;
    vi st = {0};
    int D = n;
    for1(i, n) par[i] = -1;
    for1(i, n) {
        char c = s[i - 1];
        if (c == '(') {
            dth[i] = D++;
            par[i] = st.back();
            ++outd[par[i]];
            st.pb(i);
            roots[dth[i]] = insert(roots[dth[i]], i);
//            cerr << "+ " << dth[i] << ' ' << i << '\n';
        } else {
            if (st.size() > 1) st.pop_back();
            --D;
        }
    }

    for1(i, n) if (par[i] != -1) fadd(i, 1LL * outd[i] * (outd[i] + 1) / 2);

    while (q--) {
        int type;
        int l, r;
        cin >> type >> l >> r;
//        cerr << type << ' ' << l << ' ' << r << '\n';
        if (type == 1) {
//            cin >> l >> r;
            fadd(par[l], -(outd[par[l]]--));
//            cerr << "- " << dth[l] << ' ' << l << '\n';
            roots[dth[l]] = erase(roots[dth[l]], l);
        } else {
            i64 ans = fsum(r) - fsum(l - 1);
            int R = roots[dth[l]];
            i64 cnt = below(R, r) - below(R, l);
//            cerr << ans << ' ' << cnt << '\n';
            ans += cnt * (cnt + 1) / 2;
            cout << ans << endl;
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}