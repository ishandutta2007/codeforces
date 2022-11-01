#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, a, b, color[MN], ans;
vector<int> adj[MN];

void dfs(int node, int parent) {
    int used = 1;

    for(int i=0;i<adj[node].size();i++) {
        int v = adj[node][i];
        if(v == parent) continue;

        if(color[node] == used || color[parent] == used) used++;
        if(color[node] == used || color[parent] == used) used++;

        ans = max(ans, used);   
        color[v] = used++;
        dfs(v, node);
    }
}

int main() {
    scanf("%d",&n);

    for(int i=1; i<n; i++) {
        scanf("%d %d",&a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    } color[1] = 1; dfs(1, -1);

    printf("%d\n", ans);
    for(int i=1;i<=n;i++) {
        printf("%d ", color[i]);
    }
    return 0;
}