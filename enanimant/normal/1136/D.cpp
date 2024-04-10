// March 11, 2019
//

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int MAXN = 300000;

int n, m;
unordered_map<int, int> id;
vector<int> adj[MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug_output.txt", "w", stderr);
#endif


    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        id[x] = i;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[id[u]].push_back(id[v]);
    }
    for (int i = 0; i < n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    int cur = n - 1;
    vector<bool> behind(n, false);
    for (int i = n - 2; i >= 0; i--) {
        if (adj[i].empty()) {
            continue;
        }
        int s = (int) adj[i].size();
        int ch = 0;
        for (int j : adj[i]) {
            if (j < i || behind[j]) {
                continue;
            }
            ch++;
        }
        if (ch == cur - i) {
            cur--;
            behind[i] = true;
        }
    }
    cout << n - 1 - cur << '\n';


    return 0;
}