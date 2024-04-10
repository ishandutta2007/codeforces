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

#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-10;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 1e5 + 100;

struct road {
    int a, b, l;
    road(int a = 0, int b = 0, int l = 0) : a(a), b(b), l(l) {}
    void get() {
        scanf("%d%d%d", &a, &b, &l);
    }
};

int n, m, s, t;
ll dist[N], r_dist[N], total;
vector<road> roads;
vector<pair<int, int> > graph[N], r_graph[N];
vector<int> new_graph[N], new_r_graph[N];
bool used[N], used2[N], used3[N], can[N];
void dijk(ll * d, vector<pair<int, int> > * g, int b) {
    for (int i = 1; i <= n; i++) {
        d[i] = lINF;
    }
    d[b] = 0;
    set<pair<ll, int> > st;
    st.insert(mp(0, b));
    while (st.size() != 0) {
        int cur = st.begin()->sc;
        st.erase(st.begin());
        for (auto i : g[cur]) {
            if (d[i.fs] > d[cur] + i.sc) {
                st.erase(mp(d[i.fs], i.fs));
                d[i.fs] = d[cur] + i.sc;
                st.insert(mp(d[i.fs], i.fs));
            }
        }
    }
}

void dfs(int v) {
    if (used[v]) {
        return;
    }
    used[v] = true;
    for (auto i : new_graph[v]) {
        dfs(i);
    }
}

void dfs2(int v) {
    if (!used[v]) {
        return;
    }
    if (used2[v]) {
        return;
    }
    used2[v] = true;
    for (auto i : new_r_graph[v]) {
        dfs2(i);
    }
}

vector<int> tpsrt;
int tpsrt_rev[N], cnt[N];

void topsort(int v) {
    if (used3[v]) {
        return;
    }
    used3[v] = true;
    for (auto i : new_graph[v]) {
        topsort(i);
    }
    if (v != t) tpsrt.pb(v);
}

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 0; i < m; i++) {
        road r;
        r.get();
        roads.pb(r);
        graph[r.a].eb(r.b, r.l);
        r_graph[r.b].eb(r.a, r.l);
    }
    dijk(dist, graph, s);
    dijk(r_dist, r_graph, t);
    total = dist[t];
    for (int i = 0; i < m; i++) {
        if (dist[roads[i].b] == dist[roads[i].a] + roads[i].l) {
            new_graph[roads[i].a].pb(roads[i].b);
            new_r_graph[roads[i].b].pb(roads[i].a);
        }
    }
    dfs(s);
    dfs2(t);
//    for (int i = 1; i <= n; i++) {
//        cout << dist[i] << ' ' << r_dist[i] << ' ' << used[i] << ' ' << used2[i] << endl;
//    }
    tpsrt.pb(t);
    topsort(s);
    reverse(all(tpsrt));
    for (int i = 0; i < (int) tpsrt.size(); i++) {
        tpsrt_rev[tpsrt[i]] = i;
    }
    int mn = tpsrt.size();
    for (int i = tpsrt.size() - 1; i >= 0; i--) {
        if (mn < i) {
            can[tpsrt[i]] = true;
        }
        if (used2[tpsrt[i]]) {
            for (auto j : new_r_graph[tpsrt[i]]) {
                mn = min(mn, tpsrt_rev[j]);
            }
        }
    }
//    for (auto i : tpsrt) {
//        cout << i << endl;
//    }
//    for (int i = 1; i <= n; i++) {
//        cout << can[i] << endl;
//    }
    for (int i = 1; i <= n; i++) {
        for (auto j : new_r_graph[i]) {
            if (used[j]) {
                cnt[i]++;
            }
        }
    }
    for (auto i : roads) {
        if (cnt[i.b] == 1 && !can[i.b] && used2[i.b] && dist[i.b] == dist[i.a] + i.l) {
            printf("YES\n");
        } else {
            if (total - 1 - dist[i.a] - r_dist[i.b] > 0) {
                printf("CAN %d\n", (int) (i.l - (total - 1 - dist[i.a] - r_dist[i.b])));
            } else {
                printf("NO\n");
            }
        }
    }
    return 0;
}