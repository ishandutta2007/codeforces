/*














 */
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
 
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { x = (x > y ? y: x);}
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { x = (x < y ? y: x);}
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left224
#define right right224
#define rank rank224
#define y1 y1224
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
const string FILENAME = "input";

const int mx = 1e5 + 228;
int n, m, xr, up[mx], p[mx], used[mx], tin[mx], timer;
vector<vector<pair<int, int> > > g;
vector<vector<int> > cycles;

void dfs(int v, int pv) {
    tin[v] = timer++;
    used[v] = 1;
    for (auto pp : g[v]) {
        int v1 = pp.first, w = pp.second;
        if (v1 == pv) {
            continue;
        }
        if (used[v1] == 0) {
            p[v1] = v;
            up[v1] = pp.second;
            dfs(v1, v);
        }
        else {
            if (tin[v1] < tin[v]) {
                vector<int> cur_cycle;
                cur_cycle.push_back(pp.second);
                for (int u = v; u != v1; u = p[u]) {
                    cur_cycle.push_back(up[u]);
                }
                cycles.push_back(cur_cycle);
            }
        }
    }
}

const int B = 17;
const int MX = (1 << B);
ll MOD = 1e9 + 7;

ll power(ll a, ll deg) {
    ll res = 1;
    while (deg) {
        if ((deg & 1LL) == 0) {
            a = (a * a) % MOD;
            deg >>= 1;
        }
        else {
            res = (res * a) % MOD;
            deg -= 1;
        }
    }
    return res;
}

ll inverse(ll x) {
    return power(x, MOD - 2);
}

ll _MX = inverse(MX);

void conv(ll *a, int rev) {
    for (int b = 0; b < B; ++b) {
        int mt = (1 << b) - 1;
        for (int is = 0; is < MX / 2; is++) {
            int i1 = (is & mt);
            int i = i1 + ((is ^ i1) << 1);
            i1 = i ^ (mt + 1);
            a[i] = a[i] + a[i1];
            a[i1] = a[i] - a[i1] - a[i1];
        }
    }
    for (int i = 0; i < MX; ++i) {
        a[i] = (a[i] % MOD + MOD) % MOD;
    }
    if (rev) {
        for (int i = 0; i < MX; ++i) {
            a[i] = (a[i] * _MX) % MOD;
        }
    }
}

ll a[MX], b[MX], res[MX], ways[MX];
 
void xor_convolution() {
    /*cerr << "xor_convolution" << endl;
    for (int i = 0; i < MX; ++i) {
        cerr << a[i] << " ";
    }
    cerr << endl;
    for (int i = 0; i < MX; ++i) {
        cerr << b[i] << " ";
    }
    cerr << endl;*/
    conv(a, 0);
    conv(b, 0);
    for (int i = 0; i < MX; ++i) {
        res[i] = (a[i] * b[i]) % MOD;
    }
    conv(res, 1);
    for (int i = 0; i < MX; ++i) {
        res[i] %= MOD;
    }
    /*for (int i = 0; i < MX; ++i) {
        cerr << res[i] << " ";
    }
    cerr << endl;*/
}

void init() {
    fill(res, res + MX, 0);
    res[0] = 1;
}

void handle_cycle(vector<int> &cycle) {
    fill(b, b + MX, 0);
    swap(a, res);
    fill(res, res + MX, 0);
    for (auto x : cycle) {
        b[x]++;
    }
    xor_convolution();
}

void go() {
    init();
    for (auto c : cycles) {
        handle_cycle(c);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
        xr ^= w;
    }
    dfs(0, 0);

    /*cerr << "cycles" << endl;
    for (auto c : cycles) {
        for (auto x : c) {
            cerr << x << " ";
        }
        cerr << endl;
    }
    cerr << "xr = " << xr << endl;*/

    go();
    MOD = 1e9 + 9;
    _MX = inverse(MX);
    for (int i = 0; i < MX; ++i) {
        ways[i] = res[i];
    }
    go();


    int ans = 1e9, cnt = 0;
    for (int i = 0; i < MX; ++i) {
        if (res[i] || ways[i]) {
            if (ans > (i ^ xr)) {
                ans = (i ^ xr);
                cnt = ways[i];
            }
        }
    }
    cout << ans << " " << cnt << endl;
    return 0; 
}