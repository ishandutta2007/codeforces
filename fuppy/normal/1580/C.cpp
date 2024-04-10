//*
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

constexpr int N = 200011;
int sn = sqrt(N);

vii syuuki(sn);

int n, m;
vl x, y;
vi ts, idxs;

void solve() {
    rep(i, sn) {
        syuuki[i].resize(i);
        fill(all(syuuki[i]), 0);
    }

    vi start_date(n, -1);

    vi event(m);
    int now_event = 0;
    rep(i, m) {
        int t = ts[i], idx = idxs[i];
        idx--;

        int s = x[idx] + y[idx];

        if (t == 1) {
            start_date[idx] = i;

            if (s < sn) {
                int day = (i + x[idx]) % s;
                for (int add = x[idx]; add < x[idx] + y[idx]; add++) {
                    syuuki[s][day]++;

                    day++;
                    if (day == s) day = 0;
                }
            } else {
                for (int day = i + x[idx]; day < m; day += s) {
                    event[day]++;
                }
                for (int day = i + s; day < m; day += s) {
                    event[day]--;
                }
            }
        } else {
            if (s < sn) {
                int day = (start_date[idx] + x[idx]) % s;
                for (int add = x[idx]; add < x[idx] + y[idx]; add++) {
                    syuuki[s][day]--;

                    day++;
                    if (day == s) day = 0;
                }
            } else {
                int last_add = -1, last_erase = -1;
                for (int day = start_date[idx] + x[idx]; day < m; day += s) {
                    if (day < i) {
                        last_add = day;
                        continue;
                    }
                    event[day]--;
                }
                for (int day = start_date[idx] + s; day < m; day += s) {
                    if (day < i) {
                        last_erase = day;
                    }
                    event[day]++;
                }

                if (last_add > last_erase) now_event--;
            }

            start_date[idx] = -1;
        }

        now_event += event[i];

        int ans = 0;
        REP(s, 2, sn) {
            ans += syuuki[s][i % s];
        }
        cout << ans + now_event << endl;
    }
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
    int t = 1;
    // cin >> t;
    while (t--) {
        cin >> n >> m;
        // n = rnd(3, 4);
        // m = rnd(3, 4);
        x.resize(n);
        y.resize(n);
        rep(i, n) {
            cin >> x[i] >> y[i];
        }
        // x = rnd(n, 1, 4);
        // y = rnd(n, 1, 4);
        ts.resize(m);
        idxs.resize(m);
        vi used(n);
        rep(i, m) {
            cin >> ts[i] >> idxs[i];
            // int idx = rnd(1, n + 1);
            // idx--;
            // if (!used[idx]) {
            //     ts[i] = 1;
            //     used[idx] = true;
            // } else {
            //     ts[i] = 2;
            //     used[idx] = false;
            // }
            // idxs[i] = idx + 1;
        }

        solve();

        // DEBUG_VEC(x);
        // DEBUG_VEC(y);
        // DEBUG_VEC(ts);
        // DEBUG_VEC(idxs);

        // sn = sqrt(N);
        // vi res1 = solve();
        // sn = 1;
        // vi res2 = solve();

        // assert(res1 == res2);
    }
}