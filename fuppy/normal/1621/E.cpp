/*
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

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n);
    rep(i, n) {
        cin >> a[i];
    }
    sort(all(a));
    reverse(all(a));
    while (a.size() > m)
        a.pop_back();

    reverse(all(a));

    vii b(m);
    using P = pair<pll, int>;
    vector<P> ski(m);
    rep(i, m) {
        int k;
        cin >> k;
        b[i].resize(k);
        ski[i] = P(pll(0, k), i);
        rep(j, k) {
            cin >> b[i][j];
            ski[i].first.first += b[i][j];
        }
    }

    auto judge = [](const P &a, const P &b) {
        ll sa = a.first.first, sb = b.first.first;
        ll na = a.first.second, nb = b.first.second;

        if (sa * nb != sb * na) {
            return sa * nb < sb * na;
        } else {
            return a.second < b.second;
        }
    };

    sort(all(ski), judge);

    n = m;
    vi idxs(n);
    rep(i, n) {
        idxs[ski[i].second] = i;
    }

    vi eq(n), low(n), high(n);

    rep(i, n) {
        ll s = ski[i].first.first, k = ski[i].first.second;
        eq[i] = a[i] * k < s;
    }
    rep(i, n) {
        if (i == 0) continue;
        ll s = ski[i - 1].first.first, k = ski[i - 1].first.second;
        low[i] = a[i] * k < s;
    }
    rep(i, n) {
        if (i == n - 1) continue;
        ll s = ski[i + 1].first.first, k = ski[i + 1].first.second;
        high[i] = a[i] * k < s;
    }

    vl seq(n + 1), slow(n + 1), shigh(n + 1);
    rep(i, n) {
        seq[i + 1] = seq[i] + eq[i];
        slow[i + 1] = slow[i] + low[i];
        shigh[i + 1] = shigh[i] + high[i];
    }

    rep(i, n) {
        int idx = idxs[i];
        for (ll x : b[i]) {
            ll s = ski[idx].first.first, k = ski[idx].first.second;
            ll ns = s - x, nk = k - 1;
            P nski = P(pll(ns, nk), i);

            if (judge(nski, ski[idx])) {
                int ok = -1, ng = idx;
                while (ok + 1 < ng) {
                    int mid = (ok + ng) / 2;
                    if (judge(nski, ski[mid])) {
                        ng = mid;
                    } else {
                        ok = mid;
                    }
                }

                bool flag = true;
                if (seq[ng] > 0) flag = false;
                if (a[ng] * nk < ns) flag = false;
                if (slow[idx + 1] - slow[ng + 1] > 0) flag = false;
                if (seq[n] - seq[idx + 1]) flag = false;

                if (flag)
                    cout << 1;
                else
                    cout << 0;
            } else {
                int ok = idx, ng = n;
                while (ok + 1 < ng) {
                    int mid = (ok + ng) / 2;
                    if (!judge(nski, ski[mid])) {
                        ok = mid;
                    } else {
                        ng = mid;
                    }
                }

                bool flag = true;
                if (seq[idx] > 0) flag = false;
                if (shigh[ok] - shigh[idx] > 0) flag = false;
                if (a[ok] * nk < ns) flag = false;
                if (seq[n] - seq[ng]) flag = false;

                if (flag)
                    cout << 1;
                else
                    cout << 0;
            }
        }
    }
    cout << endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}