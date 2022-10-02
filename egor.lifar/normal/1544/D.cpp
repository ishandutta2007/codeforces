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


int n;
int a[MAXN];
int cnt[MAXN];
vector<int> v[MAXN];
bool bad[MAXN];
int b[MAXN];


void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        v[i].clear();
        b[i] = a[i];
        bad[i] = false;
    }   
    for (int i = 1; i <= n; i++) {
        cnt[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        v[a[i] - 1].pb(i);
        cnt[a[i]]++;
    }
    set<int> f;
    for (int i = 0; i < n; i++) {
        if (cnt[i + 1] == 0) {
            f.insert(i);
        }
    }
     vector<int> need;
    int changes = 0;
    for (int i = 0; i < n; i++) {
        bool was = false;
        vector<int> kek;
        for (int j = 0; j < sz(v[i]); j++) {
            if (f.find(v[i][j]) != f.end()) {
                kek.pb(v[i][j]);
            }
        }
        for (int j = 0; j < sz(v[i]); j++) {
            if (f.find(v[i][j]) == f.end()) {
                kek.pb(v[i][j]);
            }
        }
        v[i] = kek;
        for (int j = 0; j < sz(v[i]); j++) {
            if (v[i][j] == i || was) {
                int x = v[i][j];
                need.pb(x);
                changes++;
                bad[x] = true;
               // cout << x << endl;
            } else {
                was = true;
            }
        }
        if (!was) {
            f.insert(i);
        }
    }
    bool neede = false;
    if (sz(f) == 1 && sz(need) == 1 && *f.begin() == need[0]) {
        changes++;
        neede = true;
    }
   
    for (int i = 0; i < n; i++) {
        if (!bad[i] && neede) {
            neede = false;
            bad[i] = true;
            need.pb(i);
            f.insert(a[i] - 1);
        }
    }
    vector<int> special, regs;
    for (int i = 0; i < sz(need); i++) {
        if (f.find(need[i]) != f.end()) {
            special.pb(need[i]);
            f.erase(need[i]);
        } else {
            regs.pb(need[i]);
        }
    }
    //cout << sz(special) << endl;
    if (sz(special) == 1) {
        a[regs.back()] = special.back() + 1;
        f.erase(special.back());
        regs.pop_back();
        regs.pb(special[0]);
    } else {
        for (int i = 0; i < sz(special); i++) {
            a[special[i]] = special[(i + 1) % sz(special)] + 1;
        }
        special.clear();
    }
    for (int i = 0; i < sz(regs); i++) {
        a[regs[i]] = *f.rbegin() + 1;
        f.erase(a[regs[i]] - 1);
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            k++;
        }
    }   
    cout << k << '\n';
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
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
   // t = 1;
    while (t--) {
        solve();
    }
    return 0;
}