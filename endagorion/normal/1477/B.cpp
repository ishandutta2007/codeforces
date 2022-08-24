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
    int L, R;
    int l, r;
    int val, sum;
};

const int maxn = 410000;
TNode t[maxn];
int tc = 0;
string s, f;

#define dn TNode &n = t[node]

void relax(int node) {
    dn;
    n.sum = t[n.l].sum + t[n.r].sum;
}

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, -1, 0};
    if (n.R - n.L == 1) n.sum = f[L] - '0';
    else {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
        relax(node);
    }
    return node;
}

void addval(int node, int x) {
    if (x == -1) return;
    dn;
    n.val = x;
    n.sum = (n.R - n.L) * x;
}

void push(int node) {
    dn;
    addval(n.l, n.val);
    addval(n.r, n.val);
    n.val = -1;
}

void assignSeg(int node, int L, int R, int x) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return;
    if (L <= n.L && n.R <= R) {
        addval(node, x);
        return;
    }
    push(node);
    assignSeg(n.l, L, R, x);
    assignSeg(n.r, L, R, x);
    relax(node);
}

int sumSeg(int node, int L, int R) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return 0;
    if (L <= n.L && n.R <= R) return n.sum;
    push(node);
    return sumSeg(n.l, L, R) + sumSeg(n.r, L, R);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q >> s >> f;
        vector<pii> ops(q);
        forn(i, q) cin >> ops[i].fi >> ops[i].se, --ops[i].fi;
        reverse(all(ops));
        tc = 0;
        int root = buildTree(0, n);

        bool ok = true;
        for (auto [L, R]: ops) {
            int sum = sumSeg(root, L, R);
            int len = R - L;
            if (2 * sum == len) {
                ok = false;
                break;
            }
            assignSeg(root, L, R, 2 * sum < len ? 0 : 1);
        }

        if (ok) forn(i, n) ok &= sumSeg(root, i, i + 1) == s[i] - '0';
        cout << (ok ? "YES" : "NO") << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}