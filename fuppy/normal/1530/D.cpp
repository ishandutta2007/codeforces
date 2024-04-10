/*
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//*/

#include <bits/stdc++.h>

// #include <atcoder/all>

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
vi dx2 = {1, 1, 0, -1, -1, -1, 0, 1}, dy2 = {0, 1, 1, 1, 0, -1, -1, -1};
struct Setup_io {
    Setup_io() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(25);
    }
} setup_io;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

void sub1(vi &ans, vi used, vi hima, vi to) {
    int n = ans.size();

    int amari_from = hima.back();
    int amari_to;
    rep(i, n) {
        if (!used[i]) {
            amari_to = i;
            break;
        }
    }
    // DEBUG(pii(amari_from, amari_to));
    if (amari_from != amari_to) {
        ans[amari_from] = amari_to;
        return;
    }

    int x = to[amari_from];
    int from;
    rep(i, n) {
        if (ans[i] == x) {
            from = i;
            break;
        }
    }

    ans[amari_from] = x;
    ans[from] = amari_to;
}

void sub2(vi &ans, vi used) {
    int n = ans.size();
    set<int> from, to;
    rep(i, n) {
        if (ans[i] == -1) from.insert(i);
        if (!used[i]) to.insert(i);
    }

    vi a, b;
    rep(i, n) {
        if (from.count(i) && to.count(i)) {
            a.push_back(i);
            b.push_back(i);
            from.erase(i);
            to.erase(i);
        }
    }
    rep(i, n) {
        if (from.count(i)) {
            a.push_back(i);
        }
        if (to.count(i)) {
            b.push_back(i);
        }
    }
    // DEBUG_VEC(ans);
    // DEBUG_VEC(used);
    // DEBUG_VEC(a);
    // DEBUG_VEC(b);

    assert(a.size() == b.size());
    int ini = b[0];
    b.erase(b.begin());
    b.push_back(ini);
    rep(i, a.size()) {
        ans[a[i]] = b[i];
    }
}

void solve() {
    int n;
    cin >> n;
    vi to(n);
    rep(i, n) {
        cin >> to[i];
        to[i]--;
    }

    vi used(n);
    vi ans(n, -1);
    int ok = 0;
    rep(i, n) {
        int x = to[i];
        if (used[x]) continue;
        ok++;
        ans[i] = x;
        used[x] = true;
    }

    vi hima;
    rep(i, n) {
        if (ans[i] == -1) hima.push_back(i);
    }

    if (hima.size() == 0) {
    } else if (hima.size() == 1) {
        sub1(ans, used, hima, to);
    } else {
        sub2(ans, used);
    }

    cout << ok << endl;
    rep(i, n) {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}