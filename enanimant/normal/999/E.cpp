#include <bits/stdc++.h>

using namespace std;


const int MAXN = 5000;


int N, M, S;
vector<int> adj[MAXN + 1];
int parent[MAXN + 1];
set<int> new_roads;

void dfs(int s, int p) {
    if (parent[s] == p) return;
    parent[s] = p;
    for (auto u : adj[s]) {
        if (u != S) dfs(u, p);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> S;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    fill(parent + 1, parent + N + 1, -1);
    for (int i = 1; i <= N; i++) {
        if (parent[i] == -1) {
            dfs(i, i);
        }
    }

    for (int i = 1; i <= N; i++) {
        new_roads.insert(parent[i]);
    }

    int ans = new_roads.size();
    if (new_roads.count(S)) ans--;

    cout << ans << '\n';


    return 0;
}