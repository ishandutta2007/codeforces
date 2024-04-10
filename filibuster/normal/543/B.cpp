#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e8 + 13;

const int N = 3000 + 13;

/*
*/

vector<int> g[N];
int d[N][N];
int n;

void bfs(int root) {
    for(int i = 0; i < n; i++)
        d[root][i] = INF;
    d[root][root] = 0;

    queue<int> q;
    q.push(root);

    while(!q.empty()) {
        int v = q.front();
        q.pop();

        for(auto u : g[v]) {
            if(d[root][u] == INF) {
                d[root][u] = d[root][v] + 1;
                q.push(u);
            }
        }
    }
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
    int m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    for(int i = 0; i < n; i++)
        bfs(i);

    int s1, t1, l1, s2, t2, l2;
    cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;

    s1--;
    t1--;
    s2--;
    t2--;

    if(d[s1][t1] > l1 || d[s2][t2] > l2) {
        cout << -1;
        return 0;
    }

    int ans = d[s1][t1] + d[s2][t2];
    for(int v = 0; v < n; v++) {
        for(int u = 0; u < n; u++) {
            int res = INF;
            if(d[s1][v] + d[v][u] + d[u][t1] <= l1 && d[s2][v] + d[v][u] + d[u][t2] <= l2)
                res = min(res, d[v][s1] + d[v][s2] + d[v][u] + d[u][t1] + d[u][t2]);

//            if(v == 1 && u == 2) {
//                cout << d[s1][v] + d[v][u] + d[u][t1] << ' ' << d[s1][v] + d[v][u] + d[u][t2] << endl;
//            }

            if(d[s1][v] + d[v][u] + d[u][t1] <= l1 && d[s2][u] + d[v][u] + d[v][t2] <= l2)
                res = min(res, d[v][s1] + d[v][t2] + d[v][u] + d[u][t1] + d[u][s2]);

//            cout << v << ' '<< u << ' ' << res << endl;
            ans = min(ans, res);
//            ans = min(ans, min(d[v][s1] + d[v][s2] + d[v][u] + d[u][t1] + d[u][t2],
//                               d[v][s1] + d[v][t2] + d[v][u] + d[u][t1] + d[u][s2]));
        }
    }

    cout << m - ans;
}