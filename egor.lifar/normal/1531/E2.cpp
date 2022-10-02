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
#include <array>
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
vector<int> pref[2];
vector<pair<int, int> > st, st1;
int uk;
int n;


bool calc(int l, int r) {
    if (r - l + 1 <= 1) {
        return true;
    }
    int m = (l + r - 1) >> 1;
    if (!calc(l, m)) {
        return false;
    }
    if (!calc(m + 1, r)) {
        return false;
    }
    int fk[2] = {m - l + 1, r - m};
    if (uk >= sz(s)) {
        return false;
    }
    int kek = sz(s);
    for (int t = 0; t < 2; t++) {
        if (pref[t][sz(s) - 1] - (uk ? pref[t][uk - 1]: 0) < fk[t]) {
            continue;
        }
        int pos = lower_bound(all(pref[t]), (uk ? pref[t][uk - 1]: 0) + fk[t]) - pref[t].begin();
        chkmin(kek, pos);
    }
    if (kek >= sz(s)) {
        return false;
    }
    st1.pb(mp(uk, kek));
    st.pb(mp(l, r));
    uk = kek + 1;
    return true;
}


map<pair<int, int>, pair<int, int> > who;
int a[MAXN];


void restore(int l, int r, vector<int> have) {
    if (l > r) {
        return;
    }
    if (l == r) {
        a[l] = have[0];
        return;
    }
    int m = (l + r - 1) >> 1;
    vector<int> st;
    vector<int> st1, order;
    for (int i = l; i <= m; i++) {
        st.pb(i);
    }
    for (int i = m + 1; i <= r; i++) {
        st1.pb(i);
    }
    int uk = 0;
    int uk1 = 0;
    for (int i = who[mp(l, r)].first; i <= who[mp(l, r)].second; i++) {
        if (s[i] == '0') {
            order.pb(st[uk]);
            uk++;
        } else {
            order.pb(st1[uk1]);
            uk1++;
        }
    }
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
    restore(l, m, have1);
    restore(m + 1, r, have2);
}

void solve() {
    cin >> s;
    pref[0].resize(sz(s));
    pref[1].resize(sz(s));
    for (int i = 0; i < sz(s); i++) {
        pref[s[i] - '0'][i] = 1;
    }
    for (int i = 1; i < sz(s); i++) {
        pref[0][i] += pref[0][i - 1];
        pref[1][i] += pref[1][i - 1];
    }
    for (n = 1; ; n++) {
        uk = 0;
        st.clear();
        st1.clear();
        if (calc(0, n - 1) && uk == sz(s)) {
            cout << n << endl;
            vector<int> have;
            for (int i = 1; i <= n; i++) {
                have.pb(i);
            }
            for (int i = 0; i < sz(st); i++) {
                who[st[i]] = st1[i];
            }
            restore(0, n - 1, have);
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