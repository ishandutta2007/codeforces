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
template<typename T1, typename T2> inline bool chkmin(T1 &a, const T2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<typename T1, typename T2> inline void chkmax(T1 &a, const T2 &b) {if (a < b) a = b;}
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



int n, m;
int xa[105], ya[105], xb[105], yb[105];
int dp[105][1 << 14];
int mind[1 << 14];
int res[1 << 14][16];
int res1[1 << 14][105];
vector<pair<int, int> > kt[1 << 14];
vector<int> kt1[1 << 14];
int t[105];
vector<pair<int, int> > need[1 << 14];
int uk[1 << 14];
bool needs[1 << 14];


void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> xa[i] >> ya[i];
    }
    vector<pair<int, int > > st;
    for (int i = 0; i < m; i++) {
        cin >> xb[i] >> yb[i] >> t[i];
        st.pb(mp(t[i], i));
    }
    sort(all(st));
    for (int i = 0; i < (1 << n); i++) {
        mind[i] = 1e9 + 2000;
    }
    mind[0] = 0;
    for (int i = 0; i < n; i++) {
        mind[(1 << i)] = 0;
    }
    for (int i = 0; i < m; i++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            dp[i][mask] = -1e9;
        }
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> st;
        for (int j = 0; j < n; j++) {
            if (mask & (1 << j)) {
                st.pb(j);
            }
        }
        for (int j = 0; j < n; j++) {
            res[mask][j] = 1e9 + 2000;
            for (auto x: st) {
                chkmin(res[mask][j], abs(xa[x] - xa[j]) + abs(ya[x] - ya[j]));
            }
        }
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> st;
        for (int j = 0; j < n; j++) {
            if (mask & (1 << j)) {
                st.pb(j);
            }
        }
        for (int j = 0; j < m; j++) {
            res1[mask][j] = 1e9 + 2000;
            for (auto x: st) {
                chkmin(res1[mask][j], abs(xa[x] - xb[j]) + abs(ya[x] - yb[j]));
            }
        }
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int j = 0; j < n; j++) {
            if (!(mask & (1 << j))) {
                kt[mask].pb(mp(mask | (1 << j), res[mask][j]));
            }
        }
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int j = 0; j < n; j++) {
            if (!(mask & (1 << j))) {
                kt1[mask].pb(j);
            }
        }
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int j = 0; j < n; j++) {
            if (!(mask & (1 << j))) {
                chkmin(mind[mask | (1 << j)], mind[mask] + res[mask][j]);
            }
        }
    }
    for (int i = 0; i < m; i++) {
        chkmax(dp[i][0], 1);
    }
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < m; i++) {
            if (st[i].first - mind[mask] >= res1[mask][st[i].second]) {
                chkmax(dp[i][mask], 1);
            }
        }
    }
    // cout << res1[5][8] << ' ' << xb[8] << ' ' << yb[8] << endl;
    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        need[mask].clear();
        for (int j = 0; j < m; j++) {
            int val = st[j].first - res1[mask][st[j].second];
            need[mask].pb(mp(val, j));
        }
        sort(all(need[mask]));
    }
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int mask = 0; mask < (1 << n); mask++) {
                if (st[j].first - st[i].first >= min(res1[mask][st[j].second], abs(xb[st[i].second] - xb[st[j].second]) + abs(yb[st[i].second] - yb[st[j].second]))) {
                    chkmax(dp[j][mask], dp[i][mask] + 1);
                }
            }
        }
        for (int mask = 0; mask < (1 << n); mask++) {
            uk[mask] = sz(need[mask]) - 1;
        }
        for (int mask = 0; mask < (1 << n); mask++) {
            mind[mask] = 1e9 + 2000;
        }
        for (int f = i + 1; f >= 1; f--) {
            bool was = false;
            for (int mask = 0; mask < (1 << n); mask++) {
                needs[mask] = false;
            }
            for (int mask = 0; mask < (1 << n); mask++) {
                if (dp[i][mask] == f) {
                    if (chkmin(mind[mask], st[i].first)) {
                        was = true;
                        needs[mask] = true;
                    }
                    for (auto f: kt1[mask]) {
                        if (chkmin(mind[mask | (1 << f)], st[i].first + abs(xb[st[i].second] - xa[f]) + abs(yb[st[i].second] - ya[f]))) {
                            was = true;
                            needs[mask | (1 << f)] = true;
                        }
                    }
                }
            }
            if (was) {
                for (int mask = 0; mask < (1 << n); mask++) {
                    if (mind[mask] > 1e9 + 5) {
                        continue;
                    }
                    if (!needs[mask]) {
                        continue;
                    }
                    for (const auto &jj: kt[mask]) {
                        if (chkmin(mind[jj.first], mind[mask] + jj.second)) {
                            needs[jj.first] = true;
                        }
                    }
                }
                for (int mask = 0; mask < (1 << n); mask++) {
                    while (uk[mask] >= 0 && need[mask][uk[mask]].first >= mind[mask]) {
                        chkmax(dp[need[mask][uk[mask]].second][mask], f + 1);
                        uk[mask]--;
                    }   
                }
            }
        }
        for (int mask = 0; mask < (1 << n); mask++) {
            chkmax(ans, dp[i][mask]);
        }
    } 
    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    int t;
    t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}