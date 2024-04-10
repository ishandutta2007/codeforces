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


const int MAXN = 1035;


int d, n;
string s[MAXN];
int mask[MAXN];
vector<int> g[MAXN * 2], v[MAXN * 2];
int mt[MAXN];   
bool used[MAXN];
int in[MAXN];



bool dfs(int i) {
    if (used[i]) {
        return false;
    }
    used[i] = true;
    for (auto h: g[i]) {
        if (mt[h] == -1 || dfs(mt[h])) {
            mt[h] = i;
            return true;
        }
    }
    return false;
}


bool comp(int i, int j) {
    return (__builtin_popcount(mask[i])) > (__builtin_popcount(mask[j])); 
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    cin >> d >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int f = 0; f < d; f++) {
            if (s[i][f] == '1') {
                mask[i] |= (1 << f);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mask[i] == mask[j]) {
                continue;
            }
            if ((mask[j] & mask[i]) == mask[i]) {
                g[i].pb(j);
            }
        }
    }
    vector<int> order;
    for (int i = 0; i < n; i++) {
        order.pb(i);
        mt[i] = -1;
    }
    sort(all(order), comp);
    int cnt = 0;
    for (auto i: order) {
        memset(used, 0, sizeof(used));
        if (dfs(i)) {
            cnt++;
        }
    } 
    for (int i = 0; i < n; i++) {
        if (mt[i] != -1) {
            v[mt[i]].pb(i);
            in[i]++;
        }
    }
    bool was = false;
    vector<char> ans;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            vector<int> res;
            res.pb(i);
            int cur = i;
            while (true) {
                if (v[cur].empty()) {
                    break;
                }
                cur = v[cur][0];
                res.pb(cur);
            }
            if (was) {
                ans.pb('R');
            }
            int last = 0;
            for (int i = 0; i < sz(res); i++) {
                for (int f = 0; f < d; f++) {
                    if ((mask[res[i]] & (1 << f))) {
                        if (!(last & (1 << f))) {
                            ans.pb('0' + f);
                        }
                    }
                }
                last = mask[res[i]];
            }
            was = true;
        }
    }
    cout << sz(ans) << '\n';
    for (auto x: ans) {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}