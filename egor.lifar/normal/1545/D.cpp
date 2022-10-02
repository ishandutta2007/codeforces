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


// int sum(int a, int b) {
//     return (a + b >= Mod ? a + b - Mod: a + b);
// }


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



const int MAXN = 1008;


int m, k;
int cord[MAXN][MAXN];
ll sum[MAXN];


void solve() {
    cin >> m >> k;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cord[i][j];
            sum[i] += cord[i][j];
        }
    }
    ll x = (sum[k - 1] - sum[0]) / (k - 1);
    int pos = -1;
    ll diff = 0;
    for (int i = 0; i < k; i++) {
        if ((sum[i] - sum[0]) != i * x) {
            pos = i;
            diff = sum[i] - sum[0] - i * x;
        }
    }    
    for (int i = 1; i < k - 1; i++) {
        if (i - 1 != pos && i != pos && i + 1 != pos) {
            x = 0;
            for (int j = 0; j < m; j++) {
                x += cord[i - 1][j] * cord[i - 1][j] + cord[i + 1][j] * cord[i + 1][j] - cord[i][j] * cord[i][j] * 2;  
            }
            break;
        }
    }
    ll s = 0, t = 0;
    for (int i =0; i < m; i++) {
        s += cord[pos - 1][i] * cord[pos - 1][i] + cord[pos + 1][i] * cord[pos + 1][i];
        t += cord[pos][i] * cord[pos][i] * 2;
    }   
    s -= x;
    ll val = 0;
    for (int i =0; i < m; i++) {
        ll temp = t - cord[pos][i] * cord[pos][i] * 2 + (cord[pos][i] - diff) * (cord[pos][i] - diff) * 2;
        if (temp == s) {
            val = cord[pos][i] - diff;
            break;
        }
    }
    cout << pos << ' ' << val << endl;       
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    int t;
    //cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}