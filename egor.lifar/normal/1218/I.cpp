/*














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
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { x = (x > y ? y: x);}
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { x = (x < y ? y: x);}
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left224
#define right right224
#define rank rank224
#define y1 y1224
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
const string FILENAME = "input";
const int MAXN = 15222;

struct edge {
    int u, v, val;
};

const int mx = 2010;
int n, a[mx][mx], b[mx][mx], c[mx], value[2 * mx], used[2 * mx];
vector<vector<pair<int, int> > > g;
vector<edge> e;

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char ch;
            cin >> ch;
            a[i][j] = ch - '0';
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char ch;
            cin >> ch;
            b[i][j] = ch - '0';
        }
    }
    for (int i = 0; i < n; ++i) {
        char ch;
        cin >> ch;
        c[i] = ch - '0';
    }   
}

void put_value(int pos, int val) {
    //cerr << "put_value " << pos << " " << val << endl;
    if (value[pos] != -1 && value[pos] != val) {
        cout << -1 << endl;
        exit(0);
    }
    value[pos] = val;
}

const int N = 2 * mx;
int V;

void build() {
    V = 2 * n;
    fill(value, value + V, -1);
    g.resize(V);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int diff = (a[i][j] ^ b[i][j]);
            if (c[i] == 0 && c[j] == 0) {
                if (diff) {
                    cout << -1 << endl;
                    exit(0);
                }
                continue;
            }
            if (c[i] == 0) {
                put_value(i, diff);
                continue;
            }
            if (c[j] == 0) {
                put_value(n + j, diff);
                continue;
            }
            g[i].emplace_back(n + j, diff);
            g[n + j].emplace_back(i, diff);
            e.push_back({i, n + j, diff});
        }
    }
}

void dfs(int v) {
    used[v] = 1;
    for (auto pp : g[v]) {
        int v1 = pp.first;
        int val = pp.second;
        put_value(v1, value[v] ^ val);
        if (used[v1] == 0) {
            dfs(v1);
        }
    }
}

void solve() {
    for (int i = 0; i < 2 * n; ++i) {
        if (used[i] == 0 && value[i] != -1) {
            dfs(i);
        }
    }
    for (int i = 0; i < 2 * n; ++i) {
        if (used[i] == 0) {
            value[i] = 0;
            dfs(i);
        }
    }
}

void print() {
    vector<pair<string, int> > ans;
    for (int i = 0; i < n; ++i) {
        if (value[i]) {
            ans.emplace_back("row", i);
        }
    }
    for (int i = n; i < 2 * n; ++i) {
        if (value[i]) {
            ans.emplace_back("col", i - n);
        }
    }
    cout << ans.size() << endl;
    for (auto pp : ans) {
        cout << pp.first << " " << pp.second << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    read();
    build();
    solve();
    print();

    return 0; 
}