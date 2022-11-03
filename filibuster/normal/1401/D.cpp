#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 1e5 + 13;

int sum(int a, int b) {
    int res = a + b;
    if(res >= M)
        res -= M;

    return res;
}

vector<int> g[N];
int sz[N];
vector<pii> e;

void dfs(int v, int pr) {
    sz[v] = 1;

    for(auto u : g[v]) {
        if(u == pr)
            continue;

        dfs(u, v);
        sz[v] += sz[u];
    }
}

int n;

bool cmp(pii a, pii b) {
    int mn = min(sz[a.f], sz[a.s]);
    li x = mn * 1ll * (n - mn);

    mn = min(sz[b.f], sz[b.s]);
    li y = mn * 1ll * (n - mn);

    return (x > y);
}

void solve() {

    cin >> n;

    for(int i = 0; i < n; i++) {
        g[i].erase(g[i].begin(), g[i].end());
        sz[i] = 0;
    }
    e.erase(e.begin(), e.end());

    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        if(v > u)
            swap(v, u);

        e.emplace_back(v,u);
        g[v].push_back(u);
        g[u].push_back(v);
    }

    dfs(0, 0);

    sort(e.begin(), e.end(), cmp);

    int m;
    cin >> m;

    vector<int> p(m);
    for(int i = 0; i < m; i++) {
        cin >> p[i];
    }



    if(m > n - 1) {
        sort(p.begin(), p.end());
        int mn = min(sz[e[0].f], sz[e[0].s]);
        int ans = mn * 1ll * (n - mn) % M;
        for(int i = n - 2; i < m; i++) {
            ans = ans * 1ll * p[i] % M;
        }

        for(int i = 1; i < n - 1; i++) {
            int mn = min(sz[e[i].f], sz[e[i].s]);
            ans = sum(ans, p[n - 2 - i] * 1ll * mn % M * 1ll * (n - mn) % M);
        }

        cout << ans << endl;
    } else {
        int ans = 0;
        sort(p.rbegin(), p.rend());
        for(int i = 0; i < n - 1; i++) {
            int x = (i < m ? p[i] : 1);
            int mn = min(sz[e[i].f], sz[e[i].s]);
//            cout << e[i].f << ' ' << e[i].s << ' ' << x << ' ' << mn << endl;
            ans = sum(ans, x * 1ll * mn % M * 1ll * (n - mn) % M);
        }

        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}