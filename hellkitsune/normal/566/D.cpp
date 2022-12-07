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

set<int> se;
int par[200000], ra[200000];
int n, q;

void dsuInit() {
    REP(i, n) par[i] = i, ra[i] = 1;
}

int dsuParent(int v) {
    if (par[v] == v) return v;
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

int main() {
    scanf("%d%d", &n, &q);
    dsuInit();
    REP(i, n - 1) se.insert(i);
    REP(i, q) {
        int qt, x, y;
        scanf("%d%d%d", &qt, &x, &y), --x, --y;
        if (qt == 1) {
            dsuMerge(x, y);
        } else if (qt == 2) {
            auto from = se.lower_bound(x);
            auto to = se.lower_bound(y);
            for (auto it = from; it != to; ++it) {
                int ind = *it;
                dsuMerge(ind, ind + 1);
            }
            if (from != to) se.erase(from, to);
        } else {
            if (dsuParent(x) == dsuParent(y)) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }
    return 0;
}