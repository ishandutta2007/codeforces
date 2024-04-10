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
    int mx;
};

const int maxn = 610000;
TNode t[maxn];
int tc = 0;

#define dn TNode &n = t[node]

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, 0};
    if (R - L > 1) {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
    }
    return node;
}

int l[maxn];

void assign(int node, int i, int l) {
    dn;
    if (i < n.L || i >= n.R) return;
    if (n.R - n.L == 1) {
        n.mx = l;
        return;
    }
    assign(n.l, i, l);
    assign(n.r, i, l);
    n.mx = max(t[n.l].mx, t[n.r].mx);
}

int segmax(int node, int L) {
    dn;
    if (L >= n.R) return 0;
    if (L <= n.L) return n.mx;
    return max(segmax(n.l, L), segmax(n.r, L));
}

int get_leftmost(int node) {
    dn;
    if (n.R - n.L == 1) return n.L;
    if (t[n.l].mx) return get_leftmost(n.l);
    return get_leftmost(n.r);
}

int rooti, rooth;

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
    rooti = buildTree(0, n);
    rooth = buildTree(-m, 11);
    vector<pii> plant(m);
    vi lft, smol;
    vi h(n);
    forn(i, n) l[i] = -1;
    forn(qi, m) {
        int lx = 10 - qi;
        vi nsmol;
        for (int x: smol) {
            if (h[x] > lx) {
                int l = segmax(rooti, x);
                assign(rooti, x, l + 1);
                assign(rooth, h[x], l + 1);
            } else nsmol.pb(x);
        }
        smol = nsmol;
        while (1) {
            bool any = false;
            while (t[rooti].mx) {
                bool need_mv = lft.size() < 10 || get_leftmost(rooti) < lft.back();
                if (!need_mv) break;
                any = true;
                int i = get_leftmost(rooti);
                assign(rooti, i, 0);
                assign(rooth, h[i], 0);
                lft.pb(i);
                sort(all(lft));
            }
            while (lft.size() > 10) {
                any = true;
                int i = lft.back();
                int l = segmax(rooth, h[i]);
                assign(rooti, i, l + 1);
                assign(rooth, h[i], l + 1);
                lft.pop_back();
            }
            if (!any) break;
        }

        assert(is_sorted(all(lft)));
        assert(is_sorted(all(smol)));

/*        cerr << "Lft: ";
        for (int x: lft) cerr << x << ' ';
        cerr << '\n';

        cerr << "Smol: ";
        for (int x: smol) cerr << x << ' ';
        cerr << '\n';

        cerr << "Global " << t[rooti].mx << '\n';*/

        int type;
        cin >> type;
        if (type == 1) {
            int i, x;
            cin >> i >> x;
            --i;
            x -= qi;
            h[i] = x;
            smol.pb(i), sort(all(smol));
        } else {
            int x;
            cin >> x;
            int l = 0, r = 0;
            bool done = false;
            while (l < lft.size() || r < smol.size()) {
                --x;
                if (r == smol.size() || (l < lft.size() && lft[l] < smol[r])) {
                    if (x == 0) {   
                        lft.erase(lft.begin() + l);
                        done = true;
                        break;
                    } else ++l;
                } else {
                    if (x == 0) {
                        smol.erase(smol.begin() + r);
                        done = true;
                        break;
                    } else ++r;
                }
            }
            assert(done);
        }
        int ans = segmax(rooti, 0);
        vi lftans(lft.size()), smolans(smol.size());
        ford(p, lft.size()) {
            int i = lft[p];
            lftans[p] = segmax(rooth, h[i]) + 1;
            fore(q, p + 1, lft.size() - 1) if (h[lft[q]] > h[i]) uax(lftans[p], lftans[q] + 1);
            uax(ans, lftans[p]);
        }
        ford(p, smol.size()) {
            int i = smol[p];
            smolans[p] = segmax(rooti, i) + 1;
            fore(q, p + 1, smol.size() - 1) if (h[smol[q]] > h[i]) uax(smolans[p], smolans[q] + 1);
            ford(q, lft.size()) {
                if (lft[q] < i) break;
                uax(smolans[p], lftans[q] + 1);
            }
            uax(ans, smolans[p]);
        }
        cout << ans << '\n';
/*        cerr << "In root:\n";
        for (auto [x, y]: t[root].assign) cerr << " A "<< x << ' ' << y << '\n';
        for (auto [x, y]: t[root].rassign) cerr << " R "<< x << ' ' << y << '\n';*/
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}