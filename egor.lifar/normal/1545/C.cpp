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



const int MAXN = 508;



int n;
int a[MAXN * 2][MAXN];
int cnt[MAXN][MAXN];
bool bad[MAXN][MAXN];
vector<int> v[MAXN][MAXN];
bool killed[MAXN * 2];


void solve() {
    cin >> n;
    memset(bad, 0, sizeof(bad));
    memset(cnt, 0, sizeof(cnt));
    memset(killed, 0, sizeof(killed));
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            v[j][k].clear();
        }
    }
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            a[i][j]--;
            v[j][a[i][j]].pb(i);
            cnt[j][a[i][j]]++;
        }
    }
    vector<int> keks;
     int cnte = 1;
    while (sz(keks) < n) {
        bool was = false;
        for (int i = 0; i < 2 * n; i++) {
            bool ok = false;
            for (int j = 0; j < n; j++) {
                if (cnt[j][a[i][j]] == 1) {
                    ok = true;
                }
            }
            if (!killed[i] && ok) {
                was = true;
                killed[i] = true;
                for (int j = 0; j < n; j++) {
                    cnt[j][a[i][j]]--;
                    for (auto h: v[j][a[i][j]]) {
                        if (!killed[h]) {
                            killed[h] = true;
                            for (int k = 0; k < n; k++) {
                                cnt[k][a[h][k]]--;
                            }
                        }
                    }
                }
                keks.pb(i);
            }
        }     
        if (was) {
            continue;
        }
        for (int i = 0; i < 2 * n; i++) {
            if (!killed[i]) {
                cnte = mul(cnte, 2);
                killed[i] = true;
                keks.pb(i);
                for (int j = 0; j < n; j++) {
                    cnt[j][a[i][j]]--;
                    for (auto h: v[j][a[i][j]]) {
                        if (!killed[h]) {
                            for (int k = 0; k < n; k++) {
                                cnt[k][a[h][k]]--;
                            }
                            killed[h] = true;
                        }
                    }
                }
                break;
            }
        }
    }
    cout << cnte << '\n';
    for (auto x: keks) {
        cout << x + 1 << ' ';
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