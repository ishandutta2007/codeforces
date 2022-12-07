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

int n, m, k;
int kx[1000], ky[1000];
int r[1000], cx[1000], cy[1000];
vector<int> g[1001];
const double EPS = 1e-9;
int d[1001][1001];
queue<int> q;
int ar[1000];

inline LL dist(LL x, LL y) {
    return x * x + y * y;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    REP(i, n) scanf("%d%d", kx + i, ky + i);
    REP(i, m) scanf("%d%d%d", r + i, cx + i, cy + i);
    REP(i, m) {
        int best = -1;
        REP(j, m) if (j != i && r[j] > r[i] &&
            dist(cx[j] - cx[i], cy[j] - cy[i]) < (LL)(r[j] - r[i]) * (r[j] - r[i])) {
            if (best == -1 || r[best] > r[j]) {
                best = j;
            }
        }
        if (best == -1) best = m;
        g[i].pb(best);
        g[best].pb(i);
    }
    ++m;
    REP(i, m) {
        REP(j, m) d[i][j] = -1;
        d[i][i] = 0;
        q.push(i);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int to : g[v]) if (d[i][to] == -1) {
                d[i][to] = d[i][v] + 1;
                q.push(to);
            }
        }
    }
    --m;
    REP(i, n) {
        int best = -1;
        REP(j, m) if (dist(cx[j] - kx[i], cy[j] - ky[i]) < (LL)r[j] * r[j]) {
            if (best == -1 || r[j] < r[best]) {
                best = j;
            }
        }
        if (best == -1) best = m;
        ar[i] = best;
    }
    ++m;
    REP(i, k) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        from = ar[from];
        to = ar[to];
        printf("%d\n", d[from][to]);
    }
    return 0;
}