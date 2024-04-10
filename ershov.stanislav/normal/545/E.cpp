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

const int N = 3e5 + 100;

struct edge{
    int u, v, w, i;
    edge(int u = 0, int v = 0, int w = 0, int i = 0) : u(u), v(v), w(w), i(i) {}
    bool operator<(const edge & b) {
        return w < b.w;
    }
};

int n, m, par[N];
ll dist[N];
vector<pair<int, int> > graph[N];
vector<edge> edges;

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        graph[u].eb(v, w);
        graph[v].eb(u, w);
        edges.eb(u, v, w, i);
    }
    int u;
    scanf("%d", &u);
    for (int i = 1; i <= n; i++) {
        dist[i] = lINF;
    }
    dist[u] = 0;
    set<pair<int, int> > s;
    s.insert(mp(0, u));
    while (s.size()) {
        int cur = s.begin()->sc;
        s.erase(s.begin());
        for (auto j : graph[cur]) {
            if (dist[j.fs] > dist[cur] + j.sc) {
                s.erase(mp(dist[j.fs], j.fs));
                dist[j.fs] = dist[cur] + j.sc;
                s.insert(mp(dist[j.fs], j.fs));
            }
        }
    }
    ll sum = 0;
    map<int, edge> ans;
    for (int i = 1; i <= n; i++) {
        par[i] = -1;
    }
    for (auto i : edges) {
        if (dist[i.u] > dist[i.v]) {
            swap(i.u, i.v);
        }
        if (dist[i.v] == dist[i.u] + i.w) {
            if (par[i.v] < dist[i.u]) {
                par[i.v] = dist[i.u];
                ans[i.v] = i;
            }
        }
    }
    for (auto i : ans) {
        sum += i.sc.w;
    }
    printf(LLD "\n", sum);
    for (auto i : ans) {
        printf("%d ", i.sc.i + 1);
    }
    return 0;
}