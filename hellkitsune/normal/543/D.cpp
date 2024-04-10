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

int n, p[200000];
vector<int> g[200000];
int d[200000];
int ans[200000];

const int MOD = 1e9 + 7;

void dfs(int v, int par) {
    d[v] = 1;
    for (int to : g[v]) if (to != par) {
        dfs(to, v);
        d[v] = ((LL)d[v] * (d[to] + 1)) % MOD;
    }
}

void go(int v, int par) {
    ans[v] = d[v];
    vector<int> suf;
    for (int to : g[v]) suf.pb(d[to] + 1);
    suf.pb(1);
    for (int i = (int)suf.size() - 2; i >= 0; --i)
        suf[i] = ((LL)suf[i + 1] * suf[i]) % MOD;
    int pos = 1;
    int mul = 1;
    for (int to : g[v]) {
        if (to != par) {
            int dv = d[v];
            int dto = d[to];
            d[v] = ((LL)mul * suf[pos]) % MOD;
            d[to] = ((LL)d[to] * (d[v] + 1)) % MOD;
            go(to, v);
            d[v] = dv;
            d[to] = dto;
        }
        ++pos;
        mul = ((LL)mul * (d[to] + 1)) % MOD;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) scanf("%d", p + i), --p[i];
    for (int i = 1; i < n; ++i) {
        g[i].pb(p[i]);
        g[p[i]].pb(i);
    }
    dfs(0, -1);
    go(0, -1);
    REP(i, n) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}