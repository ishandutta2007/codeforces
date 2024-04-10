
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


using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228
#define y1 y1228
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
using ld = long double;
const string FILENAME = "input";
const int MAXN = 200228;
const int Mod = 1000000007;



int n;
vector<int> g[MAXN];
int pr[MAXN];
vector<int> t;
vector<int> opt;
vector<int> ops;


// void get(int u) {
//     t.pb(u);
//     int nxt = -1;
//     for (auto h: g[u]) {
//         if (h == opt[sz(t)]) {
//             nxt = h;
//         }
//     }
//     if (nxt == -1) {
//         return;
//     }
//     for (auto h: g[u]) {
//         if (h != nxt) {
//             ops.pb(h);
//             g[nxt].pb(h);
//         }
//     }
//     get(nxt);
// }



int deep[MAXN];


void dfs(int u) {
    deep[u] = 1;
    for (auto h: g[u]) {
        dfs(h);
        chkmax(deep[u], deep[h] + 1);
    }
}


bool comp(int a, int b) {
    return deep[a] < deep[b];
}


void dfst(int u) {
    opt.pb(u);
    for (auto h: g[u]) {
        dfst(h);
    }
}


int pr2[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        g[p].pb(i);
        pr[i] = p;
    }
    dfs(0);
    for (int i = 0; i < n; i++) {
        sort(all(g[i]), comp);
    }
    dfst(0);
    t = opt;
    for (auto x: t) {
        cout << x << ' ';
    }
    cout << '\n';
    ops.clear();
    pr2[t[0]] = -1;
    for (int i = 1; i < n; i++) {
        pr2[t[i]] = t[i - 1];
    }
    vector<int> answ;
    for (int i = 1; i < n; ++i) {
        if (t[i] != g[pr[t[i]]][0]) {
            while (pr2[t[i]] != pr[t[i]]) {
                pr2[t[i]] = pr2[pr2[t[i]]];
                ops.push_back(t[i]);
            }
        }
    }
    cout << sz(ops) << '\n';
    for (auto x: ops) {
        cout << x << ' ';
    }
    cout << '\n';
	return 0;
}