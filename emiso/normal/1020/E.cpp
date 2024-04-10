#include <bits/stdc++.h>
#define MN 1000100

using namespace std;

vector<int> adj[MN], adjr[MN], ans;
int n, m, a, b, used[MN], resp[MN];

void solve(int node) {
    if(!node) return;
    if(used[node]) {
        solve(node-1);
        return;
    }

    used[node] = 1;
    for(int v : adj[node])
        used[v] = 1;
    solve(node-1);

    int flag = 0;
    for(int v : adjr[node]) {
        if(resp[v] == 1) {
            flag = 1;
            break;
        }
    }

    if(!flag) {
        resp[node] = 1;
        ans.push_back(node);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adjr[b].push_back(a);
    }

    solve(n);

    printf("%d\n", ans.size());
    for(int x : ans) {
        printf("%d ", x);
    } puts("");
    return 0;
}