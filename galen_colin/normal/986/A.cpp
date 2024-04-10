//test, test for Eulerian

#include <bits/stdc++.h>
// #define int long long
using namespace std;
 
const int INF = 1e9;
const int N = 1e5 + 1;
const int K = 101;
vector<vector<int>> distances(N + 1, vector<int>(K + 1, INF));
vector<vector<int>> graph(N + 1);
vector<int> a(N + 1);
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    for (int t = 1; t <= k; t++) {
        vector<int> bfs;
        for (int i = 1; i <= n; i++) {
            if (a[i] == t) {
                bfs.push_back(i);
                distances[i][t] = 0;
            }
        }
        for (int i = 0; i < bfs.size(); i++) {
            int nd = bfs[i];
            int dist = distances[nd][t];
            for (int j: graph[nd]) {
                if (distances[j][t] == INF) {
                    distances[j][t] = dist + 1;
                    bfs.push_back(j);
                }
            }
        }
    }
 
    for (int i = 1; i <= n; i++) {
        sort(distances[i].begin(), distances[i].end());
        int ans = 0;
        for (int j = 0; j < s; j++)
            ans += distances[i][j];
        cout << ans << " ";
    }
 
    return 0;
}