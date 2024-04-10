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
const int Mod = 1000000007;


int sum(int a, int b) {
    return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
    return ((ll)a * b) % Mod;
}


int powm(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}


int inv(int a) {
    return powm(a, Mod - 2);
}



const int MAXN = 200228;


int n, m;
vector<pair<int, int> > g[MAXN];
int parent[MAXN];
bool was[5000][5000];
ll cnt[MAXN];
vector<int> cur[MAXN];
int who[MAXN];
int score[MAXN];


int findset(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = findset(parent[v]);
}


int add[MAXN];


void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }
    int tot = 0;
    vector<pair<int, pair<int, int> > > order, st;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        tot ^= c;
        g[a].pb(mp(b, c));
        g[b].pb(mp(a, c));
        order.pb(mp(c, mp(a, b)));
    }
    sort(all(order));
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    for (auto x: order) {
        int ta = x.second.first;
        int tb = x.second.second;
        ta = findset(ta);
        tb = findset(tb);
        if (ta != tb) {
            st.pb(x);
            parent[ta] = tb;
        }
    }
    if ((ll)n * (n - 1) / 2 - m >= n) {
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            add[i]  =0;
        }
        for (int i = 1; i <= n; i++) {
            sort(all(g[i]));
            int last = 1;
            vector<pair<int, int> > pd;
            for (auto h: g[i]) {
                if (h.first - 1 >= last) {
                    pd.pb(mp(last, h.first - 1));
                }
                last = h.first + 1;
            }
            if (last <= n) {
                pd.pb(mp(last, n));
            }
            for (auto h: pd) {
                auto f = findset(h.first);
                int f1 = findset(i);
                parent[f1] = f;
                add[h.first]++;
                add[h.second]--;
            }
        }
        int cur = 0;
        for (int i = 1; i <= n; i++) {
            cur += add[i];
            if (cur) {
                int f = findset(i);
                int f1 = findset(i + 1);
                parent[f]  =f1;
            }
        }
        ll ans = 0;
        for (auto x: order) {
            int ta = x.second.first;
            int tb = x.second.second;
            ta = findset(ta);
            tb = findset(tb);
            if (ta != tb) {
                ans += x.first;
                parent[ta] = tb;           
            }
        }
        cout << ans << '\n';
    } else {
        for (auto x: order) {
            was[x.second.first][x.second.second] = true;
            was[x.second.second][x.second.first] = true;
        }
        vector<pair<int, int> > kd;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (!was[i][j]) {
                    kd.pb(mp(i, j));
                }
            }
        }
        ll ans = 2e18;
        for (auto y: kd) {
            auto st1 = st;
            for (auto z: kd) {
                if (z == y) {
                    st1.pb(mp(tot, z));
                } else {
                    st1.pb(mp(0, z));
                }
            }
            sort(all(st1));
            for (int i = 1; i <= n; i++) {
                parent[i] = i;
            }
            ll sum = 0;
            for (auto x: st1) {
                int ta = x.second.first;
                int tb = x.second.second;
                ta = findset(ta);
                tb = findset(tb);
                if (ta != tb) {
                    parent[ta] = tb;
                    sum += x.first;
                }
            }
            chkmin(ans, sum);
        }
        for (auto x: order) {
            was[x.second.first][x.second.second] = false;
            was[x.second.second][x.second.first] = false;
        }
        cout << ans << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    int t;
   // cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}