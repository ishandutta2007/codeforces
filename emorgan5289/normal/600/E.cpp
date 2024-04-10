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

const int maxn = 100050;
int f[maxn] = {}, m = 0;
ll s[maxn] = {};
vector<int> adj[maxn];

void ins(int i) {
    s[f[i]] -= i;
    f[i]++;
    s[f[i]] += i;
    m = max(m, f[i]);
    if (s[m] == 0) m--;
}

void rem(int i) {
    s[f[i]] -= i;
    f[i]--;
    s[f[i]] += i;
    if (s[m] == 0) m--;
}

ll query() {
    return s[m];
}

int vin[maxn], vout[maxn], t = 0;

void dfs(int i, int p) {
    vin[i] = t++;
    for (auto& j : adj[i])
        if (j != p)
            dfs(j, i);
    vout[i] = t-1;
}

ll c[maxn], a[maxn], r[maxn];
int n, sn;
array<int, 3> q[maxn];

bool cmp(array<int, 3>& x, array<int, 3>& y) {
    return x[0]/sn == y[0]/sn ? x[1] < y[1] : x[0] < y[0];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    sn = int(sqrt(n));
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v), adj[v].pb(u);
    }
    dfs(0, 0);
    for (int i = 0; i < n; i++) {
        a[vin[i]] = c[i];
        q[i] = {vin[i], vout[i], i};
    }
    sort(q, q+n, cmp);
    int px = 0, py = -1;
    for (int i = 0; i < n; i++) {
        int x = q[i][0], y = q[i][1], j = q[i][2];
        for (;px < x; px++)
            rem(a[px]);
        for (;px > x; px--)
            ins(a[px-1]);
        for (;py < y; py++)
            ins(a[py+1]);
        for (;py > y; py--)
            rem(a[py]);
        r[j] = query();
    }
    for (int i = 0; i < n; i++)
        cout << r[i] << " \n"[i==n-1];
}