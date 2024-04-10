#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int maxn = 500005;
vector<int> adj[maxn];
int a[maxn], b[maxn], ord[maxn];
bool s[maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v); adj[v].pb(u);
    }
    for (int i = 0; i < n; i++)
        cin >> a[i];
    iota(ord, ord+n, 0);
    sort(ord, ord+n, [&](int x, int y){return a[x] < a[y];});
    fill(b, b+n, -1);
    for (int k = 0; k < n; k++) {
        int i = ord[k];
        for (auto& j : adj[i])
            if (a[j] != -1) s[a[j]] = 1;
        int x = 1;
        while (s[x]) x++;
        b[i] = x;
        for (auto& j : adj[i])
            if (a[j] != -1) s[a[j]] = 0;
        if (b[i] != a[i]) {
            cout << "-1\n"; return 0;
        }
    }
    for (int k = 0; k < n; k++)
        cout << ord[k]+1 << " ";
}