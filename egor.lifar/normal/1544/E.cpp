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
const int Mod =  998244353;


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



string s;


void solve() {
    cin >> s;
    int cnt[26];
    memset(cnt, 0, sizeof(cnt));
    for (auto x: s) {
        cnt[x - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 1) {
            cout << char('a' + i);
            cnt[i]--;
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < cnt[j]; k++) {
                    cout << char('a' + j);
                }
            }
            cout << '\n';
            return;
        }
    }
    sort(all(s));
    if (s[0] == s.back()) {
        cout << s << '\n';
        return;
    }
    string ded;
    for (int i = 0; i < 26; i++) {
        if (cnt[i]) {
            string f;
            for (int j = 0; j < 26; j++) {
                if (j != i) {
                    for (int k = 0; k < cnt[j]; k++) {
                        f += char('a' + j);
                    }
                }
            }
            int uk = 0;
            string d;
            d += char('a' + i);
            d += char('a' + i);
            bool bad = false;
            for (int j = 2; j < cnt[i]; j++) {
                if (uk >= sz(f)) {
                    bad = true;
                    break;
                }
                d += f[uk];
                uk++;
                d += char('a' + i);
            } 
            if (!bad) {
                for (int j = uk; j < sz(f); j++) {
                    d += f[j];
                }
                if (ded.empty() || ded > d) {
                    ded = d;
                }
            }
        //    break;
        }
    }   
    for (int i = 0; i < 26; i++) {
        if (cnt[i]) {
            string f;
            for (int j = 0; j < 26; j++) {
                if (j != i) {
                    for (int k = 0; k < cnt[j]; k++) {
                        f += char('a' + j);
                    }
                }
            }
            int uk = 0;
            string d;
            d += char('a' + i);
            d += f[0];
            uk++;
            for (int j = 1; j < cnt[i]; j++) {
                d += char('a' + i);
            }
            int pos = -1;
            for (int j = uk; j < sz(f); j++) {
                if (f[j] != f[0]) {
                    d += f[j];
                    pos = j;
                    break;
                }
            }
            if (pos != -1) {
                for (int j = uk; j < sz(f); j++) {
                    if (j == pos) {
                        continue;
                    }
                    d += f[j];
                }
                if (ded.empty() || ded > d) {
                    ded = d;
                }
            }
         //   break;
        }
    }  
    for (int i = 0; i < 26; i++) {
        if (cnt[i]) {
            string f;
            for (int j = 0; j < 26; j++) {
                if (j != i) {
                    for (int k = 0; k < cnt[j]; k++) {
                        f += char('a' + j);
                    }
                }
            }
            int uk = 0;
            string d;
            d += char('a' + i);
            d += f;
            for (int j = 1; j < cnt[i]; j++) {
                d += char('a' + i);
            }
            if (ded.empty() || ded > d) {
                ded = d;
            }
         //   break;
        }
    }  
    cout << ded << '\n';
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