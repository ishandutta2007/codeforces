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

int n, m;
vector<int> g[100000];
vector<int> cp[100000];
int c[100000], col[100000];

bool dsuMerge(int u, int v) {
    int cu = c[u];
    int cv = c[v];
    if (cu == cv) {
        return col[u] != col[v];
    }
    if (cp[cu].size() < cp[cv].size()) swap(cu, cv);
    if (col[u] == col[v]) for (int x : cp[cv]) {
        col[x] ^= 1;
    }
    for (int x : cp[cv]) {
        cp[cu].pb(x);
        c[x] = cu;
    }
    cp[cv].clear();
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    if (m == 0) {
        LL cnt = (LL)n * (n - 1) * (n - 2) / 6;
        cout << "3 " << cnt << endl;
        return 0;
    }
    REP(i, n) cp[i].pb(i), c[i] = i, col[i] = 0;
    bool ok = true;
    REP(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        ok = ok && dsuMerge(from, to);
    }
    if (!ok) {
        printf("0 1\n");
        return 0;
    }
    LL ans = 0;
    int sz2 = 0;
    REP(i, n) if ((int)cp[i].size() > 2) {
        int z = 0, o = 0;
        for (int x : cp[i]) if (col[x] == 0) ++z;
        else ++o;
        ans += (LL)z * (z - 1) / 2 + (LL)o * (o - 1) / 2;
    } else if ((int)cp[i].size() == 2) {
        ++sz2;
    }
    if (ans == 0) {
        cout << "2 " << ((LL)sz2 * (n - 2)) << endl;
    } else {
        cout << "1 " << ans << endl;
    }
    return 0;
}