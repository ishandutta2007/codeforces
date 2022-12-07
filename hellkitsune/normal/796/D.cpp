#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k, d;
int p[300000];
vector<PII> g[300000];
set<int> ans;

queue<int> q;
int dist[300000];

int main() {
    scanf("%d%d%d", &n, &k, &d);
    forn(i, k) {
        scanf("%d", p + i), --p[i];
    }
    forn(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to);
        --from, --to;
        g[from].pb(mp(to, i + 1));
        g[to].pb(mp(from, i + 1));
    }
    memset(dist, -1, sizeof dist);
    forn(i, k) if (dist[p[i]] == -1) {
        dist[p[i]] = 0;
        q.push(p[i]);
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (PII to : g[v]) if (dist[to.first] == -1) {
            dist[to.first] = dist[v] + 1;
            q.push(to.first);
        }
    }
    forn(i, n) if (dist[i] != 0) {
        int bestDist = 12341234;
        int bestInd = -1;
        for (PII to : g[i]) if (dist[to.first] < bestDist) {
            bestDist = dist[to.first];
            bestInd = to.second;
        }
        ans.insert(bestInd);
    }
    printf("%d\n", n - 1 - (int)ans.size());
    for (int i = 1; i < n; ++i) {
        if (!ans.count(i)) {
            printf("%d ", i);
        }
    }
    puts("");
    return 0;
}