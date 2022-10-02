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
const int Mod =  998244353;


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



int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int a[100][100];
int b[100][100];

void solve() {
    int h, w;
    cin >> h >> w;
    vector<pair<int, int> > pos;
    for (int i = 0; i < w; i++) {
        pos.pb(mp(0, i));
    }
    for (int i = 1; i < h; i++) {
        pos.pb(mp(i, w - 1));
    }
    for (int i = w - 2; i >= 0; i--) {
        pos.pb(mp(h - 1, i));
    }
    for (int i = h - 2; i >= 1; i--) {
        pos.pb(mp(i, 0));
    }
    int opt = -1;
    for (int start = 0; start < sz(pos); start++) {
        memset(a, 0, sizeof(a));
        int cnt = 0;
        for (int i = start; i < sz(pos); i++) {
            auto x = pos[i];
            bool bad = false;
            for (int k = 0; k < 8; k++) {
                int ni = x.first + dx[k];
                int nj = x.second + dy[k];
                if (ni < 0 || nj < 0 || ni >= h || nj >= w) {
                    continue;
                }
                if (a[ni][nj]) {
                    bad = true;
                    break;
                }
            }
            if (!bad) {
                a[x.first][x.second]++;
                cnt++;
            }
        }
        for (int i = 0; i < start; i++) {
            auto x = pos[i];
            bool bad = false;
            for (int k = 0; k < 8; k++) {
                int ni = x.first + dx[k];
                int nj = x.second + dy[k];
                if (ni < 0 || nj < 0 || ni >= h || nj >= w) {
                    continue;
                }
                if (a[ni][nj]) {
                    bad = true;
                    break;
                }
            }
            if (!bad) {
                a[x.first][x.second]++;
                cnt++;
            }
        }
        if (cnt > opt) {
            opt = cnt;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    b[i][j] = a[i][j];
                }
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << b[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    int t;
    cin >> t;
   // t = 1;
    while (t--) {
        solve();
    }
    return 0;
}