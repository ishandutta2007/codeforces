#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int maxn = 100005;
int n, m, t = 0, sn;
int c[maxn], a[maxn], vin[maxn], vout[maxn], res[maxn];
vector<int> adj[maxn];
array<int, 4> q[maxn];

int f[maxn], s[maxn];

void ins(int i) {
    f[i]++;
    s[f[i]]++;
}

void rem(int i) {
    s[f[i]]--;
    f[i]--;
}

int query(int i) {
    return s[i];
}

void dfs(int i, int p) {
    vin[i] = t++;
    a[vin[i]] = c[i];
    for (int j : adj[i])
        if (j != p)
            dfs(j, i);
    vout[i] = t-1;
}

bool cmp(array<int, 4>& x, array<int, 4>& y) {
    return x[0]/sn == y[0]/sn ? x[1] < y[1] : x[0] < y[0];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    sn = int(sqrt(n));
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v); adj[v].pb(u);
    }
    dfs(0, 0);
    for (int i = 0; i < m; i++) {
        int v, k; cin >> v >> k; v--;
        q[i] = {vin[v], vout[v], k, i};
    }
    sort(q, q+m, cmp);
    int x = 0, y = -1;
    for (int i = 0; i < m; i++) {
        // debug(q[i]);
        while (x > q[i][0]) {
            x--; ins(a[x]);
        }
        while (x < q[i][0]) {
            rem(a[x]); x++;
        }
        while (y < q[i][1]) {
            y++; ins(a[y]);
        }
        while (y > q[i][1]) {
            rem(a[y]); y--;
        }
        res[q[i][3]] = query(q[i][2]);
    }
    for (int i = 0; i < m; i++)
        cout << res[i] << "\n";
}