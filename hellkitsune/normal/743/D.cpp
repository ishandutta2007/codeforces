#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const LL INF = LL(1e18);

int n;
int a[200005];
LL sum[200005];
vector<int> g[200005];
LL d[200005][2];

void solve(int v, int par) {
    d[v][0] = d[v][1] = -INF;
    sum[v] = a[v];
    for (int to : g[v]) if (to != par) {
        solve(to, v);
        sum[v] += sum[to];
        d[v][1] = max(d[v][1], d[to][1]);
        d[v][1] = max(d[v][1], d[v][0] + d[to][0]);
        d[v][0] = max(d[v][0], d[to][0]);
    }
    d[v][0] = max(d[v][0], sum[v]);
    //cerr << v + 1 << ": " << d[v][0] << ' ' << d[v][1] << endl;
}

int main() {
    scanf("%d", &n);
    forn(i, n) {
        scanf("%d", a + i);
    }
    forn(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to);
        --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    solve(0, -1);
    if (d[0][1] < -INF / 2) {
        cout << "Impossible" << endl;
    } else {
        cout << d[0][1] << endl;
    }
    return 0;
}