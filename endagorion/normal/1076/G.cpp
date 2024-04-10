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

const int maxn = 410000;
int a[maxn];

int m;
int allB;

struct TNode {
    int L, R;
    int l, r;
    int val;
    int tr[2][32];
};

TNode t[maxn];
int tc = 0;

#define dn TNode &n = t[node]

void fill_win(int node) {
    dn;
    forn(z, 2) forn(mask, 1 << m) {
        int canWin = mask < allB || (z ^ a[n.L]);
        n.tr[z][mask] = ((mask << 1) | canWin) & allB;
    }
}

void add_val(int node, int z) {
    if (!z) return;
    dn;
    n.val ^= z;
    forn(mask, 1 << m) swap(n.tr[0][mask], n.tr[1][mask]);
}

void push(int node) {
    dn;
    add_val(n.l, n.val);
    add_val(n.r, n.val);
    n.val = 0;
}

void relax(int node) {
    dn;
    forn(z, 2) forn(mask, 1 << m) n.tr[z][mask] = t[n.l].tr[z][t[n.r].tr[z][mask]];
}

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, 0, {}};
    if (R - L == 1) {
        fill_win(node);
    } else {    
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
        relax(node);
    }
    return node;
}

void flip_seg(int node, int L, int R) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return;
    if (L <= n.L && n.R <= R) {
        add_val(node, 1);
        return;
    }
    push(node);
    flip_seg(n.l, L, R);
    flip_seg(n.r, L, R);
    relax(node);
}

int tr_mask(int node, int L, int R, int mask) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return mask;
    if (L <= n.L && n.R <= R) return n.tr[0][mask];
    push(node);
    return tr_mask(n.l, L, R, tr_mask(n.r, L, R, mask));
}

int getflip(int node, int i) {
    dn;
    if (i < n.L || i >= n.R) return 0;
    if (n.R - n.L == 1) return n.val;
    return n.val ^ getflip(n.l, i) ^ getflip(n.r, i);
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
    cin >> n >> m >> q;
    allB = (1 << m) - 1;
    forn(i, n) {
        i64 x;
        cin >> x;
        a[i] = (x & 1) ^ 1;
    }
    int root = buildTree(0, n);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            i64 x;
            cin >> l >> r >> x;
            --l;
            if (x & 1) flip_seg(root, l, r);
        } else {
            int l, r;
            cin >> l >> r;
            --l;
            bool win = tr_mask(root, l, r, allB) & 1;
            cout << (win ? 1 : 2) << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}