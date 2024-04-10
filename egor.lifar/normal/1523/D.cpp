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



const int MAXN = 200228;


int n, m, p;
string s[MAXN];
mt19937 as;
int cnt[MAXN];
int cnt1[MAXN][30];


void solve() {
    cin >> n >> m >> p;
    as.seed(n + m + p + time(NULL));
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    as.seed(time(NULL));
    vector<int> checks;
    for (int k = 0; k < 30; k++) {
        checks.pb(as() % n);
    }
    int ans = 0;
    string res;
    for (int i = 0; i < m; i++) {
        res += '0';
    }
    for (auto j: checks) {
        vector<int> pos;
        for (int i = 0; i < m; i++) {
            if (s[j][i] == '1') {
                pos.pb(i);
            }
        }
        if (pos.empty()) {
            continue;
        }
        for (int i = 0; i < (1 << sz(pos)); i++) {
            cnt[i] = 0;
            memset(cnt1[i], 0, sizeof(cnt1[i]));
        }
        for (int i = 0; i < n; i++) {
            int mask = 0;
            for (int j = 0; j < sz(pos); j++) {
                if (s[i][pos[j]] == '1') {
                    mask |= (1 << j);
                }
            }
            cnt[mask]++;
        }
        for (int mask = (1 << sz(pos)) - 1; mask >= 0; mask--) {
            int sum = cnt[mask];
            for (int f = sz(pos) - 1; f >= 0; f--) {
                if (!(mask & (1 << f))) {
                    sum += cnt1[mask | (1 << f)][f];
                }
                cnt1[mask][f] = sum;
            }
        }
        for (int mask = 0; mask < (1 << sz(pos)); mask++) {
            if (cnt1[mask][0] >= (n + 1) / 2) {
                int td = __builtin_popcount(mask);
                if (td > ans) {
                    ans = td;
                    for (int i = 0; i < m; i++) {
                        res[i] = '0';
                    }
                    for (int i = 0; i < sz(pos); i++) {
                        if (mask & (1 << i)) {
                            res[pos[i]] = '1';
                        }
                    }
                }
            }
        }
    }
    cout << res << '\n';

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    int t;
    t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}