/*
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//*/

#include <bits/stdc++.h>

// #include <atcoder/all>
// #include <atcoder/modint>

using namespace std;
// using namespace atcoder;

#define DEBUG(x) cerr << #x << ": " << x << endl;
#define DEBUG_VEC(v)                                        \
    cerr << #v << ":";                                      \
    for (int iiiiiiii = 0; iiiiiiii < v.size(); iiiiiiii++) \
        cerr << " " << v[iiiiiiii];                         \
    cerr << endl;
#define DEBUG_MAT(v)                            \
    cerr << #v << endl;                         \
    for (int i = 0; i < v.size(); i++) {        \
        for (int j = 0; j < v[i].size(); j++) { \
            cerr << v[i][j] << " ";             \
        }                                       \
        cerr << endl;                           \
    }
typedef long long ll;
// #define int ll

#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>
#define vll vector<vector<ll>>
#define vs vector<string>
#define pii pair<int, int>
#define pis pair<int, string>
#define psi pair<string, int>
#define pll pair<ll, ll>
template <class S, class T>
pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) {
    return pair<S, T>(s.first + t.first, s.second + t.second);
}
template <class S, class T>
pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first - t.first, s.second - t.second); }
template <class S, class T>
ostream &operator<<(ostream &os, pair<S, T> p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}
#define X first
#define Y second
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define rrep1(i, n) for (int i = (int)(n); i > 0; i--)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(), c.end()
void YES(bool t = true) {
    cout << (t ? "YES" : "NO") << endl;
}
void Yes(bool t = true) { cout << (t ? "Yes" : "No") << endl; }
void yes(bool t = true) { cout << (t ? "yes" : "no") << endl; }
void NO(bool t = true) { cout << (t ? "NO" : "YES") << endl; }
void No(bool t = true) { cout << (t ? "No" : "Yes") << endl; }
void no(bool t = true) { cout << (t ? "no" : "yes") << endl; }
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = (ll)1e18 + 1;
const long double pi = 3.1415926535897932384626433832795028841971L;
int popcount(ll t) { return __builtin_popcountll(t); }
// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {0, 1, 0, -1}, dy = {-1, 0, 1, 0};
// vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
struct Setup_io {
    Setup_io() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(25);
    }
} setup_io;
// const ll MOD = 1000000007;
const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

const int N = 300011;
vii G(N);

bool dfs(int now, int tar, vector<int> &used, vi &path) {
    path.push_back(now);
    used[now] = true;
    if (now == tar) {
        return true;
    }

    for (int ch : G[now]) {
        if (used[ch]) continue;
        if (dfs(ch, tar, used, path)) return true;
    }
    path.pop_back();
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int q;
    cin >> q;
    vi cnt(n);
    vector<pii> ab(q);
    rep(i, q) {
        cin >> ab[i].first >> ab[i].second;
        ab[i].first--;
        ab[i].second--;

        cnt[ab[i].first]++;
        cnt[ab[i].second]++;
    }

    int odd_cnt = 0;
    rep(i, n) {
        if (cnt[i] % 2 == 1) odd_cnt++;
    }

    if (odd_cnt) {
        NO();
        cout << odd_cnt / 2 << endl;
        return;
    }

    YES();

    vii ans(q);
    vii u2i(n);
    rep(i, q) {
        auto [a, b] = ab[i];
        u2i[a].push_back(i);
        u2i[b].push_back(i);
    }
    vector<int> done(q);

    vi used(n), nused(n);
    vi path, npath;
    vi idx(n);
    rep(i, q) {
        if (done[i]) continue;

        auto [a, b] = ab[i];
        done[i] = true;
        path.clear();
        fill(all(used), 0);

        dfs(a, b, used, path);

        ans[i] = path;
        // DEBUG_VEC(path);

        while (b != a) {
            int ni;
            while (true) {
                ni = u2i[b].back();
                u2i[b].pop_back();
                if (done[ni]) continue;
                break;
            }
            done[ni] = true;
            // DEBUG(ni);

            int nb = ab[ni].first + ab[ni].second - b;
            npath.clear();
            fill(all(nused), 0);
            dfs(nb, b, nused, npath);
            // DEBUG_VEC(npath);

            fill(all(idx), inf);
            rep(i, path.size()) idx[path[i]] = i;

            pii mi(inf, inf);
            rep(i, npath.size()) {
                int u = npath[i];
                if (idx[u] != inf) {
                    mi = pii(idx[u], i);
                    break;
                }
            }

            int i1 = mi.first;
            int i2 = mi.second;

            // DEBUG(pii(i1, i2));

            int last_pop;
            for (int j = path.size() - 1; j >= i1; j--) {
                ans[ni].push_back(path[j]);
                last_pop = path.back();
                path.pop_back();
            }
            path.push_back(last_pop);
            for (int j = i2 - 1; j >= 0; j--) {
                ans[ni].push_back(npath[j]);
                path.push_back(npath[j]);
            }

            // DEBUG_VEC(path);
            if (ans[ni].back() != ab[ni].second) {
                reverse(all(ans[ni]));
            }

            b = nb;
        }
    }

    rep(i, ans.size()) {
        cout << ans[i].size() << endl;
        for (int u : ans[i]) {
            cout << u + 1 << " ";
        }
        cout << endl;
    }
}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}