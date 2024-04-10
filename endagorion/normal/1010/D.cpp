#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 1100000;
string type[maxn];
vi args[maxn], e[maxn];
int val[maxn], reach[maxn];

void dfs(int v) {
    if (type[v] == "IN") {
        val[v] = args[v][0];
        return;
    }
    for (int u: args[v]) dfs(u);
    if (type[v] == "NOT") val[v] = !val[args[v][0]];
    if (type[v] == "AND") {
        val[v] = 1;
        for (int u: args[v]) val[v] &= val[u];
    }
    if (type[v] == "OR") {
        val[v] = 0;
        for (int u: args[v]) val[v] |= val[u];
    }
    if (type[v] == "XOR") {
        val[v] = 0;
        for (int u: args[v]) val[v] ^= val[u];
    }
}

void dfse(int v) {
    reach[v] = 1;
    for (int u: e[v]) dfse(u);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n;
    forn(i, n) {
        cin >> type[i];
        if (type[i] == "IN" || type[i] == "NOT") args[i].resize(1);
        else args[i].resize(2);
        for (int &x: args[i]) {
            cin >> x;
            if (type[i] != "IN") --x;
        }
    }

    dfs(0);
    cerr << val[0] << '\n';
    forn(i, n) {
        if (type[i] == "IN") continue;
        if (type[i] == "AND") {
            if (val[i] == 1) for (int u: args[i]) e[i].pb(u);
            else {
                int z = 0;
                for (int u: args[i]) z += val[u];
                if (z == 1) for (int u: args[i]) if (val[u] == 0) e[i].pb(u);
            }
        } else if (type[i] == "OR") {
            if (val[i] == 0) for (int u: args[i]) e[i].pb(u);
            else {
                int z = 0;
                for (int u: args[i]) z += val[u];
                if (z == 1) for (int u: args[i]) if (val[u] == 1) e[i].pb(u);
            }
        }
        else for (int u: args[i]) e[i].pb(u);
    }

    dfse(0);

    forn(i, n) if (type[i] == "IN") cout << (val[0] ^ reach[i]);
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}