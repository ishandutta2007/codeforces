#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int INF = int(2e9);

int n, best = INF;
int d[2000][2000];
int dist[2000];
bool used[2000] = {};
PII ord[2100000];
int cnt = 0;

inline bool cmp(const PII &lhs, const PII &rhs) {
    return d[lhs.first][lhs.second] < d[rhs.first][rhs.second];
}

int main() {
    scanf("%d", &n);
    forn(i, n) forn(j, n - 1 - i) {
        int k = i + 1 + j;
        scanf("%d", &d[i][k]);
        d[k][i] = d[i][k];
        best = min(best, d[i][k]);
    }
    forn(i, n) forn(j, n) if (i != j) {
        d[i][j] -= best;
    }
    forn(i, n) dist[i] = INF;
    forn(i, n) forn(j, i) ord[cnt++] = mp(i, j);
    sort(ord, ord + cnt, cmp);
    forn(i, cnt) {
        int u = ord[i].first;
        int v = ord[i].second;
        dist[v] = min(dist[v], d[u][v] + min(d[u][v], dist[u]));
        dist[u] = min(dist[u], d[u][v] + min(d[u][v], dist[v]));
    }
    forn(i, n) cout << (LL)best * (n - 1) + dist[i] << '\n';
    return 0;
}