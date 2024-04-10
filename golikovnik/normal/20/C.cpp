#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define endl '\n'
#define X first
#define Y second

const ll MAXN = 1e18;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> graph(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        ll w;
        cin >> x >> y >> w;
        --x; --y;
        graph[x].pb(mp(y, w));
        graph[y].pb(mp(x, w));
    }
    int s = 0;
    vector<ll> d(n, MAXN);
    vi p(n);
    d[s] = 0;
    p[s] = -1;
    set<pair<ll, int>> q;
    q.insert(mp(d[s], s));
    while (!q.empty()) {
        int u = q.begin()->Y;
        q.erase(q.begin());
        for (int v = 0; v < graph[u].size(); ++v) {
            int to = graph[u][v].X;
            ll w = graph[u][v].Y;
            if (d[u] + w < d[to]) {
                q.erase(mp(d[to], to));
                d[to] = d[u] + w;
                p[to] = u;
                q.insert(mp(d[to], to));
            }
        }
    }
    if (d[n-1] == MAXN) {
        cout << -1;
        return 0;
    }
    vi path;
    for (int i = n - 1; i != -1; i = p[i]) {
        path.pb(i);
    }
    reverse(all(path));
    for (int x: path) {
        cout << x + 1 << " ";
    }
    return 0;
}