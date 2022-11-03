#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int N = 2e5 + 13;

vector<int> g[N], r[N];
bool used[N];
vector<int> ts;
int d[N];

void dfs(int v) {
    used[v] = true;

    for(auto u : g[v])
        if(!used[u])
            dfs(u);

    ts.push_back(v);
}

/*
2
4 6
1 2
1 3
2 3
2 4
3 4
3 4

7 6
1 2
1 3
2 4
2 5
3 6
3 7

*/

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        g[i].erase(g[i].begin(), g[i].end());
        r[i].erase(r[i].begin(), r[i].end());
        used[i] = false;
        d[i] = 0;
    }
    ts.erase(ts.begin(), ts.end());

    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;

        g[v - 1].push_back(u - 1);
        r[u - 1].push_back(v - 1);
    }

    for(int i = 0; i < n; i++)
        if(!used[i])
            dfs(i);

    reverse(ts.begin(), ts.end());

    for(int i = 0; i < n; i++)
        used[i] = false;

    vector<int> ans;

    for(auto v : ts) {
        bool res = true;
        for(auto p : r[v])
            if(d[p] == 0)
                d[v] = max(d[v], 1);
            else if(d[p] == 1)
                res = false;

//        cout << v << ' ' << d[v] << ' ' << res << endl;

        if(!res) {
            ans.push_back(v);
            d[v] = -1;
        }
    }

    cout << ans.size() << endl;
    for(auto x : ans)
        cout << x + 1 << ' ';
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}