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

const int maxn = 110000;
int a[maxn];
int ind[maxn];
vi occ[maxn];
int gap[maxn];
int gl[maxn];

int fenw[maxn];

void fadd(int i, int x) {
    for (; i < maxn; i |= i + 1) fenw[i] += x;
}

int fsum(int i) {
    int s = 0;
    for (; i >= 0; i &= i + 1, --i) s += fenw[i];
    return s;
}

struct TNode {
    int L, R;
    int l, r;
    int x;
};

int tc = 0;
TNode t[2 * maxn];

#define dn TNode &n = t[node]

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, (int)1e9};
    if (R - L > 1) {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
    }
    return node;
}

void relax(int node) {
    dn;
    n.x = min(t[n.l].x, t[n.r].x);
}

void setx(int node, int i, int x) {
    dn;
    if (i < n.L || i >= n.R) return;
    if (n.R - n.L == 1) {
        n.x = x;
        return;
    }
    setx(n.l, i, x);
    setx(n.r, i, x);
    relax(node);
}

int segmin(int node, int L, int R) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return 1e9;
    if (L <= n.L && n.R <= R) return n.x;
    return min(segmin(n.l, L, R), segmin(n.r, L, R));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n;
    forn(i, n) {
        cin >> a[i];
        --a[i];
        ind[i] = occ[a[i]].size();
        occ[a[i]].pb(i);
    }

    int q;
    cin >> q;
    vi L(q), R(q);


    forn(i, q) {
        cin >> L[i] >> R[i];
        --L[i];
    }

    vi ord(q);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j){return R[i] < R[j];});

    int GL = 0;
    forn(i, maxn) gap[i] = -1;
    int ptr = 0;
    vi ans(q);

    int root = buildTree(0, n);

    for1(r, n) {
        fadd(r - 1, 1);
        if (ind[r - 1]) {
            int x = a[r - 1], i = ind[r - 1];
            vi &pos = occ[x];
            fadd(pos[i - 1], -1);
            int ngap = r - 1 - pos[i - 1];
            if (gap[x] == -1) gap[x] = ngap;
            if (gap[x] != ngap) gl[x] = pos[i - 2] + 1, gap[x] = ngap;
            setx(root, pos[i - 1], 1e9);
            setx(root, pos[i], gl[x]);
        } else setx(root, r - 1, 0);

        while (ptr < q && R[ord[ptr]] == r) {
            int id = ord[ptr++];
            ans[id] = fsum(R[id] - 1) - fsum(L[id] - 1) + (L[id] >= segmin(root, L[id], R[id]) ? 0 : 1);
        }
    }
    forn(i, q) cout << ans[i] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}