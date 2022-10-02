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


const int MAXN = 10228;


int n, k;
int c[MAXN];
vector<int> where[MAXN];
int uk[MAXN];
int l[MAXN], r[MAXN];


void solve() {
    cin >> n >> k;
    for (int i = 0; i < n * k; i++) {
        cin >> c[i];
        where[c[i] - 1].pb(i);
    }
    for (int i = 0; i < n; i++) {
        uk[i] = sz(where[i]) - 1;
        l[i] = where[i][uk[i] - 1];
        r[i] = where[i][uk[i]]; 
    }
    int need = (n + k - 2) / (k - 1);
    for (int i = n * k - 1; i >= 0; i--) {
        int kek = 0;
        vector<pair<pair<int, int>, int> > st;
        for (int j = 0; j < n; j++) {
            if (l[j] <= i && i <= r[j]) {
                kek++;
                st.pb(mp(mp(uk[j], -l[j]), j));
            }
        }
        sort(all(st));
        while (kek > need) {
            auto d = st.back();
            st.pop_back();
            kek--;
            int j = d.second;
            uk[j]--;
            assert(uk[j] >= 1);
            l[j] = where[j][uk[j] - 1];
            r[j] = where[j][uk[j]]; 
        }
    }
    for (int i = 0; i < n; i++) {
        cout << l[i] + 1 << ' ' << r[i] + 1 << '\n';
    }
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