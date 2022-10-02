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



const int MAXN = 300228;


int n, q;
int a[MAXN];
int parent[1000229];
vector<int> who[1000228];
bool bad[1000228];
vector<int> z[1000228];


int findset(int a) {
    if (parent[a] == a) {
        return a;
    }
    return parent[a] = findset(parent[a]);
}


void merge(int a, int b) {
    a = findset(a);
    b = findset(b);
    if (a == b) {
        return;
    }
    parent[b] = a;
}


int rep[1000229];
vector<int> goode[1000229];


void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        who[a[i]].pb(i);
        parent[i] = i;
    }
    for (int i = 2; i <= 1000001; i++) {
        if (bad[i]) {
            continue;
        }
        z[i].pb(i);
        for (int j = 2 * i; j <= 1000001; j += i) {
            z[j].pb(i);
            bad[j] = true;
        }
    }
    for (int i = 2; i <= 1000001; i++) {
        int a = -1;
        if (!who[i].empty()) {
            a = who[i][0];
        }
        for (int j = 2 * i; j <= 1000001; j += i) {
            if (!who[j].empty()) {
                if (a == -1) {
                    a = who[j][0];
                } else {
                    merge(a, who[j][0]);
                }
            }
        }
    }
    for (int i = 2; i <= 1000001; i++) {
        if (!bad[i]) {
            rep[i] = -1;
            for (int j = i; j <= 1000001; j += i) {
                if (!who[j].empty()) {
                    rep[i] = findset(who[j][0]);
                    break;
                }
            }
        }
    }
    for (int i = 2; i <= 1000001; i++) {
        if (who[i].empty()) {
            continue;
        }
        for (auto x: z[i + 1]) {
            if (rep[x] != -1) {
                goode[findset(who[i][0])].pb(rep[x]);
                goode[rep[x]].pb(findset(who[i][0]));
            }
        }
        vector<int> st;
        for (auto x: z[i + 1]) {
            if (rep[x] != -1) {
                st.pb(rep[x]);
            }
        }
        sort(all(st));
        st.resize(distance(st.begin(), unique(all(st))));
        for (int j = 0; j < sz(st); j++) {
            for (int k = j + 1; k < sz(st); k++) {
                goode[st[j]].pb(st[k]);
                goode[st[k]].pb(st[j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        sort(all(goode[i]));
    }
    for (int it = 0; it < q; it++) {
        int s, t;
        cin >> s >> t;
        s--, t--;
        s = findset(s);
        t = findset(t);
        if (s == t) {
            cout << 0 << '\n';
            continue;
        }
        {
            auto fk = lower_bound(all(goode[s]), t) - goode[s].begin();
            if (fk != sz(goode[s]) && goode[s][fk] == t) {
                cout << 1 << '\n';
                continue;
            }
        }
        swap(s, t);
        {
            auto fk = lower_bound(all(goode[s]), t) - goode[s].begin();
            if (fk != sz(goode[s]) && goode[s][fk] == t) {
                cout << 1 << '\n';
                continue;
            }
        }
        cout << 2 << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    int t;
 //   cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}