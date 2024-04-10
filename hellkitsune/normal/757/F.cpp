#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const LL INF = LL(1e18);

int n, m, s;
vector<PII> gg[200005];
vector<int> g[200005], inv[200005];
LL dist[200005];
int best[200005];

struct Cmp {
    inline bool operator()(const int &lhs, const int &rhs) const {
        if (dist[lhs] != dist[rhs]) return dist[lhs] < dist[rhs];
        return lhs < rhs;
    }
};

set<int, Cmp> q;

inline bool cmp(const int &lhs, const int &rhs) {
    return dist[lhs] < dist[rhs];
}

int ord[200005];
map<int, int> ma;

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &s);
    --s;
    forn(i, m) {
        int from, to, w;
        scanf("%d%d%d", &from, &to, &w), --from, --to;
        gg[from].pb(mp(to, w));
        gg[to].pb(mp(from, w));
    }
    forn(i, n) {
        dist[i] = INF;
    }
    dist[s] = 0;
    q.insert(s);
    while (!q.empty()) {
        int v = *q.begin();
        q.erase(q.begin());
        for (PII to : gg[v]) if (dist[to.first] > dist[v] + to.second) {
            q.erase(to.first);
            dist[to.first] = dist[v] + to.second;
            q.insert(to.first);
        }
    }
    forn(v, n) for (PII to : gg[v]) {
        if (dist[to.first] == dist[v] + to.second) {
            g[v].pb(to.first);
            inv[to.first].pb(v);
        }
    }
    forn(i, n) {
        ord[i] = i;
    }
    sort(ord, ord + n, cmp);
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        int ind = ord[i];
        if (dist[ind] == INF) {
            break;
        }
        best[ind] = ind;
        for (int x : inv[ind]) {
            if (x == s) {
                best[ind] = ind;
                break;
            }
            if (best[ind] == ind) {
                best[ind] = best[x];
            } else if (best[ind] != best[x]) {
                best[ind] = ind;
                break;
            }
        }
        ans = max(ans, ++ma[best[ind]]);
    }
    cout << ans << endl;
    return 0;
}