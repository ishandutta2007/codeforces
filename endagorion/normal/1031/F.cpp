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

const int maxa = 1000000;
int mind[maxa + 1], vid[maxa + 1];
vi ps;

vi pows(int n) {
    vi res;
    while (n > 1) {
        int p = mind[n], z = 0;
        while (n % p == 0) n /= p, ++z;
        res.pb(z);
    }
    sort(rall(res));
    return res;
}

int dist_stupid(vi v, vi u) {
    int K = (int)max(v.size(), u.size());
    v.resize(K);
    u.resize(K);
    int ans = 0;
    forn(i, K) ans += abs(v[i] - u[i]);
    return ans;
}

vector<unordered_map<i64, int> > dd;
map<i64, vi> pres;
vvi pdist;
int LIM = 8;
vvi vs;

void rec(vi &v, int i, i64 Q, int d, int ub, int p) {
//    assert(Q > 0);
    if (d > LIM) return;
    if (i == v.size() && (!dd[p].count(Q) || dd[p][Q] > d)) {
        //        cerr << p << ' ' << Q << ' ' << d << '\n';
        if (!dd[p].count(Q)) pres[Q].pb(p);
        dd[p][Q] = d;
        for (int pp: pres[Q]) {
            int D = d + dd[pp][Q];
            uin(pdist[pp][p], D);
            uin(pdist[p][pp], D);
        }
    }
    bool last = false;
    if (i >= v.size()) v.pb(0), last = true;
    int lb = 0;
//    cerr << p << ' ' << i << ' ' << Q << ' ' << d << ' ' << lb << ' ' << ub << '\n';
    uin(ub, v[i] + LIM - d);
    uax(lb, v[i] - (LIM - d));
//    cerr << p << ' ' << i << ' ' << Q << ' ' << d << ' ' << lb << ' ' << ub << '\n';
//    for (int x: v) cerr << x << ' ';
//    cerr << '\n';
    if (d + min(abs(v[i] - lb), abs(v[i] - ub)) <= LIM) {
        fore(x, lb, ub) {
            if (last && !x) continue;
            if (x >= v[i] && d + x - v[i] > LIM) break;
            i64 nQ = Q / (v[i] + 1) * (x + 1);
            swap(x, v[i]);
            rec(v, i + 1, nQ, d + abs(x - v[i]), v[i], p);
            swap(x, v[i]);
        }
    }
    if (last) v.pop_back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    forn(i, maxa + 1) mind[i] = i;
    fore(i, 2, maxa) {
        if (i == mind[i]) ps.pb(i);
        for (i64 p: ps) {
            if (p > mind[i] || p * i > maxa) break;
            mind[i * p] = p;
        }
    }

    map<vi, int> svs;
    for1(i, maxa) {
        auto v = pows(i);
        if (!svs.count(v)) {
            int z = vs.size();
            svs[v] = z;
            vs.pb(v);
        }
        vid[i] = svs[v];
    }
    cerr << vs.size() << '\n';
    dd.resize(vs.size());
    pdist = vvi(vs.size(), vi(vs.size(), 1e9));
//    forn(i, vs.size()) pdist[i][i] = 0;
//    for (auto x: vs) for (auto y: vs) uax(LIM, dist_stupid(x, y));
    forn(i, vs.size()) {
        i64 Q = 1;
        for (int x: vs[i]) Q *= x + 1;
        rec(vs[i], 0, Q, 0, 1e9, i);
/*        cerr << i << ": ";
        for (int x: vs[i]) cerr << x << ' ';
        cerr << '\n';
        for (auto [q, d]: dd[i]) cerr << i << ' ' << q << ' ' << d << '\n';*/
 //       cerr << i << ' ' << dd[i].size() << '\n';
    }

//    forn(i, vs.size()) forn(j, vs.size()) cerr << pdist[i][j] << ' ';
//    cerr << '\n';

    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        cout << pdist[vid[a]][vid[b]] << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}