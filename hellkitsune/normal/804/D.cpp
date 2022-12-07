#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, q;
vector<int> g[100005];
int cnt, c[100005];
vector<int> cm[100005];
int szcm[100005];
vector<int> pcnt[100005];
vector<LL> psum[100005];
int dist[100005], dst[100005];

void dfs(int v) {
    c[v] = cnt;
    cm[cnt].pb(v);
    for (int to : g[v]) if (c[to] == -1) {
        dfs(to);
    }
}

void calc(int v, int d) {
    dist[v] = d;
    for (int to : g[v]) if (dist[to] == -1) {
        calc(to, d + 1);
    }
}

map<PII, double> ma;

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &q);
    forn(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    memset(c, -1, sizeof c);
    forn(i, n) if (c[i] == -1) {
        dfs(i);

        for (int v : cm[cnt]) {
            dist[v] = -1;
        }
        calc(cm[cnt][0], 0);
        int a = cm[cnt][0];
        for (int v : cm[cnt]) {
            if (dist[v] > dist[a]) {
                a = v;
            }
        }
        for (int v : cm[cnt]) {
            dist[v] = -1;
        }
        calc(a, 0);
        int b = cm[cnt][0];
        for (int v : cm[cnt]) {
            if (dist[v] > dist[b]) {
                b = v;
            }
        }
        szcm[cnt] = dist[b];
        for (int v : cm[cnt]) {
            dst[v] = dist[v];
            dist[v] = -1;
        }
        calc(b, 0);

        pcnt[cnt].assign(szcm[cnt] + 1, 0);
        psum[cnt].assign(szcm[cnt] + 1, 0);

        for (int v : cm[cnt]) {
            int d = max(dst[v], dist[v]);
            ++pcnt[cnt][d];
            psum[cnt][d] += d;
        }
        forn(i, szcm[cnt]) {
            pcnt[cnt][i + 1] += pcnt[cnt][i];
            psum[cnt][i + 1] += psum[cnt][i];
        }

        ++cnt;
    }
    forn(test, q) {
        int u, v;
        scanf("%d%d", &u, &v), --u, --v;
        u = c[u];
        v = c[v];
        if (u > v) {
            swap(u, v);
        }
        if (u == v) {
            printf("-1\n");
            continue;
        }
        auto it = ma.find(mp(u, v));
        if (it != ma.end()) {
            printf("%.12f\n", it->second);
            continue;
        }
        double ans = 0;

        if (szcm[u] > szcm[v]) {
            swap(u, v);
        }
        int usz = szcm[u];
        int vsz = szcm[v];
        for (int i = (usz + 1) / 2; i <= usz; ++i) {
            double mul = double(pcnt[u][i] - (i ? pcnt[u][i - 1] : 0)) / pcnt[u][usz];
            int bad = vsz - i - 1;
            double delta = 0;
            if (bad >= 0) {
                delta += mul * pcnt[v][bad] * vsz;
//                cerr << "?";
            }
            if (bad < vsz) {
                delta += mul * (psum[v][vsz] - (bad >= 0 ? psum[v][bad] : 0ll));
                delta += mul * (pcnt[v][vsz] - (bad >= 0 ? pcnt[v][bad] : 0)) * (1 + i);
//                cerr << "!";
            }
            ans += delta / pcnt[v][vsz];
        }

        if (u > v) {
            swap(u, v);
        }
        printf("%.12f\n", ans);
        ma[mp(u, v)] = ans;
    }
    return 0;
}