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
 


int n, k;


void solve() {
    cin >> n >> k;
    vector<int> last2s;
    int opt = 2e9;
    int shift = 0;
    for (int f = 0; f <= n; f += k) {
        int have = n - f;
        if (have % 2 != 0) {
            continue;
        }
        vector<int> last1;
        int cost = f / k;
        for (int t = 2 * k; t >= 2; t -= 2) {
            if (t + k - t / 2 > n) {
                continue;
            }
            while (have >= t) {
                have -= t;
                cost += 2;
                last1.pb(t);
            }
        } 
        if (have == 0 && opt > cost) {
            opt = cost;
            last2s = last1;
            shift = f;
        }
    }
    if (opt > 500) {
        cout << -1 << endl;
        return;
    }
    ll ans = 0;
    for (int i = k; i <= shift; i += k) {
        cout << "? ";
        for (int j = i - k + 1; j <= i; j++) {
            cout << j << ' ';
        }
        cout << endl;
        int res;
        cin >> res;
        ans ^= res;
    }
    int i = shift;
    for (auto last2: last2s) {
        i += last2;
        cout << "? ";
        for (int j = i - last2 / 2 + 1; j <= i; j++) {
            cout << j << ' ';
        }
        int need = k - last2 / 2;
        for (int d = 1; d <= n; d++) {
            if (d >= i - last2 + 1 && d <= i) {
                continue;
            }
             if (need == 0) {
                break;
            }
            cout << d << ' ';
            need--;
        }
        cout << endl;
        int res;
        cin >> res;
        ans ^= res;
        cout << "? ";
        for (int j = i - last2 + 1; j <= i - last2 / 2; j++) {
            cout << j << ' ';
        }
        need = k - last2 / 2;
        for (int d = 1; d <= n; d++) {
            if (d >= i - last2 + 1 && d <= i) {
                continue;
            }
            if (need == 0) {
                break;
            }
            cout << d << ' ';
            need--;
        }
        cout << endl;
        cin >> res;
        ans ^= res;
    }
    cout << "! " << ans << endl; 
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