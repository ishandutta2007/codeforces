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

void easy(ll n, ll a, ll b, ll c, string s) {
    ll ac = 0, bc = 0;
    rep(i, n - 1) {
        if (s[i] == s[i + 1]) {
            if (s[i] == '0')
                ac++;
            else
                bc++;
        }
    }

    ll ans;
    if (ac > bc) {
        ac = bc + 1;
    } else if (ac < bc) {
        bc = ac + 1;
    }

    ans = ac * a + bc * b;
    cout << ans << endl;
}

ll calc(ll n, ll a, ll b, ll c, string s, bool sen) {
    int c0 = 0;
    priority_queue<int, vi, greater<int>> pq1;
    vi v2;
    int c3 = 0;

    int cb = 0;

    rep(_, 2) {
        if (s.back() == '0') {
            int cnt = 0;
            while (s.back() == '0') {
                cnt++;
                s.pop_back();
            }
            if (cnt == 1)
                c3++;
            else
                v2.push_back(cnt);
        }
        reverse(all(s));
    }

    n = s.size();
    int idx = 0;
    while (idx < n) {
        if (s[idx] == '1') {
            int cnt = 0;
            while (idx < n && s[idx] == '1') {
                cnt++;
                idx++;
            }

            cb += cnt - 1;
        } else {
            int cnt = 0;
            while (idx < n && s[idx] == '0') {
                cnt++;
                idx++;
            }

            if (cnt == 1) {
                c0++;
            } else {
                pq1.push(cnt);
            }
        }
    }

    ll ans = 0;
    ll now = 0;
    while (true) {
        if (sen) {
            sen = false;
        } else {
            if (cb == 0) break;

            now += b;
            cb--;
            chmax(ans, now);
        }

        if (c0 > 0) {
            c0--;
            cb++;
            now -= c;
        } else if (pq1.size() > 0) {
            int cc = pq1.top();
            pq1.pop();
            now += a;
            chmax(ans, now);
            cc--;

            if (cc == 1)
                c0++;
            else
                pq1.push(cc);
        } else if (v2.size() > 0) {
            int cc = v2.back();
            v2.pop_back();
            now += a;
            chmax(ans, now);
            cc--;

            if (cc == 1)
                c3++;
            else
                v2.push_back(cc);
        } else if (c3 > 0) {
            now -= c;
            c3--;
        } else {
            break;
        }
    }
    return ans;
}

void solve() {
    ll n, a, b, c;
    cin >> n >> a >> b >> c;

    string s;
    cin >> s;

    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    if (b <= c) {
        easy(n, a, b, c, s);
        return;
    }

    string ss = s;
    sort(all(ss));

    if (ss.back() == '0') {
        cout << a << endl;
        return;
    }
    if (ss[0] == '1') {
        cout << b << endl;
        return;
    }

    ll ans = 0;
    chmax(ans, calc(n, a, b, c, s, false));
    chmax(ans, calc(n, a, b, c, s, true));

    cout << ans << endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}