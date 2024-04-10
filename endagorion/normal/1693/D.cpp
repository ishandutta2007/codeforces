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

const int maxn = 210000;
int a[maxn];
int R[maxn];

struct TNode {
    int L, R;
    int l, r;
    pii mx;
    int lim;
    vi els;
};

TNode t[2 * maxn];
int tc = 0;

int get_lim(const vi &a) {
    vi st;
    int ans = 1e9;
    for (int x: a) {
        while (!st.empty() && x < st.back()) {
            uin(ans, st.back());
            st.pop_back();
        }
        st.pb(x);
    }
    return ans;
}

#define dn TNode &n = t[node]

int build_tree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, {}, (int)1e9, vi(a + L, a + R)};
    n.lim = get_lim(n.els);
//    cerr << L << ' ' << R << ' ' << n.lim << '\n';
    sort(all(n.els));
    if (R - L > 1) {
        int M = (L + R) / 2;
        n.l = build_tree(L, M);
        n.r = build_tree(M, R);
        n.mx = max(t[n.l].mx, t[n.r].mx);
    } else n.mx = {a[L], L};
    return node;
}

const int NONE = -1;
const int FAIL = -2;

struct TRes {
    int L, R;

    TRes operator+(const TRes &r) const {
        if (L == NONE) return r;
        if (r.L == NONE) return *this;
        if (L == FAIL || r.L == FAIL) return {FAIL, FAIL};
        if (R > r.L) return {FAIL, FAIL};
        return {L, r.R};
    }
};

pii right_greater(int node, int L, int R, int y) {
    dn;
    if (max(L, n.L) >= min(n.R, R)) return {-1, -1};
    if (n.mx.fi < y) return {-1, -1};
    if (L <= n.L && n.R <= R && n.els[0] >= y) return {a[n.R - 1], n.R - 1};
    auto w = right_greater(n.r, L, R, y);
    if (w.fi != -1) return w;
    return right_greater(n.l, L, R, y);
}

TRes is_sorted(int node, int L, int R, int y) {
    dn;
    if (max(L, n.L) >= min(n.R, R)) return {NONE, NONE};
    if (L <= n.L && n.R <= R) {
        if (y >= n.lim) return {FAIL, FAIL};
        if (y <= n.els[0]) return {NONE, NONE};
        return {n.els[0], *(--lower_bound(all(n.els), y))};
    }
    return is_sorted(n.l, L, R, y) + is_sorted(n.r, L, R, y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

/*  int n;
    cin >> n;
    vi perm(n);
    iota(all(perm), 0);
    do {
        bool good = false;
        forn(mask, 1 << n) {
            vi inc, dec;
            forn(i, n) (((mask >> i) & 1) ? inc : dec).pb(i);
            bool ok = true;
            forn(j, (int)inc.size() - 1) ok &= perm[inc[j]] < perm[inc[j + 1]];
            forn(j, (int)dec.size() - 1) ok &= perm[dec[j]] > perm[dec[j + 1]];
            good |= ok;
        }
        bool good2 = true;
        forn(i, n) forn(j, i) forn(k, j) forn(l, k) {
//            int M = max({perm[i], perm[j], perm[k], perm[l]}), N = min({perm[i], perm[j], perm[k], perm[l]});
//            cerr << M << ' ' << N << ' ' << perm[i] << ' ' << perm[l] << '\n';
//            if (perm[i] != M && perm[i] != N && perm[l] != M && perm[l] != N) good2 = false;
            vi v = {perm[k], perm[l], perm[i], perm[j]};
            if (is_sorted(all(v)) || is_sorted(rall(v))) good2 = false;
        }
        if (good != good2) {
            cerr << good << ' ' << good2 << '\n';
            for (int x: perm) cerr << x << ' ';
            cerr << '\n';
        }
    } while (next_permutation(all(perm)));*/

    int n;
    cin >> n;
    forn(i, n) cin >> a[i];
    forn(i, n) R[i] = n;

    forn(z, 2) {
        tc = 0;
        int root = build_tree(0, n);
        int r = 0;
        forn(l, n) {
            uax(r, l);
            while (r < n) {
                int i = right_greater(root, l, r, a[r]).se;
//                cerr << l << ' ' << r << ' ' << i << '\n';
                if (i == -1) {
                    ++r;
                    continue;
                }
                auto w = is_sorted(root, l, i, a[r]);
//                cerr << l << ' ' << r << ' ' << i << ' ' << w.L << ' ' << w.R << '\n';
                if (w.L != FAIL) ++r;
                else break;
            }
//            cerr << l << ' ' << r << '\n';
            uin(R[l], r);
        }

        forn(i, n) a[i] = n - a[i] + 1;
    }

    i64 ans = 0;
    forn(i, n) ans += R[i] - i;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}