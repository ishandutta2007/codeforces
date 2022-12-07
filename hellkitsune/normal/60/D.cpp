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
typedef long long LL;
typedef pair<int, int> PII;

int n;
int cnt[10000001] = {};
int par[10000001], ra[10000001];

void dsuInit() {
    REP(i, 10000001) par[i] = i, ra[i] = cnt[i];
}

int dsuParent(int v) {
    if (v == par[v]) return v;
    return par[v] = dsuParent(par[v]);
}

void dsuMerge(int u, int v) {
    u = dsuParent(u);
    v = dsuParent(v);
    if (u == v) return;
    if (ra[u] < ra[v]) swap(u, v);
    par[v] = u;
    ra[u] += ra[v];
}

int gcd(int a, int b) {
    while (b) a %= b, swap(a, b);
    return a;
}

int main() {
    scanf("%d", &n);
    REP(i, n) {
        int x;
        scanf("%d", &x);
        ++cnt[x];
    }
    dsuInit();
    for (int p = 1; p <= 3200; ++p) {
        for (int q = p + 1; 2 * p * q <= 10000000; q += 2) {
            if (gcd(p, q) != 1) continue;
            LL x = (LL)q * q - p * p;
            LL y = 2 * p * q;
            LL z = p * p + (LL)q * q;
            if (x <= 10000000 && y <= 10000000 && cnt[x] && cnt[y]) dsuMerge(x, y);
            if (x <= 10000000 && z <= 10000000 && cnt[x] && cnt[z]) dsuMerge(x, z);
            if (y <= 10000000 && z <= 10000000 && cnt[y] && cnt[z]) dsuMerge(y, z);
        }
    }
    int ans = 0;
    REP(i, 10000001) if (cnt[i] && dsuParent(i) == i) {
        if (ra[i] == cnt[i]) ans += cnt[i];
        else ++ans;
    }
    printf("%d\n", ans);
    return 0;
}