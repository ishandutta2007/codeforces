#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 111;

int n, m, a[N], b[N], c[300][300], f[300][300], flow, d[300], ptr[300];
int t;

int dfs(int v, int flow) {
    if (flow == 0) {
        return 0;
    }
    if (v == t) {
        return flow;
    }
    for (; ptr[v] <= t; ptr[v]++) {
        if (d[ptr[v]] != d[v] + 1) {
            continue;
        }
        int res = dfs(ptr[v], min(flow, c[v][ptr[v]] - f[v][ptr[v]]));
        if (res > 0) {
            f[v][ptr[v]] += res;
            f[ptr[v]][v] -= res;
            return res;
        }
    }
    return 0;
}

int bfs() {
    queue<int> q;
    memset(d, -1, 300 * sizeof(int));
    q.push(0);
    d[0] = 0;
    while (q.size()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < 300; i++) {
            if (c[cur][i] > f[cur][i] && d[i] == -1) {
                d[i] = d[cur] + 1;
                q.push(i);
            }
        }
    }
}

int dinic() {
    while (true) {
        memset(ptr, 0, 300 * sizeof(int));
        bfs();
        if (d[t] == -1) {
            break;
        }
        while (true) {
            int res = dfs(0, INF);
            flow += res;
            if (res == 0) {
                break;
            }
        }
    }
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    t = 2 * n + 1;
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        c[0][i + 1] = a[i];
        c[i + 1][n + 1 + i] = INF;
        sum1 += a[i];
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        c[n + 1 + i][t] = b[i];
        sum2 += b[i];
    }
    for (int i = 0; i < m; i++) {
        int p, q;
        scanf("%d%d", &p, &q);
        p--, q--;
        c[p + 1][n + 1 + q] = INF;
        c[q + 1][n + 1 + p] = INF;
    }
    dinic();
    if (sum1 != sum2 || sum1 != flow) {
        printf("NO\n");
    } else {
        printf("YES\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", f[i + 1][j + n + 1]);
            }
            printf("\n");
        }
    }
    return 0;
}