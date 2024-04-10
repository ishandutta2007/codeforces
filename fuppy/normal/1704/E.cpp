//*
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//*/

#include <bits/stdc++.h>

// #include <atcoder/all>

using namespace std;
// using namespace atcoder;

// #define _GLIBCXX_DEBUG

#define DEBUG(x) cerr << #x << ": " << x << endl;
#define DEBUG_VEC(v)                                        \
    cerr << #v << ":";                                      \
    for (int iiiiiiii = 0; iiiiiiii < v.size(); iiiiiiii++) \
        cerr << " " << v[iiiiiiii];                         \
    cerr << endl;
#define DEBUG_MAT(v)                                \
    cerr << #v << endl;                             \
    for (int iv = 0; iv < v.size(); iv++) {         \
        for (int jv = 0; jv < v[iv].size(); jv++) { \
            cerr << v[iv][jv] << " ";               \
        }                                           \
        cerr << endl;                               \
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
vi dx = {0, 0, -1, 1}, dy = {-1, 1, 0, 0};
vi dx2 = {1, 1, 0, -1, -1, -1, 0, 1}, dy2 = {0, 1, 1, 1, 0, -1, -1, -1};
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

int remove_edges(const vii &G, vi &in_num, const vl &a, vi &removed) {
    int n = G.size();

    queue<int> qu;
    rep(i, n) {
        if (removed[i]) {
            continue;
        }
        if (in_num[i] == 0 && a[i] == 0) {
            qu.push(i);
        }
    }

    int cnt = 0;
    while (qu.size()) {
        int u = qu.front();
        qu.pop();
        removed[u] = true;
        cnt++;

        for (int v : G[u]) {
            in_num[v]--;

            if (a[v] == 0 && in_num[v] == 0) {
                qu.push(v);
            }
        }
    }
    return cnt;
}

vi topo(const vii &G) {
    int n = G.size();

    vi in_num(n);
    rep(u, n) {
        for (int v : G[u]) {
            in_num[v]++;
        }
    }

    queue<int> qu;
    rep(i, n) {
        if (in_num[i] == 0) {
            qu.push(i);
        }
    }

    vi res;

    while (qu.size()) {
        int u = qu.front();
        qu.pop();
        res.push_back(u);

        for (int v : G[u]) {
            in_num[v]--;

            if (in_num[v] == 0) {
                qu.push(v);
            }
        }
    }
    return res;
}
void solve() {
    int n, m;
    cin >> n >> m;
    // int K;
    // cin >> K;
    // n = 1 + 3 * K;
    // m = 4 * K;

    vl a(n);
    rep(i, n) {
        // a[i] = 1;
        cin >> a[i];
        // a[i] %= MOD;
    }

    vii G(n);
    vi in_num(n);
    vi removed(n);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        in_num[v]++;
    }
    // int last = 0;
    // rep(i, K) {
    //     int u1 = last + 1, u2 = last + 2, u3 = last + 3;

    //     {
    //         int u = last, v = u1;
    //         G[u].push_back(v);
    //         in_num[v]++;
    //     }
    //     {
    //         int u = last, v = u2;
    //         G[u].push_back(v);
    //         in_num[v]++;
    //     }
    //     {
    //         int u = u1, v = u3;
    //         G[u].push_back(v);
    //         in_num[v]++;
    //     }
    //     {
    //         int u = u2, v = u3;
    //         G[u].push_back(v);
    //         in_num[v]++;
    //     }
    //     last = u3;
    // }

    int cnt = remove_edges(G, in_num, a, removed);

    ll ans = 0;
    while (cnt < n) {
        // DEBUG(cnt);
        // DEBUG_VEC(a);
        // DEBUG(ans);
        bool flag = false;
        rep(i, n) {
            if (removed[i]) {
                continue;
            }
            if (in_num[i] != 0 && a[i] == 0) {
                flag = true;
                break;
            }
        }

        if (!flag) {
            break;
        }

        static vl na(n);
        na = a;
        rep(i, n) {
            if (a[i] == 0) {
                continue;
            }
            if (removed[i]) {
                continue;
            }
            na[i]--;
            for (int u : G[i]) {
                na[u]++;
                
            }
        }

        swap(a, na);

        ans++;
        cnt += remove_edges(G, in_num, a, removed);
    }

    if (cnt == n) {
        cout << ans << endl;
        return;
    }

    vii rG(n);
    int root = -1;
    rep(u, n) {
        for (int v : G[u]) {
            rG[v].push_back(u);
        }
        if (G[u].size() == 0) {
            root = u;
        }
    }

    vi to = topo(rG);
    vl dp(n);
    assert(to[0] == root);
    dp[root] = 1;
    for (int u : to) {
        for (int v : rG[u]) {
            (dp[v] += dp[u]) %= MOD;
        }
    }

    rep(i, n) {
        ans += a[i] % MOD * dp[i] % MOD;
    }

    cout << ans % MOD << endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}