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

struct TNode {
    int prv, nxt, nxtk;
    int x;
};

const int maxn = 4000;
TNode t[maxn];

i64 eval(int a) {
    int b = t[a].nxt, c = t[a].nxtk;
    i64 dab = t[b].x - t[a].x;
    i64 ans = 1LL * dab * (dab - 1) / 2;
    ans += dab * (t[c].x - t[b].x);
    return ans;
}

int tc = 1;

int insert_after(int node, int x) {
    int nnode = tc++;
    TNode &n = t[nnode];
    n.prv = node;
    n.nxt = 0;
    n.x = x;
    if (node) t[node].nxt = nnode;
    return nnode;
}

void erase(int node) {
    int p = t[node].prv, n = t[node].nxt;
    if (p) t[p].nxt = n;
    if (n) t[n].prv = p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int r, c, n, k;
    cin >> r >> c >> n >> k;
    vector<pii> a(n);
    forn(i, n) cin >> a[i].fi >> a[i].se;
    i64 ans = 1LL * r * (r + 1) * c * (c + 1) / 4;
    sort(all(a));
    vvi byc(c + 1);
    forn(i, n) byc[a[i].se].pb(i);

    for1(L, c) {
        tc = 1;
        int tail = 0;
        tail = insert_after(tail, 0);
        vi nid(n);
        forn(i, n) {
            if (a[i].se >= L) {
                tail = insert_after(tail, a[i].fi);
                nid[i] = tail;
            }
        }
        forn(j, k + 1) tail = insert_after(tail, r + 1);
        int v = tail, u = tail;
        forn(i, k) v = t[v].prv;
        i64 sum = 0;
        while (v) {
            t[v].nxtk = u;
//            cerr << "E " << t[v].x << ' ' << t[t[v].nxtk].x << ' ' << eval(v) << '\n';
            sum += eval(v);
            v = t[v].prv;
            u = t[u].prv;
        }

        ans -= sum;
//        cerr << L << ' ' << c << ' ' << sum << '\n';
        for (int R = c; R > L; --R) {
            for (int i: byc[R]) {
                int v = nid[i];
                sum -= eval(v);
                for (int p = t[v].prv, z = k; p && z; p = t[p].prv, --z) {
                    sum -= eval(p);
                    t[p].nxtk = t[t[p].nxtk].nxt;
                    assert(t[p].nxtk);
                }
                int p = t[v].prv;
                erase(v);
                for (int z = k; p && z; p = t[p].prv, --z) sum += eval(p);
            }
//            cerr << L << ' ' << R - 1 << ' ' << sum << '\n';
            ans -= sum;
        }
    }

    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}