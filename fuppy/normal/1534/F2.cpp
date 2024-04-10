//*
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
// vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
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

int cnt = 0;
#define N 400010
vii G(N, vi());
vii rG(N, vi());
vi vr;
vector<int> used(N);
vi cmp(N);

void add_edge(int from, int to) {
    //DEBUG(pii(from, to));
    G[from].push_back(to);
    rG[to].push_back(from);
}

void dfs(int v) {
    used[v] = true;
    for (int i = 0; i < G[v].size(); i++) {
        if (!used[G[v][i]]) {
            dfs(G[v][i]);
        }
    }
    vr.push_back(v);
}

void rdfs(int v, int k) {
    used[v] = true;
    cmp[v] = k;
    for (int i = 0; i < rG[v].size(); i++) {
        if (!used[rG[v][i]]) {
            rdfs(rG[v][i], k);
        }
    }
}

int scc() {
    fill(used.begin(), used.end(), false);
    vr.clear();
    for (int v = 0; v < cnt; v++) {
        if (!used[v]) dfs(v);
    }
    fill(used.begin(), used.end(), false);
    int k = 0;
    for (int i = vr.size() - 1; i >= 0; i--) {
        if (!used[vr[i]]) rdfs(vr[i], k++);
    }
    return k;
}

vector<pii> ijs;
void dfs(int now, vi &visited, vi &al) {
    visited[now] = true;
    auto [i, j] = ijs[now];
    al[j]++;

    for (int v : G[now]) {
        if (visited[v]) continue;
        dfs(v, visited, al);
    }
}

void solve() {
    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    rep(i, h) {
        cin >> s[i];
    }
    vi a(w);
    rep(i, w) {
        cin >> a[i];
    }

    vii tyou(h, vi(w, -1));
    rep(i, h) {
        rep(j, w) {
            if (s[i][j] == '#') {
                ijs.push_back(pii(i, j));
                tyou[i][j] = cnt++;
            }
        }
    }
    if (cnt == 0) {
        cout << 0 << endl;
        return;
    }

    //DEBUG_MAT(tyou);

    rep(j, w) {
        int last = -1;
        int li = -1;
        rep(i, h) {
            if (s[i][j] == '#') {
                if (last != -1) {
                    int th = tyou[i][j];
                    add_edge(last, th);
                    if (li == i - 1) {
                        add_edge(th, last);
                    }
                }

                last = tyou[i][j];
                li = i;
            }
        }
    }

    //DEBUG("aa");
    for (int j = 1; j < w; j++) {
        int ni = -1;
        rep(i, h) {
            if (s[i][j - 1] == '#') ni = i;
            if (s[i][j] == '#' && ni != -1) {
                int u = tyou[i][j];
                int v = tyou[ni][j - 1];
                add_edge(v, u);
            }
        }
    }
    //DEBUG("bb");
    for (int j = 0; j < w - 1; j++) {
        int ni = -1;
        rep(i, h) {
            if (s[i][j + 1] == '#') ni = i;
            if (s[i][j] == '#' && ni != -1) {
                int u = tyou[i][j];
                int v = tyou[ni][j + 1];
                add_edge(v, u);
            }
        }
    }
    //DEBUG("cc");

    int g = scc();

    // (j, g) -> i
    map<pii, int> high;
    vii sands(w);
    rep(j, w) {
        rep(i, h) {
            if (s[i][j] == '#') {
                sands[j].push_back(i);
            }
        }
    }
    rep(j, w) {
        rrep(idx, sands[j].size()) {
            int i = sands[j][idx];
            int u = tyou[i][j];
            int gr = cmp[u];
            high[pii(j, gr)] = idx;
        }
    }
    vii ok(h, vi(w));
    vi al(w);
    vector<int> visited(cnt);

    //DEBUG_MAT(sands);

    int l = 0;
    int ans = 0;
    for (int j = 0; j < w; j++) {
        //DEBUG(pii(l, j));
        //DEBUG(ans);
        //DEBUG_MAT(ok);
        if (sands[j].size() == 0) {
            if (l == j) {
                l++;
                continue;
            }
        } else if (l == j) {
            if (al[j] >= a[j]) {
                l++;
                continue;
            }
            rep(idx, sands[j].size()) {
                int i = sands[j][idx];
                int u = tyou[i][j];
                int gr = cmp[u];

                //DEBUG(i);
                int hi = high[pii(j, gr)];
                //DEBUG(pii(j, gr));
                //DEBUG(hi);
                if (sands[j].size() - hi >= a[j]) {
                    ok[i][j] = true;
                } else {
                    ok[i][j] = false;
                }
            }
            continue;
        } else {
            rep(idx, sands[j].size()) {
                int i = sands[j][idx];
                int u = tyou[i][j];
                int gr = cmp[u];

                //DEBUG(pii(i, j));
                int hi = high[pii(j, gr)];
                //DEBUG(hi);
                if (hi != idx) {
                    int ii = sands[j][hi];
                    ok[i][j] = ok[ii][j];
                } else {
                    if (sands[j].size() - hi < a[j]) {
                        ok[i][j] = false;
                        continue;
                    }

                    int ng = -1, okk = sands[j - 1].size();
                    while (ng + 1 < okk) {
                        int mid = (okk + ng) / 2;
                        int ii = sands[j - 1][mid];
                        if (ii >= i)
                            okk = mid;
                        else
                            ng = mid;
                    }
                    //DEBUG(okk);
                    if (okk == sands[j - 1].size()) {
                        ok[i][j] = false;
                    } else {
                        int ii = sands[j - 1][okk];
                        ok[i][j] = ok[ii][j - 1];
                    }
                }
            }
            int i = sands[j][0];
            if (ok[i][j])
                continue;
        }
        //DEBUG(pii(l, j));
        //DEBUG_MAT(ok);

        int i = sands[j - 1][0];
        int u = tyou[i][j - 1];
        ans++;
        dfs(u, visited, al);

        if (l == j) {
            l = j + 1;
        } else {
            l = j;
            for (int i : sands[j])
                ok[i][j] = false;
            j--;
        }
    }
    if (l != w) ans++;
    cout << ans << endl;
}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}