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
const int Mod = 1000000009;


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



const int MAXN = 200228;


int n;
string s;
char a[MAXN], b[MAXN];
int bals[MAXN], bals1[MAXN];
int suff[MAXN], suff1[MAXN];


void solve() {
    cin >> n;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            cnt++;
        }
    }
    if (cnt % 2 == 1) {
        cout << "NO\n";
        return;
    }
    string a, b;
    int pd = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            pd++;
            if (pd % 2 == 0) {
                a += ')';
                b += '(';
            } else {
                a += '(';
                b += ')';
            }
        } else {
            a += '(';
            b += '(';
        }
    } 
    int bal = 0;
    for (auto x: a) {
        if (x == '(') {
            bal++;
        } else {
            bal--;
        }
        if (bal < 0) {
            cout << "NO\n";
            return;
        }
    }
    bal = 0;
    for (auto x: b) {
        if (x == '(') {
            bal++;
        } else {
            bal--;
        }
        if (bal < 0) {
            cout << "NO\n";
            return;
        }
    }
    cnt = 0;
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        cnt += (a[i] == '(' ? 1: -1);
        cnt1 += (b[i] == '(' ? 1: -1);
        bals[i] = cnt;
        bals1[i] = cnt1;
    }
    for (int i = n - 1; i >= 0; i--) {
        suff[i] = bals[i];
        suff1[i] = bals1[i];
        if (i + 1 < n) {
            chkmin(suff[i], suff[i + 1]);
            chkmin(suff1[i], suff1[i + 1]);
        }
    }
    int curd = 0, curd1 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (curd && curd1) {
                if (i == n - 1 || (suff[i + 1] - bals[i] + curd - 1 >= 0 && suff1[i + 1] - bals1[i] + curd1 - 1 >= 0)) {
                    a[i] = ')';
                    b[i] = ')';
                }
            }
        }
        curd += (a[i] == '(' ? 1: -1);
        curd1 += (b[i] == '(' ? 1: -1);
    }
    if (curd != 0 || curd1 != 0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << a << '\n';
    cout << b << '\n';
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