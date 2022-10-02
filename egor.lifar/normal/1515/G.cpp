/*
KAMUI!
 
 

 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

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
using ll = long long;
using ld = long double; 
const string FILENAME = "input";
const int MAXN = 200228;


int n, m;
vector<pair<int, int> > g[MAXN], rg[MAXN], v[MAXN];
bool used[MAXN];
vector<int> order;


void dfs(int u) {
    used[u] = true;
    for (auto h: g[u]) {
        if (!used[h.first]) {
            dfs(h.first);
        }
    }
    order.pb(u);
}   


int c = 0;
int col[MAXN];
int sz[MAXN];
vector<int> st;
ll gt[MAXN];
int td[MAXN];
ll sum[MAXN];


ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}


void dfs1(int u) {
    col[u] = c;
    sz[c]++;
    st.pb(u);
    used[u] = true;
    for (auto h: rg[u]) {
        if (!used[h.first]) {
            dfs1(h.first);
        }
    }
}


ll deep[MAXN];


void dfs2(int u) {
    used[u] = true;
    for (auto h: v[u]) {
        if (!used[h.first]) {
            deep[h.first] = deep[u] + h.second;
            dfs2(h.first);
        }
    } 
    for (auto h: v[u]) {
        ll fl = deep[h.first] - deep[u] - h.second;
        gt[col[u]] = gcd(gt[col[u]], fl);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        a--, b--;
        g[a].pb(mp(b, l));
        rg[b].pb(mp(a, l));
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }
    memset(used, 0, sizeof(used));
    reverse(all(order));
    for (auto x: order) {
        if (!used[x]) {
            c++;
            st.clear();
            dfs1(x);
            for (auto x: st) {
                for (auto y: g[x]) {
                    if (col[y.first] == col[x]) {
                        v[x].pb(y);
                        td[c]++;
                        sum[c] += y.second;
                    }
                }
            }
        }
    }
    memset(used, 0, sizeof(used));
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs2(i);
        }
    }
    int q;
    cin >> q;
    for (int it = 0; it < q; it++) {
        int v, s, t;
        cin >> v >> s >> t;
        v--;
        if (s == 0) {
            cout << "YES\n";
            continue;
        }
        int rem = (t - s) % t;
        int mod = t;
        if (sz[col[v]] == 1) {
            cout << "NO\n";
            continue;
        }
        {
            ll f = gcd(gt[col[v]] % mod, mod);
            if (rem % f != 0) {
                cout << "NO\n";
                continue;
            }
        }
        cout << "YES\n";
    }
    return 0;
}