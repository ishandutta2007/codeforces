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
#define int ll

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

void solve() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }

    sort(all(a));
    vi num(n);
    rep(i, n) num[a[i]]++;
    vi sum(n + 1);
    rep(i, n) {
        sum[i + 1] = sum[i] + num[i];
    }
    // DEBUG_VEC(num)

    ll res = INF;
    for (int k1 = 0; k1 <= 20; k1++) {
        ll m1 = 1 << k1;
        int ok = 0, ng = n + 1;
        while (ok + 1 < ng) {
            int mid = (ok + ng) / 2;
            if (sum[mid] <= m1)
                ok = mid;
            else
                ng = mid;
        }

        int u1 = ok;
        int n1 = sum[u1];

        for (int k2 = 0; k2 <= 20; k2++) {
            ll m2 = 1 << k2;

            int ok = u1, ng = n + 1;
            while (ok + 1 < ng) {
                int mid = (ok + ng) / 2;
                if (sum[mid] - sum[u1] <= m2)
                    ok = mid;
                else
                    ng = mid;
            }

            int u2 = ok;
            int n2 = sum[u2] - sum[u1];

            int n3 = sum[n] - sum[u2];

            ll ans = (m1 - n1) + (m2 - n2);

            if (n3 == 0)
                ans++;
            else {
                rrep(k3, 21) {
                    if (n3 & (1 << k3)) {
                        int m3 = 1 << k3;

                        if (m3 != n3) m3 <<= 1;

                        ans += m3 - n3;
                        break;
                    }
                }
            }

            // if (ans == 0) {
            //     DEBUG(u1);
            //     DEBUG(n1);
            //     DEBUG(u2);
            //     DEBUG(n2);
            //     DEBUG(n3);
            // }
            chmin(res, ans);
        }
    }
    cout << res << endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}