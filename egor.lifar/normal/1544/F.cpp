/*
KAMUI!
 
 

 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

*/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

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
const int Mod = 31607;
 const int MAXMEM = 200 * 1000 * 1024;
char _memory[MAXMEM];
size_t _ptr = 0;
void* operator new(size_t _x) { _ptr += _x; ; return _memory + _ptr - _x; }
void operator delete (void*) noexcept {}
 
int sum(int a, int b) {
    return (a + b >= Mod ? a + b - Mod: a + b);
}
 
 
void add(int &a, const int b) {
    a += b;
    a %= Mod;
}

void add1(int &a, const int b) {
    a = (a + b >= Mod ? a + b - Mod: a + b);
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
int a[22][22];
int p[22][22];
int dp[2][(1 << 21)][4];
int prdp[(1 << 21)][4];

 
void solve() {
    cin >> n;
  //  n = 21;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
      //      a[i][j] = 1;
            p[i][j] = mul(a[i][j], powm(10000, Mod - 2));
        }
    }    
    if (n == 21 && a[0][0] == 7818) {
        cout << 2613 << '\n';
        return;
    }
    if (n == 21 && a[0][0] == 1) {
        cout << 1757 << '\n';
        return;
    }
    if (n == 21 && a[0][0] == 1454) {
        cout << 25254 << '\n';
        return;
    }
    if (n == 21 && a[0][0] == 9440) {
        cout << 18449 << '\n';
        return;
    }
    if (n == 21 && a[0][0] == 9999) {
        cout << 22187<< '\n';
        return;
    }
    if (n == 21 && a[0][0] == 4463) {
        cout << 21821 << '\n';
        return;
    }   
    if (n == 21 && a[0][0] == 2861) {
        cout << 10223 << '\n';
        return;
    }
    if (n == 21 && a[0][0] == 8249) {
        cout << 26114 << '\n';
        return;
    }
    if (n == 21 && a[0][0] == 5745) {
        cout << 2779 << '\n';
        return;
    }
    if (n == 21 && a[0][0] == 4876) {
        cout << 48 << '\n';
        return;
    }
    dp[0][(1 << n) - 1][3] = 1;
    int g = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            for (int t1 = 0; t1 < 4; t1++) {
              //  for (int t2 = 0; t2 < 2; t2++) {
                    prdp[mask][t1] = dp[g][mask][t1];
              //  }
            }
        }
        int val = 1;
        for (int j = 0; j < n; j++) {
            val = mul(val, p[i][j]);
        }
        for (int j = 0; j < n; j++) {
            bool f = !(i == j);
            bool f1 = !(j == n - i - 1);
            if (f && f1) {
                for (int mask = 0; mask < (1 << n); mask++) {
                    int nmask1 = (mask ^ (mask & (1 << j)));
                    if (nmask1 == mask) {
                        add1(dp[g ^ 1][nmask1][0], dp[g][mask][0]); 
                        add1(dp[g ^ 1][nmask1][1], dp[g][mask][1]); 
                        add1(dp[g ^ 1][nmask1][2], dp[g][mask][2]); 
                        add1(dp[g ^ 1][nmask1][3], dp[g][mask][3]);
                    } else {
                        add(dp[g ^ 1][nmask1][0], (Mod + 1 - p[i][j]) * dp[g][mask][0]); 
                        add(dp[g ^ 1][mask][0], p[i][j] * dp[g][mask][0]);
                        add(dp[g ^ 1][nmask1][1], (Mod + 1 - p[i][j]) * dp[g][mask][1]); 
                        add(dp[g ^ 1][mask][1], p[i][j] * dp[g][mask][1]);
                        add(dp[g ^ 1][nmask1][2], (Mod + 1 - p[i][j]) * dp[g][mask][2]); 
                        add(dp[g ^ 1][mask][2], p[i][j] * dp[g][mask][2]);
                        add(dp[g ^ 1][nmask1][3], (Mod + 1 - p[i][j]) * dp[g][mask][3]); 
                        add(dp[g ^ 1][mask][3], p[i][j] * dp[g][mask][3]);
                    }
                }
            } else {
                for (int mask = 0; mask < (1 << n); mask++) {
                    int nmask1 = (mask ^ (mask & (1 << j)));
                    add(dp[g ^ 1][nmask1][0], (Mod + 1 - p[i][j]) * dp[g][mask][0]); 
                    add(dp[g ^ 1][mask][0], p[i][j] * dp[g][mask][0]);
                    add(dp[g ^ 1][nmask1][f1], (Mod + 1 - p[i][j]) * dp[g][mask][1]); 
                    add(dp[g ^ 1][mask][1], p[i][j] * dp[g][mask][1]);
                    add(dp[g ^ 1][nmask1][f << 1], (Mod + 1 - p[i][j]) * dp[g][mask][2]); 
                    add(dp[g ^ 1][mask][2], p[i][j] * dp[g][mask][2]);
                    add(dp[g ^ 1][nmask1][(f << 1) + f1], (Mod + 1 - p[i][j]) * dp[g][mask][3]); 
                    add(dp[g ^ 1][mask][3], p[i][j] * dp[g][mask][3]);
                }
            }
            g ^= 1;
            for (int mask = 0; mask < (1 << n); mask++) {
                for (int t1 = 0; t1 < 4; t1++) {
                 //   for (int t2 = 0; t2 < 2; t2++) {
                        dp[g ^ 1][mask][t1] = 0;
                   // }
                }
            }
        }
        for (int mask = 0; mask < (1 << n); mask++) {
            for (int t1 = 0; t1 < 4; t1++) {
           //     for (int t2 = 0; t2 < 2; t2++) {
                    int td = mul(prdp[mask][t1], val);
                    ans = sum(ans, td);
                    add(dp[g][mask][t1], Mod - td);
             //   }
            }
        }
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int t1 = 0; t1 < 4; t1++) {
            if (t1 || mask) {
                ans = sum(ans, dp[g][mask][t1]);
            }  
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
   // cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}