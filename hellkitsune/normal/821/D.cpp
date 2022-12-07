#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MX = 10000;
const int INF = int(1e9);

int n, m, k;
int r[10000], c[10000];
map<PII, int> ma;
vector<PII> g[30001];
int dist[30001];
int pre[30001];

struct Cmp {
    inline bool operator()(const int &lhs, const int &rhs) const {
        if (dist[lhs] != dist[rhs]) return dist[lhs] < dist[rhs];
        return lhs < rhs;
    }
};

set<int, Cmp> q;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int main() {
    scanf("%d%d%d", &n, &m, &k);
    forn(i, k) {
        scanf("%d%d", r + i, c + i);
        --r[i], --c[i];
        ma[mp(r[i], c[i])] = i;
    }
    const int LAST = k + 2 * MX;
    const int CNT = LAST + 1;
    forn(i, k) {
        forn(dir, 4) {
            int rr = r[i] + dx[dir];
            int cc = c[i] + dy[dir];
            auto it = ma.find(mp(rr, cc));
            if (it != ma.end()) {
                g[i].pb(mp(it->second, 0));
            }
        }
        for (int x = max(0, r[i] - 1); x <= min(n - 1, r[i] + 1); ++x) {
            g[i].pb(mp(x + k, 1));
            g[x + k].pb(mp(i, 0));
        }
        for (int x = max(0, c[i] - 1); x <= min(m - 1, c[i] + 1); ++x) {
            g[i].pb(mp(x + k + MX, 1));
            g[x + k + MX].pb(mp(i, 0));
        }
    }
    g[k + n - 1].pb(mp(LAST, 0));
    g[k + MX + m - 1].pb(mp(LAST, 0));
    auto it = ma.find(mp(n - 1, m - 1));
    if (it != ma.end()) {
        g[it->second].pb(mp(LAST, 0));
    }
    it = ma.find(mp(0, 0));
    assert(it != ma.end());
    int st = it->second;

    forn(i, CNT) dist[i] = INF;
    dist[st] = 0;
    q.insert(st);

    while (!q.empty()) {
        int v = *q.begin();
        q.erase(q.begin());
        for (PII to : g[v]) if (dist[to.first] > dist[v] + to.second) {
            q.erase(to.first);
            dist[to.first] = dist[v] + to.second;
            pre[to.first] = v;
            q.insert(to.first);
        }
    }
//    for (int v = LAST; v != st; v = pre[v]) {
//        cerr << v << ' ';
//    }
//    cerr << endl;

    if (dist[LAST] == INF) dist[LAST] = -1;
    cout << dist[LAST] << endl;
    return 0;
}