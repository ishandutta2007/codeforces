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
// const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

map<vi, int> dp;

int judge(vi a, vi b) {
    dp[a] = 0;
    queue<vi> qu;
    int n = a.size();

    qu.push(a);
    while (qu.size()) {
        vi now = qu.front();
        qu.pop();
        int cost = dp[now];

        rep(i, n) {
            REP(j, i + 1, n) {
                swap(now[i], now[j]);

                if (dp.count(now) == 0) {
                    dp[now] = cost + 1;
                    qu.push(now);
                }

                swap(now[i], now[j]);
            }
        }
    }

    return dp[b];
}

template <typename T>
class Zaatsu {
    bool is_build;
    vector<T> elements;

  public:
    Zaatsu() : is_build(false) {}

    void add(T x) {
        elements.push_back(x);
    }

    void add(vector<T> x) {
        for (int i = 0; i < (int)x.size(); i++) {
            elements.push_back(x[i]);
        }
    }

    int build() {
        sort(elements.begin(), elements.end());
        UNIQUE(elements);
        is_build = true;
        return elements.size();
    }

    int operator[](T x) {
        assert(is_build);
        return lower_bound(elements.begin(), elements.end(), x) - elements.begin();
    }

    T original(int i) {
        assert(is_build);
        return elements[i];
    }
};

int solve(int n, vi a, vi b) {
    Zaatsu<int> za;
    za.add(a);
    int cnt = za.build();

    rep(i, n) {
        a[i] = za[a[i]];
        b[i] = za[b[i]];
    }

    vi num(cnt);
    vii x2i(cnt);
    vii num2x(n + 1);

    rep(i, n) {
        int x = a[i];
        num[x]++;
        num2x[num[x]].push_back(x);
        x2i[x].push_back(i);
    }

    int omit = -1;
    rrep1(nu, n) {
        if (num2x[nu].size() == 0) continue;

        omit = num2x[nu][0];
        break;
    }

    vii G(cnt);
    rep(i, n) {
        if (a[i] == omit or b[i] == omit) continue;
        G[a[i]].push_back(b[i]);
    }

    vi in_num(cnt);
    rep(i, cnt) {
        for (int v : G[i]) {
            in_num[v]++;
        }
    }

    queue<int> qu;
    rep(i, cnt) {
        if (in_num[i] == 0) qu.push(i);
    }

    int done = 0;
    while (qu.size()) {
        int u = qu.front();
        qu.pop();
        done++;

        for (int v : G[u]) {
            in_num[v]--;

            if (in_num[v] == 0) qu.push(v);
        }
    }

    if (done == cnt) {
        cout << "AC" << endl;
    } else {
        cout << "WA" << endl;
    }
    return 0;
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
    vi operator()(int n, ll x, ll y) {
        vi res(n);
        for (int i = 0; i < n; i++)
            res[i] = this->operator()(x, y);
        return res;
    }
} rnd;

signed main() {
    int t = 1;
    cin >> t;
    while (t--) {
        // dp.clear();

        int n;
        cin >> n;
        vi a(n), b(n);
        rep(i, n) {
            cin >> a[i];
            a[i]--;
        }
        rep(i, n) {
            cin >> b[i];
            b[i]--;
        }

        // int n = rnd(2, 8);
        // vi a = rnd(n, 0, n / 2);
        // DEBUG(n);
        // DEBUG_VEC(a);

        int ans_num = solve(n, a, b);

        // pair<int, vi> ma(0, vi(0));
        // for (auto itr = dp.begin(); itr != dp.end(); itr++) {
        //     chmax(ma, {itr->second, itr->first});
        // }

        // DEBUG(ma.first);
        // DEBUG_VEC(ma.second);
        // assert(ma.first == ans_num);
    }
}