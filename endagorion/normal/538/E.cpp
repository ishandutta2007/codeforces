#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
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
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

template<class T>
bool uin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool uax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const int MAXN = 210000;
vi e[MAXN];
int w[MAXN];
int dpmax[MAXN], dpmin[MAXN];

void dfs(int v) {
    if (e[v].empty()) {
        w[v] = 1;
        dpmax[v] = dpmin[v] = 0;
        return;
    }

    int md = 1e9, s = 0;
    w[v] = 0;
    for (int u: e[v]) {
        dfs(u);
        w[v] += w[u];
        uin(md, dpmin[u]);
        s += w[u] - dpmax[u];
    }
    dpmax[v] = w[v] - md - 1;
    dpmin[v] = s - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N;
    cin >> N;
    forn(i, N - 1) {
        int x, y;
        cin >> x >> y;
        e[--x].pb(--y);
    }
    dfs(0);
    cerr << w[0] << '\n';
    cout << dpmax[0] + 1 << ' ' << dpmin[0] + 1 << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}