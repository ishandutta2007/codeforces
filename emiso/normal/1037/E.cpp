#include <bits/stdc++.h>

#define MN 201000

using namespace std;
typedef long long ll;

int n, m, k, a[MN], b[MN], deg[MN], nope[MN], ans;
vector<int> adj[MN];

void limpa(int node, int dim = 0) {
    if(nope[node]) return;
    if(dim) ans--;
    nope[node] = 1;
    for(int v : adj[node]) {
        deg[v]--;
        if(deg[v] + 1 == k) limpa(v, dim);
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &k);

    for(int i = 0; i < m; i++) {
        scanf("%d %d", &a[i], &b[i]);
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
        deg[a[i]]++;
        deg[b[i]]++;
    }

    for(int i = 1; i <= n; i++) {
        if(!nope[i] && deg[i] < k) limpa(i);
    }

    for(int i = 1; i <= n; i++) {
        if(!nope[i]) ans++;
    }

    stack<int> resp;

    for(int i = m-1; i >= 0; i--) {
        resp.push(ans);

        if(nope[a[i]] || nope[b[i]]) {
            adj[a[i]].pop_back();
            adj[b[i]].pop_back();
            continue;
        }

        deg[a[i]]--;
        if(deg[a[i]] < k) limpa(a[i], 1);
        else deg[b[i]]--;

        if(deg[b[i]] < k) {
            deg[a[i]]++;
            limpa(b[i], 1);
        }

        adj[a[i]].pop_back();
        adj[b[i]].pop_back();
    }

    while(!resp.empty()) {
        printf("%d\n", resp.top());
        resp.pop();
    }

    // if k == 1...
    return 0;
}