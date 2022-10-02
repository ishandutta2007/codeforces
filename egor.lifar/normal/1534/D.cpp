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
const int Mod = 998244353;


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
 

const int MAXN = 2005;


int n;
vector<int> d[MAXN];


vector<int> myquery(int x) {
    if (!d[x].empty()) {
        return d[x];
    }
    cout << "? " << x + 1 << endl;
    vector<int> dists;
    dists.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> dists[i];
    }
    return dists;
}


vector<pair<int, int> > who[MAXN];
vector<pair<int, int> > ans;
vector<int> kd[MAXN];


void build(int u) {
    if (who[u].empty()) {
        return;
    }   
    for (int i = 0; i <= n; i++) {
        kd[i].clear();
    }
    kd[0].pb(u);
    for (int i = 0; i < sz(who[u]); i++) {
        kd[who[u][i].first].pb(who[u][i].second);
    }
    int cost = 0;
    for (int i = 1; i <= n; i+= 2) {
        cost += sz(kd[i]);
    }
    int cost1 = 0;
    for (int i = 2; i <= n; i+= 2) {
        cost1 += sz(kd[i]);
    }
    int t;
    if (cost < cost1) {
        t = 1;
    } else {
        t = 0;
    }
    for (int i = t; i <= n; i+= 2) {
        for (auto h: kd[i]) {
            d[h] = myquery(h);
            for (int j = 0; j < n; j++) {
                if (d[h][j] == 1) {
                    ans.pb(mp(h, j));
                }
            } 
        }
    }
}



void solve() {
    cin >> n;
    d[0] = myquery(0);
    for (int i = 1; i < n; i++) {
        who[0].pb(mp(d[0][i], i));
    }
    build(0);
    cout << "!" << endl;
    for (auto x: ans) {
        cout << x.first + 1 << ' ' << x.second + 1 << endl;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
   // read(FILENAME);
    int t;
    t = 1;
  //  cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}