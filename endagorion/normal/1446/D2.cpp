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
int a[maxn], cnt[maxn];
vector<pii> locc[maxn], rocc[maxn];
int lupd[maxn];

int T = 0;

int mf;
int ans = 0;

void vmerge(vector<pii> &v1, vector<pii> &v2, vi &res, int b0) {
    int maxb = res.size() - 1;
    int lb, rb;
    if (b0 < 0) lb = -1e9, rb = -1;
    else if (b0 > maxb) lb = maxb + 1, rb = 1e9;
    else lb = rb = b0;
    if (lb <= 0) lb = -1e9;
    if (rb >= maxb) rb = 1e9;
    int pos2 = 0;
/*    cerr << "vmerge " << b0 << '\n';;
    for (auto [l, p]: v1) cerr << l << ' ' << p << ", ";
    cerr << '\n';
    for (auto [l, p]: v2) cerr << l << ' ' << p << ", ";
    cerr << '\n';
    for (int x: res) cerr << x << ' ';
    cerr << '\n';*/

    
    for (auto [l, p]: v1) {
        while (1) {
            int skipto = p;
            uin(skipto, pos2 + rb - b0);
            b0 += skipto - pos2;
            pos2 = skipto;
            if (skipto == p) break;
            assert(b0 == rb);
            ++b0; ++rb;
            uax(res[b0], v2[pos2++].fi);
            if (rb > maxb) rb = 1e9;
        }
//        cerr << l << ' ' << p << ' ' << b0 << ' ' << pos2 << '\n';
        if (b0 == lb) {
            --lb; uax(res[lb], l);
        }
        --b0;
        if (lb <= 0) lb = -1e9;
    }
    int p = v2.size();
    while (1) {
        int skipto = p;
        uin(skipto, pos2 + rb - b0);
        b0 += skipto - pos2;
        pos2 = skipto;
        if (skipto == p) break;
        assert(b0 == rb);
        ++b0; ++rb;
        uax(res[b0], v2[pos2++].fi);
        if (rb > maxb) rb = 1e9;
    }
/*    cerr << "becomes " << b0 << '\n';
    for (int x: res) cerr << x << ' ';
    cerr << '\n';*/
}

void dnc(int L, int R) {
    if (R - L < 2) return;
    int M = (L + R) / 2;
    ++T;
    lupd[mf] = T;
    locc[mf].clear();
    rocc[mf].clear();
    vi dist;
    fore(i, L, M - 1) {
        int x = a[i];
        if (lupd[x] < T) {
            dist.pb(x);
            locc[x].clear();
            rocc[x].clear();
            lupd[x] = T;
        }
        if (x == mf) locc[x].pb(mp(M - i - 1, -1));
        else locc[x].pb(mp(M - i - 1, locc[mf].size()));
    }
    for (int i = R - 1; i >= M; --i) {
        int x = a[i];
        if (lupd[x] < T) {
            dist.pb(x);
            locc[x].clear();
            rocc[x].clear();
            lupd[x] = T;
        }
        if (x == mf) rocc[x].pb(mp(i - M, -1));
        else rocc[x].pb(mp(i - M, rocc[mf].size()));
    }
    for (int x: dist) {
        int ls = locc[x].size(), rs = rocc[x].size();
        vi res1(ls + rs + 1, -1e9), res2(ls + rs + 1, -1e9);
        int lb0 = ls + rs - (int)locc[mf].size();
        int rb0 = ls + rs - (int)rocc[mf].size();
        if (lb0 >= 0 && lb0 < res1.size()) res1[lb0] = M - L;
        if (rb0 >= 0 && rb0 < res2.size()) res2[rb0] = R - M;
        vmerge(locc[x], locc[mf], res1, lb0);
        vmerge(rocc[x], rocc[mf], res2, rb0);
        forn(i, ls + rs + 1) uax(ans, res1[i] + res2[ls + rs - i]);

/*        cerr << x << ' ' << ls << ' ' << rs << '\n';
        cerr << lb0 << ' ' << rb0 << '\n';
        for (int x: res1) cerr << x << ' ';
        cerr << '\n';
        for (int x: res2) cerr << x << ' ';
        cerr << '\n';*/
    }
    dnc(L, M);
    dnc(M, R);
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
        int &x = a[i];
        cin >> x;
        --x; ++cnt[x];
    }

    mf = max_element(cnt, cnt + n) - cnt;
    dnc(0, n);

    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}