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


int n;
char c[100][100];


void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = '.';
        }
    }
    int opt = 1e9;
    for (int t = 1; t <= n; t++) {
        int f = n - t * t;
        if (f < 0 || f % 2 != 0) {
            continue;
        }
        int need = f / 2;
        int can = t;
        int cnt = t;
        vector<int> st;
        for (int i = 0; i < t; i++) {
            st.pb(t);
        }
        for (int i = can; i >= 1; i--) {
            while (need >= i) {
                need -= i;
                st.pb(i);
                cnt++;
            }
        }
        if (cnt < opt) {
            opt = cnt;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    c[i][j] = '.';
                }
            }
            for (int i = cnt - 1; i >= 0; i--) {
                for (int k = 0; k < st[cnt - i - 1]; k++) {
                    c[i][k] = 'o';
                }
            }
            for (int i = 0; i < cnt; i++) {
                for (int k = 0; k < st[i]; k++) {
                    c[cnt - 1 - k][i] = 'o';
                }
            }
        }
    }
    if (opt > 1e8) {
        cout << -1 << '\n';
        return;
    }
    cout << opt << '\n';
    for (int i = 0; i < opt; i++) {
        for (int j = 0; j < opt; j++) {
            cout << c[i][j];
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
    t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}