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

int n;
i64 D;

struct DP {
    vi64 dists;
    vvi rdp, bdp;

    DP(int col) {
        dists = {0};
        rdp = bdp = vvi(2, vi(1, 1e9));
        bdp[1][0] = int(col != 1);
        rdp[0][0] = int(col != 0);
    }

    DP(const vi64 &dists)
        : dists(dists)
    {
        rdp = bdp = vvi(dists.size() + 1, vi(dists.size(), 1e9));
    }

    int sz() const {
        return dists.size();
    }

    void shift(i64 x) {
        for (auto &d: dists) d += x;
    }

    DP combine(const DP &r) const {
        vi nid(sz()), rnid(r.sz());
        vi64 ndists(sz() + r.sz());
        int i = 0, j = 0;
        while (i < sz() || j < r.sz()) {
            if (j == r.sz() || (i < sz() && dists[i] < r.dists[j])) {
                nid[i] = i + j;
                ndists[i + j] = dists[i];
                ++i;
            } else {
                rnid[j] = i + j;
                ndists[i + j] = r.dists[j];
                ++j;
            }
        }
//        cerr << "here=\n";
        DP res(ndists);
        const DP *p1 = this, *p2 = &r;
        const vi *id1 = &nid, *id2 = &rnid;
        forn(z, 2) {
            forn(w1, p1->sz() + 1) forn(w2, p2->sz() + 1) {
                int bv = *min_element(all(p2->bdp[w2]));
                {
                    int minv = bv, p = 0;
                    forn(ri, p1->sz()) {
                        while (p < p2->sz() && p2->dists[p] <= p1->dists[ri]) {
                            uin(minv, p2->rdp[w2][p++]);
                        }
                        uin(res.rdp[w1 + w2][(*id1)[ri]], minv + p1->rdp[w1][ri]);
                    }
                }
                {
                    int minv = bv, p = 0;
                    ford(bi, p1->sz()) {
                        while (p < p2->sz() && p2->dists[p] + p1->dists[bi] <= D) {
                            uin(minv, p2->rdp[w2][p++]);
                        }
                        uin(res.bdp[w1 + w2][(*id1)[bi]], minv + p1->bdp[w1][bi]);
                    }
                }
            }
            swap(p1, p2);
            swap(id1, id2);
        }
        return res;
    }
};

const int maxn = 510;
vector<pii> e[maxn];
int col[maxn];

DP dfs(int v, int p) {
    DP res(col[v]);
    for (auto [u, w]: e[v]) {
        if (u == p) continue;
        DP ch = dfs(u, v);
        ch.shift(w);
        res = res.combine(ch);
/*        cerr << v << " + " << u << '\n';
        for (auto d: res.dists) cerr << d << ' ';
        cerr << '\n';
        forn(i, res.sz() + 1) {
            forn(j, 2 * res.sz()) cerr << res.dp[i][j] << ' ';
            cerr << '\n';
        }*/
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n >> D;
    forn(i, n) cin >> col[i];
    forn(i, n - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        e[u].pb({v, w});
        e[v].pb({u, w});
    }

    auto res = dfs(0, -1);
    int c1 = count(col, col + n, 1);
    int ans = *min_element(all(res.bdp[c1]));
    if (ans > 1e8) ans = -2;
    cout << ans / 2 << '\n';    

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}