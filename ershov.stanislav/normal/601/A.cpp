#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int maxn = 500;
int n, m;
int d[maxn][maxn];
vector<int> g1[maxn], g2[maxn];
int dist[maxn];

int main() {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        d[a][b] = d[b][a] = 1;
        g1[a].pb(b);
        g1[b].pb(a);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            if (d[i][j]) {
                continue;
            }
            g2[i].pb(j);
        }
    }
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while (q.size()) {
        int cur = q.front();
        q.pop();
        for (auto i : g1[cur]) {
            if (dist[i] == INF) {
                q.push(i);
                dist[i] = dist[cur] + 1;
            }
        }
    }
    int t1 = dist[n - 1];
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[0] = 0;
    while (q.size()) {
        q.pop();
    }
    q.push(0);
    while (q.size()) {
        int cur = q.front();
        q.pop();
        for (auto i : g2[cur]) {
            if (dist[i] == INF) {
                q.push(i);
                dist[i] = dist[cur] + 1;
            }
        }
    }
    int t2 = dist[n - 1];
    int ans = max(t1, t2);
    if (ans == INF) {
        printf("-1\n");
    } else {
        printf("%d\n", ans);
    }
    return 0;
}