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

#define prev mprev

struct SAT2 {
    vector<vector<int> > es;
    vector<vector<int> > inves;
    vector<int> used;
    vector<int> topsort;
    vector<int> components;
    vector<int> istrue;
    bool flag;
    int maxu;
    void makesize(int n) {
        es.assign(n * 2, vector<int>());
    }
    int addv() {
        es.pb(vector<int>());
        es.pb(vector<int>());
        return sz(es) / 2 - 1;
    }
    void adde(int a, int istrue1, int b, int istrue2) {
        es[a * 2 + istrue1].pb(b * 2 + istrue2);
        es[b * 2 + !istrue2].pb(a * 2 + !istrue1);
        //printf("%d %d %d %d\n", a, istrue1, b, istrue2);
    }
    void makefalse(int v) {
        adde(v, true, v, false);
    }
    void maketrue(int v) {
        adde(v, false, v, true);
    }
    void dfs1(int v) {
        if (used[v] == maxu) {
            return;
        }
        used[v] = maxu;
        for (int i = 0; i < sz(es[v]); i++) {
            dfs1(es[v][i]);
        }
        topsort.pb(v);
    }
    void dfs2(int v) {
        if (used[v] == maxu) {
            return;
        }
        used[v] = maxu;
        components.pb(v);
        for (int i = 0; i < sz(inves[v]); i++) {
            dfs2(inves[v][i]);
        }
    }
    void dfs3(int v) {
        if (istrue[v / 2] != -1) {
            if (istrue[v / 2] != (v & 1)) {
                flag = false;
            }
            return;
        }
        istrue[v / 2] = (v & 1);
        for (int i = 0; i < sz(es[v]); i++) {
            dfs3(es[v][i]);
        }
    }
    void solve() {
        used.assign(sz(es), 0);
        maxu++;
        for (int i = 0; i < sz(es); i++) {
            dfs1(i);
        }
        inves.assign(sz(es), vector<int>());
        for (int i = 0; i < sz(es); i++) {
            for (int j = 0; j < sz(es[i]); j++) {
                inves[es[i][j]].pb(i);
            }
        }
        maxu++;
        for (int i = sz(es) - 1; i >= 0; i--) {
            dfs2(topsort[i]);
        }
        istrue.assign(sz(es) / 2, -1);
        flag = true;
        for (int i = sz(components) - 1; i >= 0; i--) {
            if (istrue[components[i] / 2] == -1) {
                dfs3(components[i]);
            }
        }
    }
};

const int maxn = 5e4 + 100;
int n, m, cnte;
int times[maxn];
vector<pair<int, int> > graph[maxn];
vector<vector<int> > types[maxn];
SAT2 sat2first;

bool solve(int maxt, bool print = false) {
    SAT2 sat2;
    sat2.es = sat2first.es;
    for (int i = 0; i < m; i++) {
        if (times[i] > maxt) {
            sat2.maketrue(i);
        }
    }
    
    sat2.solve();
    if (print) {
        assert(sat2.flag);
        vector<int> todel;
        for (int i = 0; i < m; i++) {
            if (!sat2.istrue[i]) {
                todel.pb(i);
            }
        }
        printf("%d %d\n", maxt, sz(todel));
        for (int i = 0; i < sz(todel); i++) {
            printf("%d%c", todel[i] + 1, " \n"[i == sz(todel) - 1]);
        }
    }
    return sat2.flag;
}

int main() {
#ifdef LOCAL
    freopen("text.in", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int v, u, c, t;
        scanf("%d%d%d%d", &v, &u, &c, &t);
        v--, u--;
        graph[v].emplace_back(c, cnte);
        graph[u].emplace_back(c, cnte);
        times[cnte] = t;
        cnte++;
    }
    for (int i = 0; i < n; i++) {
        sort(all(graph[i]));
        for (int j = 0; j < sz(graph[i]); j++) {
            if (j == 0 || graph[i][j - 1].first < graph[i][j].first) {
                types[i].push_back(vector<int>());
            }
            types[i].back().push_back(graph[i][j].second);
        }
    }
    sat2first.makesize(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sz(types[i]); j++) {
            if (sz(types[i][j]) > 2) {
                printf("No\n");
                return 0;
            } else if (sz(types[i][j]) == 2) {
                sat2first.adde(types[i][j][0], 1, types[i][j][1], 0);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1, prev = -1; j < sz(graph[i]); j++) {
            int cur = sat2first.addv();
            sat2first.adde(cur, 1, graph[i][j - 1].second, 1);
            if (prev != -1) {
                sat2first.adde(cur, 1, prev, 1);
            }
            sat2first.adde(graph[i][j].second, 0, cur, 1);
            prev = cur;
        }
    }
    int L = -1, R = (int) 1e9 + 100;
    while (L < R - 1) {
        int mid = (L + R) / 2;
        if (solve(mid)) {
            R = mid;
        } else {
            L = mid;
        }
    }
    if (L > 1e9) {
        printf("No\n");
    } else {
        printf("Yes\n");
        solve(L + 1, true);
    }
    return 0;
}