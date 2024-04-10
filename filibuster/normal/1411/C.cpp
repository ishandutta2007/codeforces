#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 1e5 + 13;

vector<int> g[N];
int used[N];

int ans = 0;

void dfs(int v, int par) {
//    cout << "dfs " << v << ' ' << par <<endl;
    used[v] = 1;

    for(auto u : g[v]) {
        if(used[u] == 1) {
            if(par != -1)
                ans++;
//            cout << "cyc " << v << ' ' << u << endl;
        }else if(used[u] == 0)
            dfs(u, v);



    }

    used[v] = 2;
}

void solve() {
    int n, m;
    cin >> n >> m;

    ans = 0;
    for(int i = 0; i <= n; i++) {
        g[i].erase(g[i].begin(), g[i].end());
        used[i] = 0;
    }

    vector<pii> a(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i].f >> a[i].s;

        if(a[i].f != a[i].s) {
            ans++;
            g[a[i].f].push_back(a[i].s);
//            g[a[i].s].push_back(a[i].f);
        }
    }
    for(int i = 1; i <= n; i++)
        if(!used[i])
            dfs(i, -1);
    cout << ans << endl;
}

/*
1
5 3
2 3
3 1
1 2

1
3 2
2 1
1 2

1
5 4
4 5
5 1
2 2
3 3
*/

int main() {

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}