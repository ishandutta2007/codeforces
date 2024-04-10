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

const int MAXN = 602;


int n, m;
vector<pair<int, int> > g[MAXN];
ll dist[MAXN];
ll mind[MAXN * 2];
bool used[MAXN];


void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].pb(mp(b, c));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[j] = 1e18;
            used[j] = false;
        }
        dist[i] = 0;
        while (true) {
            int opt = -1;
            for (int k = 0; k < n; k++) {
                if (used[k]) {
                    continue;
                }
                if (opt == -1 || dist[k] < dist[opt]) {
                    opt = k;
                }
            }
            if (opt == -1) {
                break;
            }
            int u = opt;
            used[u] = true;
            for (int j = 0; j < 2 * n; j++) {
                mind[j] = 1e18;
            }
            int fke = dist[u] % n;
            for (auto h: g[u]) {
                int cur = h.first + fke;
                if (cur >= n) {
                    cur -= n;
                }
                mind[cur] = mind[cur + n] = dist[u] + h.second;
            }
            ll fk = 1e18;
            for (int j = 0; j < 2 * n; j++) {
                chkmin(fk, mind[j] - j);
                chkmin(mind[j], j + fk);
            }
            for (int j = 0; j < n; j++) {
                chkmin(dist[j], min(mind[j], mind[j + n]));
            }
        }
        for (int j = 0; j < n; j++) {
            cout << dist[j] << ' ';
        }
        cout << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    int t;
 //   cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}