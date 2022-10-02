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



const int MAXN = 100229;


string s;
map<pair<int, int>, bool> was[MAXN];
map<pair<int, int>, pair<int, int> > how[MAXN];


bool solve(int n, int l, int r) {
    if (r - l + 1 < 0) {
        return false;
    }
    if (r < l) {
        if (n != 1) {
            return false;
        }   
        return true;
    }  
    if (n == 1) {
        if (r - l + 1 == 0) {
            return true;
        }
        return false;
    }
    if (was[n].find(mp(l, r)) != was[n].end()) {
        return was[n][mp(l, r)];
    }
    int m = (n / 2) - 1;
    vector<int> st;
    vector<int> st1;
    for (int i = 0; i <= m; i++) {
        st.pb(i);
    }
    for (int i = m + 1; i < n; i++) {
        st1.pb(i);
    }  
    for (int k = r; k >= l; k--) {
        //0, m
        //m + 1, n - 1
        vector<int> order;
        bool bad = false;
        int uk = 0;
        int uk1 = 0;
        for (int i = k; i <= r; i++) {
            if (s[i] == '0') {
                if (uk == sz(st) || uk1 == sz(st1)) {
                    bad = true;
                    break;
                }
                order.pb(st[uk]);
                uk++;
            } else {
                if (uk == sz(st) || uk1 == sz(st1)) {
                    bad = true;
                    break;
                }
                order.pb(st1[uk1]);
                uk1++;
            }
        }
        assert(uk <= sz(st));
        assert(uk1 <= sz(st1));
        if (uk != sz(st) && uk1 != sz(st1)) {
            bad = true;
        }
        if (bad) {
            continue;
        }
        for (int i = uk; i < sz(st); i++) {
            order.pb(st[i]);
        }
        for (int i = uk1; i < sz(st1); i++) {
            order.pb(st1[i]);
        }
        for (int i = l - 1; i < k; i++) {
            if (solve(m + 1, l, i) && solve(n - (m + 1), i + 1, k - 1)) {
                was[n][mp(l, r)] = true;
                how[n][mp(l, r)] = mp(k, i);
                return true;
            }
        }
    }
    was[n][mp(l, r)] = false;
    return false;
}


int a[MAXN];


void restore(int ls, int rs, int l, int r, vector<int> have) {
    if (ls > rs) {
        return;
    }
    if (ls == rs) {
        a[ls] = have[0];
        return;
    }
    int n = rs - ls + 1;
    int m = (n / 2) - 1;  
    int k = how[n][mp(l, r)].first;
    vector<int> order;
    vector<int> st;
    vector<int> st1;
    for (int i = 0; i <= m; i++) {
        st.pb(i);
    }
    for (int i = m + 1; i < n; i++) {
        st1.pb(i);
    }
    int uk = 0;
    int uk1 = 0;
    for (int i = k; i <= r; i++) {
        if (s[i] == '0') {
            order.pb(st[uk]);
            uk++;
        } else {
            order.pb(st1[uk1]);
            uk1++;
        }
    }
    assert(uk <= sz(st));
    assert(uk1 <= sz(st1));
    for (int i = uk; i < sz(st); i++) {
        order.pb(st[i]);
    }
    for (int i = uk1; i < sz(st1); i++) {
        order.pb(st1[i]);
    }
    vector<int> have1, have2;
    for (int i = 0; i < sz(order); i++) {
        if (order[i] <= m) {
            have1.pb(have[i]);
        } else {
            have2.pb(have[i]);
        }
    }
    int i = how[n][mp(l, r)].second;
    restore(ls, ls + m, l, i, have1);
    restore(ls + m + 1, rs, i + 1, k - 1, have2);
}


void solve() {
    cin >> s;
    for (int n = 1; ; n++) {
        if (solve(n, 0, sz(s) - 1)) {
            vector<int> have;
            for (int i = 0; i < n; i++) {
                have.pb(i + 1);
            }
            restore(0, n - 1, 0, sz(s) - 1, have);
            cout << n << '\n';
            for (int i = 0; i < n; i++) {
                cout << a[i] << ' ';
            }
            cout << '\n';
            return;
        }
    }
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