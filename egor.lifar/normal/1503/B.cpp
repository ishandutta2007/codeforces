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




int n;


int main() {
    ios_base::sync_with_stdio(false);
   // read(FILENAME);
    cin >> n;
    vector<pair<int, int> > st[2];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            st[(i + j) % 2].pb(mp(i + 1, j + 1));
        }
    }
    for (int it = 0; it < n * n; it++) {
        int a;
        cin >> a;
        if (st[0].empty() || st[1].empty()) {
            if (!st[0].empty()) {
                auto f = st[0].back();
                st[0].pop_back();
                if (a == 2) {
                    cout << 3 << ' ';
                } else {
                    cout << 2 << ' ';
                }
                cout << f.first << ' ' << f.second << endl;
            } else {
                auto f = st[1].back();
                st[1].pop_back();
                if (a == 1) {
                    cout << 3 << ' ';
                } else {
                    cout << 1 << ' ';
                }
                cout << f.first << ' ' << f.second << endl;
            }
        } else {
            if (a == 1) {
                auto f = st[0].back();
                st[0].pop_back();
                cout << 2 << ' ' << f.first << ' ' << f.second << endl;
            } else {
                auto f = st[1].back();
                st[1].pop_back();
                cout << 1 << ' ' << f.first << ' ' << f.second << endl;
            }
        }
    }
    return 0;
}