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
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
#define rank rank228
#define int long long
using ll = long long;
using ld = long double;
const string FILENAME = "input";
const int MAXN = 1000228;
const int INF = 1e9;

int n, k;
vector<int> g[MAXN];
int timer = 0;
int in[MAXN], out[MAXN], who[MAXN];
int need[MAXN];
int prs[MAXN];
vector<int> st;


void dfs(int u, int pr = -1) {
    timer++;
    in[u] = timer;
    who[timer] = u;
    int pt = 0;
    for (auto h: g[u]) {
        if (h == pr) {
            continue;
        }
        prs[h] = u;
        dfs(h, u);
        pt++;
    }  
    need[u] = pt; 
    out[u] = timer;
    if (pt == 0) {
        st.pb(u);
    }
}


int ss;
pair<ll, int> d[MAXN];
ll mod[MAXN];



void push(int v) {
    if (mod[v] != 0) {
        d[v].first += mod[v];
        if (v < ss) {
            mod[v * 2] += mod[v];
            mod[v * 2 + 1] += mod[v];
        }
        mod[v] = 0;
    }
}


vector<int> z[MAXN];


void add(int v, int vl, int vr, int l, int r, ll val, int ve = -1) {
    if (vl > r || vr < l) {
        push(v);
        return;
    }
    if (l <= vl && vr <= r) {
        mod[v]+= val;
        if (ve != -1) {
            z[v].pb(ve);
        }
        push(v);
        return;
    }
    push(v);
    add(v * 2, vl, (vl + vr) / 2, l, r, val, ve);
    add(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r, val, ve);
    d[v] = max(d[v * 2], d[v * 2 + 1]);
}


void add(int l, int r, int v) {
    add(1, 1, ss, l, r, 1, v);
}

bool good[MAXN];



void solve() {
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }   
    dfs(1);
    ss = 1;
    while (ss <= n) {
        ss <<= 1;
    }
    for (int i = 0; i < ss; i++) {
        d[ss + i] = mp(-INF, who[i + 1]);
    }
    for (int i = ss - 1; i >= 1; i--) {
        d[i] = max(d[i * 2], d[i * 2 + 1]);
    }
    for (int i = 1; i <= n; i++) {
        add(in[i], out[i], i);
    }
    for (auto x: st) {
        add(1, 1, ss, in[x], in[x], INF);
    }
    int wr = 0;
    ll ans = -(ll)(n / 2) * (n - n  / 2);
    for (int i = 1; i <= k; i++) {
        push(1);
        int u = d[1].second;
        if (!good[u]) {
            good[u] = true;
            wr++;
            add(1, 1, ss, in[u], out[u], -1);
        }
        int t = in[u] + ss - 1;
        while (t) {
            for (auto rp: z[t]) {
                if (!good[rp]) {
                    good[rp] = true;
                    wr++;
                    add(1, 1, ss, in[rp], out[rp], -1);
                }
            }
            z[t].clear();
            t >>= 1;
        }
        add(1, 1, ss, in[u], in[u], -INF);
        need[prs[u]]--;
        if (need[prs[u]] == 0) {
            add(1, 1, ss, in[prs[u]], in[prs[u]], INF);
        }
       // cout << u << endl;
        int mb = n - wr;
        chkmax(ans, (ll)(n - i) * i - (ll)(n - min(mb, n / 2)) * min(mb, n / 2));
    }
    cout << ans << '\n';
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}