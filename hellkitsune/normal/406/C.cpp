#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

struct T {
    int a, b, c;
    T(int a, int b, int c) : a(a), b(b), c(c) {}
};

int n, m;
vector<int> g[100000];
int vis[100000] = {};
vector<T> ans;

int dfs(int v, int p) {
    vector<int> e;
    vis[v] = 1;
    for (int to : g[v]) if (to != p && vis[to] != 2) {
        if (vis[to] == 0) {
            int ret = dfs(to, v);
            if (ret == -1) {
                e.pb(to);
            } else {
                ans.pb(T(v, to, ret));
            }
        } else {
            e.pb(to);
        }
    }
    REP(i, (int)e.size() / 2) {
        ans.pb(T(e[2 * i], v, e[2 * i + 1]));
    }
    vis[v] = 2;
    if ((int)e.size() & 1) return e.back();
    return -1;
}

int main() {
    scanf("%d%d", &n, &m);
    if (m % 2 == 1) {
        printf("No solution\n");
        return 0;
    }
    REP(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    dfs(0, -1);
    for (T x : ans) printf("%d %d %d\n", x.a + 1, x.b + 1, x.c + 1);
    return 0;
}