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

int n, m, N;
int d[100000], h[100000];
LL val[2][200000];
LL st[2][18][200000];
int p[200001];
LL dist[200000];

void buildSt() {
    int curP = 0;
    for (int i = 1; i <= N; ++i) {
        if ((1 << (curP + 1)) < i)
            ++curP;
        p[i] = curP;
    }
    val[0][0] = 0;
    for (int i = 1; i < N; ++i) val[0][i] = val[0][i - 1] - d[(i - 1) % n];
    REP(i, N) val[0][i] += 2 * h[i % n];
    val[1][N - 1] = 0;
    for (int i = N - 2; i >= 0; --i) val[1][i] = val[1][i + 1] - d[i % n];
    REP(i, N) val[1][i] += 2 * h[i % n];
    REP(k, 2) REP(j, N) st[k][0][j] = j;
    REP(k, 2) for (int i = 1; i < 18; ++i) {
        int mx = N - (1 << i) + 1;
        REP(j, mx) {
            if (val[k][st[k][i - 1][j]] > val[k][st[k][i - 1][j + (1 << (i - 1))]])
                st[k][i][j] = st[k][i - 1][j];
            else
                st[k][i][j] = st[k][i - 1][j + (1 << (i - 1))];
        }
    }
}

inline LL stGet(int k, int from, int to) {
    int curP = p[to - from + 1];
    int a = st[k][curP][from], b = st[k][curP][to - (1 << curP) + 1];
    return (val[k][a] > val[k][b]) ? a : b;
}

LL solve(int from, int to) {
    int l = stGet(0, from, to);
    int r = stGet(1, from, to);
    assert(r >= l);
    if (r == l) {
        if (r == to) l = stGet(0, from, r - 1);
        else if (l == from) r = stGet(1, l + 1, to);
        else {
            int nl = stGet(0, from, r - 1);
            int nr = stGet(1, l + 1, to);
            if (dist[nr] - dist[l] + 2ll * (h[l % n] + h[nr % n]) > dist[r] - dist[nl] + 2ll * (h[r % n] + h[nl % n]))
                r = nr;
            else
                l = nl;
        }
    }
    return dist[r] - dist[l] + 2ll * (h[r % n] + h[l % n]);
}

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%d", d + i);
    REP(i, n) scanf("%d", h + i);

    N = 2 * n;
    dist[0] = 0;
    for (int i = 1; i < N; ++i)
        dist[i] = dist[i - 1] + d[(i - 1) % n];
    buildSt();

    REP(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        LL ans;
        if (to >= from) {
            ans = solve(to + 1, n + from - 1);
        } else {
            ans = solve(to + 1, from - 1);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}