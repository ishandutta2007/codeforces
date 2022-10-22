//*
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//*/

// #include <atcoder/all>
#include <bits/stdc++.h>

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

vii G;
vector<pll> lr;
vi par;
vl score;

void pre_dfs(int now, pll plr) {
    int ch_num = G[now].size();
    if (ch_num == 0) {
        return;
    }

    ll low, high;
    low = plr.first / ch_num;
    high = (plr.second + ch_num - 1) / ch_num;
    assert(high - low <= 1);

    for (int ch : G[now]) {
        lr[ch] = pll(low, high);
        pre_dfs(ch, pll(low, high));
    }
}

pll dfs(int now) {
    ll base = 0;
    vl diff;

    int one_ch = -1;
    for (int ch : G[now]) {
        one_ch = ch;

        pll res = dfs(ch);
        base += res.first;
        diff.push_back(res.second - res.first);
    }
    sort(all(diff));
    reverse(all(diff));

    pll res = pll(score[now] * lr[now].first, score[now] * lr[now].second);

    int ch_num = G[now].size();
    if (ch_num == 0) {
        // DEBUG(now);
        // DEBUG(base);
        // DEBUG(res);
        return res;
    }
    // DEBUG_VEC(diff);

    // low
    {
        ll low, high;
        low = lr[now].first / ch_num;
        high = (lr[now].first + ch_num - 1) / ch_num;

        ll rem = lr[now].first % ch_num;

        if (low == lr[one_ch].first) {
            res.first += base;
            rep(i, rem) {
                res.first += diff[i];
            }
        } else {
            assert(rem == 0);
            res.first += base;
            rep(i, diff.size()) {
                res.first += diff[i];
            }
        }
    }
    // high
    {
        ll low, high;
        low = lr[now].second / ch_num;
        high = (lr[now].second + ch_num - 1) / ch_num;

        ll rem = lr[now].second % ch_num;

        if (low == lr[one_ch].first) {
            res.second += base;
            rep(i, rem) {
                res.second += diff[i];
            }
        } else {
            assert(rem == 0);
            res.second += base;
            rep(i, diff.size()) {
                res.second += diff[i];
            }
        }
    }
    // DEBUG(now);
    // DEBUG(base);
    // DEBUG(res);

    return res;
}

void solve() {
    ll n, k;
    cin >> n >> k;

    G.clear();
    G.resize(n);
    lr.resize(n);
    par.resize(n);
    score.resize(n);

    rep1(i, n - 1) {
        int p;
        cin >> p;
        p--;
        G[p].push_back(i);
        par[i] = p;
    }

    rep(i, n) {
        cin >> score[i];
    }

    lr[0] = pll(k, k);
    pre_dfs(0, pll(k, k));

    pll ans = dfs(0);

    // DEBUG_VEC(lr);

    cout << ans.first << endl;
}

signed main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}