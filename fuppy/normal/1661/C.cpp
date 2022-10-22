/*
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//*/

#include <bits/stdc++.h>

// #include <atcoder/all>
// #include <atcoder/convolution>

using namespace std;
// using namespace atcoder;

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

ll solve(vl a) {
    int n = a.size();

    if (n == 1) {
        return 0;
    }

    sort(all(a));
    reverse(all(a));

    ll temp = INF;
    for (ll tar = a[0]; tar <= a[0] + 2; tar++) {
        ll taran = 0;
        ll need1 = 0;
        rep(i, n) {
            taran += tar - a[i];
            if (a[i] % 2 != tar % 2) {
                need1++;
            }
        }

        ll ans = (taran / 3) * 2;
        if (taran % 3 == 1)
            ans++;
        else if (taran % 3 == 2)
            ans += 2;

        chmax(ans, (need1 - 1) * 2 + 1);

        chmin(temp, ans);
    }
    return temp;
    // cout << temp << endl;
}

ll guchoku(vl a) {
    int n = a.size();

    sort(all(a));
    if (a[0] == a.back()) return 0;

    ll ma = a.back();
    ma += 2;
    using P = pair<vl, int>;

    map<P, ll> dp;
    dp[{a, 0}] = 0;

    queue<P> qu;
    qu.push({a, 0});
    int ans = inf;
    while (qu.size()) {
        if (ans != inf) break;

        P key = qu.front();
        auto [now, d] = key;
        qu.pop();

        int cost = dp[key];

        P nkey = key;
        nkey.second = (nkey.second + 1) % 2;

        if (dp.count(nkey) == 0) {
            dp[nkey] = cost + 1;
            qu.push(nkey);
        }

        rep(i, n) {
            vl nex = now;
            if (d == 0)
                nex[i]++;
            else
                nex[i] += 2;
            if (nex[i] > ma) continue;

            sort(all(nex));
            P nkey = {nex, (d + 1) % 2};
            if (nex[0] == nex.back()) {
                chmin(ans, cost + 1);
                break;
            }

            if (dp.count(nkey) == 0) {
                dp[nkey] = cost + 1;
                qu.push(nkey);
            }
        }
    }
    return ans;
}

struct dice {
    mt19937 mt;
    dice() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
    // [0, x)
    ll operator()(ll x) { return this->operator()(0, x); }
    // [x, y)
    ll operator()(ll x, ll y) {
        uniform_int_distribution<ll> dist(x, y - 1);
        return dist(mt);
    }
    vl operator()(int n, ll x, ll y) {
        vl res(n);
        for (int i = 0; i < n; i++)
            res[i] = this->operator()(x, y);
        return res;
    }
} rnd;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        // n = rnd(2, 5);
        vl a(n);
        // a = rnd(n, 0, 5);
        rep(i, n) cin >> a[i];

        ll ans = solve(a);
        cout << ans << " ";
        // DEBUG(ans);
        // ll ans2 = guchoku(a);
        // DEBUG(ans2);

        // if (ans != ans2) {
        //     DEBUG_VEC(a);
        //     break;
        // }
    }
    cout << endl;
}