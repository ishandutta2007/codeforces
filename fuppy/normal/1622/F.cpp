//*
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//*/

#include <bits/stdc++.h>

// #include <atcoder/all>
// #include <atcoder/maxflow>

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
vi dx = {0, 1, 0, -1}, dy = {-1, 0, 1, 0};
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

void solve() {
    int n;
    cin >> n;
    vl a(n + 1);
    vi is_prime(n + 1, 1);
    a[0] = a[1] = 0;
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (!is_prime[i]) continue;

        a[i] = rnd(1, INF);
        for (int j = 2; i * j <= n; j++) {
            int x = i * j;
            is_prime[x] = false;

            int cnt = 0;
            while (x % i == 0) {
                x /= i;
                cnt++;
            }
            if (cnt % 2 == 1) {
                a[i * j] ^= a[i];
            }
        }
    }

    vl sum(n + 1);
    rep(i, n) sum[i + 1] = sum[i] ^ a[i + 1];

    // DEBUG_VEC(a);
    // DEBUG_VEC(sum);

    ll zen = 0;
    rep1(i, n) zen ^= sum[i];

    auto out = [&](const vi &er, int n) {
        set<int> st;
        for (int x : er)
            st.insert(x);

        cout << n - (int)st.size() << endl;

        rep1(i, n) {
            if (st.count(i)) continue;
            cout << i << " ";
        }
        cout << endl;
    };

    if (zen == 0) {
        out(vi(0), n);
        return;
    }

    rep1(i, n) {
        if (zen == sum[i]) {
            out(vi(1, i), n);
            return;
        }
    }

    unordered_map<ll, vi> mp;
    rep1(i, n) mp[sum[i]].push_back(i);

    ll zz = zen;
    rep(t, 2) {
        vi er;
        ll zen = zz;
        // DEBUG(zen);
        if (t == 1) {
            zen ^= sum[n];
            er.push_back(n);
            mp[sum[n]].pop_back();
        }

        for (int i = 1; i <= n - t; i++) {
            ll zen2 = zen ^ sum[i];
            // DEBUG(pii(i, t));
            // DEBUG(zen2);

            if (mp[zen2].size() > 0) {
                int j = mp[zen2].back();

                er.push_back(j);
                er.push_back(i);

                out(er, n);
                return;
            }
        }
    }
}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}