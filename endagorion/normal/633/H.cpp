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

int n, m;
const int maxn = 30001;
int a[maxn], ca[maxn];
int K;

void add(int &x, int y) {
    x += y;
    x %= m;
}

struct TRes {
    int a[3][3];

    TRes(){}

    TRes(int x) {
        forn(i, 3) forn(j, 3) a[i][j] = 0;
        if (x == -1) forn(i, 3) a[i][i] = 1;
        else {
            a[0][0] = 1;
            a[0][1] = x % m;
            a[1][1] = 1;
            a[1][2] = 1;
            a[2][1] = 1;
        }
    }

    TRes operator*(const TRes &rhs) const {
        TRes c;
        forn(i, 3) forn(j, 3) c.a[i][j] = 0;
        forn(i, 3) forn(j, 3) if (a[i][j]) forn(k, 3) add(c.a[i][k], a[i][j] * rhs.a[j][k]);
        return c;
    }
};



struct TNode {
    int L, R;
    int l, r;
    int w;
    TRes res;
};

TNode t[2 * maxn];
const int BUBEN = 200, NEBUB = maxn / BUBEN + 1;
int tc = 0;

#define dn TNode &n = t[node]

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, 0, TRes(-1)};
    if (R - L > 1) {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
    }
    return node;
}

void relax(int node) {
    dn;
    n.res = t[n.r].res * t[n.l].res;
}

bool change(int node, int i, int x) {
    dn;
    if (i < n.L || i >= n.R) return false;
    if (n.R - n.L == 1) {
        int nw = n.w + x;
        bool ch = (n.w > 0) != (nw > 0);
        if (ch) {
            n.res = TRes(nw == 0 ? -1 : a[n.L]);
        }
        n.w = nw;
        return ch;
    }
    if (change(n.l, i, x) || change(n.r, i, x)) {
        relax(node);
        return true;
    } else return false;
}

vector<pii> qs[NEBUB][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n >> m;
    forn(i, n) cin >> a[i];
    {
        vi alla(a, a + n);
        sort(all(alla));
        alla.erase(unique(all(alla)), alla.end());
        forn(i, n) ca[i] = lower_bound(all(alla), a[i]) - alla.begin();
        forn(i, alla.size()) a[i] = alla[i];
        K = alla.size();
    }

    int q;
    cin >> q;

    int cb = n / BUBEN + 1;

    forn(qi, q) {
        int l, r;
        cin >> l >> r;
        --l;
        qs[l / BUBEN][r].pb(mp(qi, l));
    }

    vi ans(q, -1);

    forn(i, cb) {
//        cerr << i << '\n';
        tc = 0;
        int root = buildTree(0, K);
        int L = i * BUBEN;
        int l0 = L;
        for (int r = L + 1; r <= n; ++r) {
            change(root, ca[r - 1], 1);
            for (auto [qi, l]: qs[i][r]) {
                while (L < l) change(root, ca[L++], -1);
                while (L > l) change(root, ca[--L], 1);
                auto &res = t[root].res;
/*                cerr << qi << '\n';
                forn(i, 3) {
                    forn(j, 3) cerr << res.a[i][j] << ' ';
                    cerr << '\n';
                }*/
                ans[qi] = res.a[0][1];
            }
        }
    }
    forn(i, q) cout << ans[i] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}