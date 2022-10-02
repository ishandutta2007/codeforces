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


const int MAXN = 1005;


int n, m;
string s;

void solve() {
    cin >> n >> m;
    cin >> s;
    vector<pair<int, int> > st;
    for (int i = 0; i < n; i++) {
        if (st.empty() || st.back().first != s[i] - '0') {
            st.pb(mp(s[i] - '0', 1));
        } else {
            st.back().second++;
        }
    }
    for (int i = 0; i < sz(st); i++) {
        if (st[i].first == 0) {
            if (i == 0 && i == sz(st) - 1) {
                for (int j = 0; j < st[i].second; j++) {
                    cout << 0;
                }
                continue;
            }
            if (i == 0) {
                for (int j = 0; j < max(0, st[i].second - m); j++) {
                    cout << 0;
                }
                for (int j = 0; j < st[i].second - max(0, st[i].second - m); j++) {
                    cout << 1;
                }
            } else if (i == sz(st) - 1) {
                for (int j = 0; j < st[i].second - max(0, st[i].second - m); j++) {
                    cout << 1;
                }
                for (int j = 0; j < max(0, st[i].second - m); j++) {
                    cout << 0;
                }
            } else {
                int t = min(st[i].second / 2, m);
                for (int j = 0; j < t; j++) {
                    cout << 1;
                }
                for (int j = 0; j < st[i].second - 2 * t; j++) {
                    cout << 0;
                }
                for (int j = 0; j < t; j++) {
                    cout << 1;
                }
            }
        } else {
            for (int j = 0; j < st[i].second; j++) {
                cout << 1;
            }
        }
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
    while (t--) {
        solve();
    }
    return 0;
}