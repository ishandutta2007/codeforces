#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, s;
vector<PII> g[1000005];
vector<int> rev[1000005];
vector<PII> ng[1000005];
vector<int> ord;
int cmp[1000005];
int curCmp;
bool used[1000005];
LL vcost[1000005];
LL d[1000005];

void dfs1(int v) {
    used[v] = true;
    for (PII to : g[v]) if (!used[to.first]) {
        dfs1(to.first);
    }
    ord.pb(v);
}

void dfs2(int v) {
    used[v] = true;
    cmp[v] = curCmp;
    for (int to : rev[v]) if (!used[to]) {
        dfs2(to);
    }
}

LL getCost(int x) {
    int lo = 1, hi = 20000, mid;
    while (lo < hi) {
        mid = (lo + hi + 1) >> 1;
        if (mid * (mid - 1) / 2 <= x) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    return (LL)lo * x - LL(lo - 1) * lo * (lo + 1) / 6;
}

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    forn(i, m) {
        int from, to, w;
        scanf("%d%d%d", &from, &to, &w), --from, --to;
        g[from].pb(mp(to, w));
        rev[to].pb(from);
    }
    scanf("%d", &s), --s;
    forn(i, n) used[i] = false;
    forn(i, n) if (!used[i]) {
        dfs1(i);
    }
    reverse(ord.begin(), ord.end());
    curCmp = 0;
    forn(i, n) used[i] = false;
    forn(ii, n) {
        int i = ord[ii];
        if (!used[i]) {
            dfs2(i);
            ++curCmp;
        }
    }
    forn(i, n) for (PII to : g[i]) {
        if (cmp[i] == cmp[to.first]) {
            vcost[cmp[i]] += getCost(to.second);
        } else {
            ng[cmp[i]].pb(mp(cmp[to.first], to.second));
        }
    }
    n = curCmp;
    s = cmp[s];
    memset(d, -1, sizeof d);
    d[s] = vcost[s];
    LL ans = d[s];
    for (int i = s; i < n; ++i) if (d[i] >= 0) {
        for (PII to : ng[i]) {
            d[to.first] = max(d[to.first], d[i] + to.second + vcost[to.first]);
            ans = max(ans, d[to.first]);
        }
    }
    cout << ans << endl;
    return 0;
}