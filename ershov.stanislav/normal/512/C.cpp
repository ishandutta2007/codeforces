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

const int INF = 1e9 + 100;
const ll lINF = 4e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

int n, a[222], c[222][222], f[222][222], flow, l[222], d[222], cntEven;
bool primes[22000], used[222];
vector<int> graph[222];
vector<vector<int> > cycles;

void bfs() {
    queue<int> q;
    l[0] = 0;
    q.push(0);
    while (q.size()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < n + 2; i++) {
            if (c[cur][i] > f[cur][i] && l[i] == -1) {
                l[i] = l[cur] + 1;
                q.push(i);
            }
        }
    }
}

int dfs(int v, int mx = INF) {
    if (mx == 0) {
        return 0;
    }
    if (v == n + 1) {
        return mx;
    }
    for (; d[v] < n + 2; d[v]++) {
        if (l[d[v]] != l[v] + 1) {
            continue;
        }
        int pushed = dfs(d[v], min(mx, c[v][d[v]] - f[v][d[v]]));
        if (pushed) {
            f[v][d[v]] += pushed;
            f[d[v]][v] -= pushed;
            return pushed;
        }
    }
    return 0;
}

void dinic() {
    for (int run = 1; run; ) {
        run = 0;
        memset(l, -1, (n + 2) * sizeof(int));
        memset(d, 0, (n + 2) * sizeof(int));
        bfs();
        while (int pushed = dfs(0)) {
            flow += pushed;
            run = 1;
        }
    }
}

void dfs2(int v) {
    if (used[v]) {
        return;
    }
    used[v] = true;
    cycles.back().pb(v);
    for (auto i : graph[v]) {
        dfs2(i);
    }
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] & 1) {
            c[i][n + 1] = 2;
        } else {
            c[0][i] = 2;
            cntEven++;
        }
    }
    for (int i = 2; i < 22000; i++) {
        primes[i] = true;
    }
    for (int i = 2; i * i < 22000; i++) {
        for (int j = i * i; j < 22000; j += i) {
            primes[j] = false;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!(a[i] & 1)) {
            for (int j = 1; j <= n; j++) {
                if (primes[a[i] + a[j]]) {
                    c[i][j] = 1;
                }
            }
        }
    }
    dinic();

    if (flow == cntEven * 2) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (f[i][j] != 0) {
                    graph[i].pb(j);
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                cycles.pb(vector<int>());
                dfs2(i);
            }
        }
        printf("%d\n", (int) cycles.size());
        for (auto i : cycles) {
            printf("%d ", (int) i.size());
            for (auto j : i) {
                printf("%d ", j);
            }
            printf("\n");
        }
    } else {
        printf("Impossible\n");
    }
    return 0;
}