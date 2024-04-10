#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = int(1e9) + 7;

int n, m, k;
LL c[500005];

vector<pair<LL, PII> > edges;

int par[500005], ra[500005];
LL p2[500005];

void dsuInit(int n) {
    p2[0] = 1;
    forn(i, 500003) {
        p2[i + 1] = 2 * p2[i] % MOD;
    }
    forn(i, n) {
        par[i] = i;
        ra[i] = 1;
    }
}

int dsuParent(int v) {
    if (par[v] == v) {
        return v;
    }
    return par[v] = dsuParent(par[v]);
}

bool dsuMerge(int u, int v) {
    u = dsuParent(u);
    v = dsuParent(v);
    if (u == v) {
        return false;
    }
    if (ra[u] < ra[v]) {
        swap(u, v);
    }
    par[v] = u;
    ra[u] += ra[v];
    return true;
}

LL solve(int from, int to) {
    int sz = n;
    for (int i = from; i < to; ++i) {
        PII e = edges[i].second;
        if (dsuMerge(e.first, e.second)) {
            --sz;
        }
    }
    for (int i = from; i < to; ++i) {
        PII e = edges[i].second;
        par[e.first] = e.first;
        par[e.second] = e.second;
        ra[e.first] = 1;
        ra[e.second] = 1;
    }
    return p2[sz];
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    forn(i, n) {
        scanf("%I64d", c + i);
    }
    forn(i, m) {
        int from, to;
        scanf("%d%d", &from, &to);
        --from, --to;
        edges.pb(mp(c[from] ^ c[to], mp(from, to)));
    }
    sort(edges.begin(), edges.end());
    LL cnt = 1ll << k;
    LL ans = 0;
    dsuInit(n);
    for (int beg = 0; beg < m; ) {
        int end = beg + 1;
        while (end < m && edges[beg].first == edges[end].first) {
            ++end;
        }
        ans = (ans + solve(beg, end)) % MOD;
        beg = end;
        cnt -= 1;
    }
    ans = (ans + p2[n] * (cnt % MOD)) % MOD;
    cout << ans << endl;
    return 0;
}