#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 1<<17;
vector<int> adj[N];
int vin[N], vout[N], d[N], a[N], a_v[N];
int t = 0;

int aa[2*N], bb[2*N];
int min_d[2*N], max_d[2*N];
vector<int> tree[2*N];

void dfs(int i, int k) {
    vin[i] = t++;
    d[vin[i]] = d[vin[k]]+1;
    a_v[vin[i]] = a[i];
    for (int j : adj[i])
        if (j != k)
            dfs(j, i);
    vout[i] = t-1;
}

int query(int l, int r, int k, int i = 1) {
    if (l <= aa[i] && r >= bb[i]) {
        debug(i, aa[i], bb[i], k);
        if (k < min_d[i]) return inf;
        if (k > max_d[i]) return tree[i].back();
        return tree[i][k-min_d[i]];
    }
    if (l > bb[i] || r < aa[i])
        return inf;
    return min(query(l, r, k, 2*i), query(l, r, k, 2*i+1));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, r; cin >> n >> r; r--;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].pb(y), adj[y].pb(x);
    }
    dfs(r, r);

    for (int i = 0; i < N; i++)
        aa[N+i] = bb[N+i] = i;
    for (int i = N-1; i > 0; i--)
        aa[i] = aa[2*i], bb[i] = bb[2*i+1];

    for (int i = 1; i < 2*N; i++) {
        if (bb[i] >= n) continue;
        min_d[i] = inf, max_d[i] = -inf;
        for (int j = aa[i]; j <= bb[i]; j++) {
            cmin(min_d[i], d[j]);
            cmax(max_d[i], d[j]);
        }
        tree[i].assign(max_d[i]-min_d[i]+1, inf);
        for (int j = aa[i]; j <= bb[i]; j++) {
            cmin(tree[i][d[j]-min_d[i]], a_v[j]);
        }
        for (int j = 1; j < tree[i].size(); j++)
            cmin(tree[i][j], tree[i][j-1]);
    }

    int m; cin >> m;
    int last = 0;
    while (m--) {
        int x, k; cin >> x >> k;
        x = (x+last)%n, k = (k+last)%n;
        debug(x, vin[x], vout[x], k, d[vin[x]]);
        last = query(vin[x], vout[x], d[vin[x]]+k);
        cout << last << "\n";
    }
}