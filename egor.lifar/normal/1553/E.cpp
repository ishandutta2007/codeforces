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



const int MAXN = 300228;


int n, m;
int p[MAXN];
int used[MAXN];
int uk = 0;


int getpos(int val, int shift) {
    if (val <= n - shift) {
        return val + shift;
    }
    return val - (n - shift);
}


int good[MAXN];


void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        good[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        vector<int> cans;
        if (i + n - p[i] < n) {
            cans.pb((i + n - p[i] + 1) % n);
        }
        if (i - p[i] + 1 >= 0) {
            int len = (n - (n - (i - p[i] + 1))) % n;
            cans.pb(len);
        }
        for (auto y: cans) {
            good[y]++;
        }
    }
    vector<int> checks;
    for (int i = 0; i < n; i++) {
        if (good[i] >= n / 24) {
            checks.pb(i);
        }
    }
    vector<int> ans;
    for (auto shift: checks) {
        uk++;
        int have = m;
        for (int i = 0; i < n; i++) {
            if (used[i] != uk) {
                int cur = i;
                while (used[cur] != uk) {
                    used[cur] = uk;
                    int t = getpos(p[cur], shift) - 1;
                   // cout << cur << ' ' << t << ' ' << shift << endl;
                    if (t == i) {
                        break;
                    } 
                    cur = t;
                    have--;
                    if (have < 0) {
                        break;
                    }
                }
                if (have < 0) {
                    break;
                }
            }
        }
        if (have >= 0) {
            ans.pb(shift);
        }
    }
    cout << sz(ans);
    for (auto x: ans) {
        cout << ' ' << x;
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
 //   t = 1;
    while (t--) {
        solve();
    }
    return 0;
}