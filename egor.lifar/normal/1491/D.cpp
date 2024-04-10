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





bool ok(ll u, ll v) {
    if (u == v) {
        return true; 
    }
    if (u > v) {
        return false;
    }
    // if (u % 2 == 1) {
    //     if (v % 2 == 0) {
    //         if (ok(u + 1, v) || ok(u, v - 1)) {
    //             return true;
    //         }
    //     }
    // }
    vector<int> st;
    for (int t = 0; t < 30; t++) {
        if (u & (1 << t)) {
            st.pb(t);
        }
    }
    vector<int> st1;
    for (int t = 0; t < 30; t++) {
        if (v & (1 << t)) {
            st1.pb(t);
        }
    }
    if (sz(st) < sz(st1)) {
        return false;
    }
    for (int i = 0; i < min(sz(st), sz(st1)); i++) {
        if (st1[i] < st[i]) {
            return false;
        }
    }
    return true;
}


void solve() {
    ll u, v;
    cin >> u >> v;
    if (ok(u, v)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}



map<int, bool> used;
vector<int> st;

void dfs(int u) {
    used[u] = true;
    st.pb(u);
    vector<int> fp;
    for (int f = 0; f < 30; f++) {
        if (u & (1 << f)) {
            fp.pb(f);
        }
    }
    for (int j = 0; j < (1 << sz(fp)); j++) {
        int res = 0;
        for (int k = 0; k < sz(fp); k++) {
            if (j & (1 << k)) {
                res += (1 << fp[k]);
            }
        }
        if (u + res <= 1000000 && !used[u + res]) {
            dfs(u + res);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
   //  for (int t = 12; ; t++) {
   //      st.clear();
   //      used.clear();
   //      dfs(t);
   //      sort(all(st));
   //      for (int f = 0; f <= 1000000; f++) {
   //          if (ok(t, f)) {
   //             //cout << f << endl;
   //              if (!used[f]) {
   //                  cout << t << ' ' << f << endl;

   //                  exit(0);
   //              }
   //              assert(used[f]);
   //          } else {
   //           //   cout << f << endl;
   //              assert(!used[f]);
   //          }
   //      }
   //      cout << t << ' ' << sz(st) << '\n';
   //  }
   //  // for (auto x: st) {
   //  //     for (int t = 0; t < 17; t++) {
   //  //         if (x & (1 << t)) {
   //  //             cout << 1;
   //  //         } else {
   //  //             cout << 0;
   //  //         }
   //  //     }
   //  //     cout  << '\n';
   //  // }
   // exit(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}