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



string s[3];


void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < 3; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            string res;
            int cnt2 = 0;
            int cnt3 = 0;
            for (int k = 0; k < 2 * n; k++) {
                if (s[i][k] == '0') {
                    cnt2++;
                } else {
                    cnt3++;
                }
            }
            int cnt = 0;
            int cnt1 = 0;
            for (int k = 0; k < 2 * n; k++) {
                if (s[j][k] == '0') {
                    cnt++;
                } else {
                    cnt1++;
                }
            }
            res = s[i];
            char target;
            int have = 0;
            if (min(cnt, cnt2) > min(cnt1, cnt3)) {
                target = '0';
                have = min(cnt, cnt2);
            } else {
                target = '1';
                have = min(cnt1, cnt3);
            }
            int uk = 0;
            string d;
            for (int k = 0; k < 2 * n; k++) {
                if (s[j][k] == target && have)  {
                    while (uk < sz(res) && res[uk] != target) {
                        d += res[uk];
                        uk++;
                    }
                    d += res[uk];
                    uk++;
                    have--;
                } else {
                    d += s[j][k];
                }
            }
            for (int i = uk; i < sz(res); i++) {
                d += res[i];
            }
            if (sz(d) <= 3 * n) {
                while (sz(d) < 3 * n) {
                    d += '0';
                }
                cout << d << '\n';
                return;
            }
        }
    }
    assert(false);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}