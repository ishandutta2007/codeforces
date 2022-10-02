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
const int MAXN = 300228;


vector<int> a;


void add(int x){
    a.push_back(x);
}


int parent[MAXN];
ll curc[MAXN];
int at[MAXN], b[MAXN];
ll cost[MAXN];
bool good[MAXN];
set<pair<int, int> > g[MAXN];


int findset(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = findset(parent[v]);
}


bool solve(int n, int m, vector<int> &c, vector<int> &v, vector<int> &u, vector<int> &w) {
    ll kek = 0;
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        curc[i] = c[i];
        kek += c[i];
    }
    for (int i = 0; i < m; i++) {
        at[i] = u[i] - 1;
        b[i] = v[i] - 1;
        cost[i] = w[i];
    }
    vector<pair<int, int> > st;
    for (int i = 0; i < m; i++) {
        st.pb({w[i], i});
    }
    sort(all(st));
    ll sum = 0;
    for (auto x: st) {
        int as = at[x.second];
        int bs = b[x.second];
        as = findset(as);
        bs = findset(bs);
        if (as == bs) {
            continue;
        }
        good[x.second] = true;
        sum += x.first;
        parent[as] = bs;
    }
    for (int i = 0; i < n; i++) {
        if (findset(0) != findset(i)) {
            return false;
        }
    }
    if (kek < sum) {
        return false;
    }
    vector<int> order, order1;
    for (int i = 0; i < m; i++) {
        if (good[i]) {
            g[at[i]].insert({b[i], i});
            g[b[i]].insert({at[i], i});
        }
    }
    priority_queue<pair<int, int> > s;
    for (int i = 0; i < n; i++) {
        s.push({-sz(g[i]), i});
    }
    while (!s.empty()) {
        pair<int, int> p = s.top();
        int u = p.second;
        s.pop();
        if (sz(g[u]) != -p.first) {
            continue;
        }
        if (p.first == 0) {
            continue;
        }
        assert(p.first == -1);
        int i = g[u].begin()->second;
        int j = g[u].begin()->first;
        g[j].erase({u, i});
        s.push({-sz(g[j]), j});
        if (curc[u] + curc[j] >= cost[i]) {
            order.pb(i);
            curc[j] += curc[u] - cost[i];
        } else {
            order1.pb(i);
        }
    }
    for (auto x: order) {
        add(x + 1);
    }
    reverse(all(order1));
    for (auto x: order1) {
        add(x + 1);
    }
    return true;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> c(n), f(m), s(m), w(m);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> f[i] >> s[i];
        w[i] = x;
    }
    if (!solve(n, m, c, f, s, w)) {
        cout << "NO" << "\n";
    } else {
        cout << "YES\n";
        for (int i = 0; i < sz(a); i++) {
            cout << a[i] << "\n";
        }
    }
    return 0;
}