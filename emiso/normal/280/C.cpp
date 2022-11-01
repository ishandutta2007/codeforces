#include <bits/stdc++.h>

#define MN 100010

using namespace std;

int n;
double sum;
vector<int> adj[MN];

void dfs(int no, int dep, int p = -1) {
    sum += (1.0 / dep);
    for(int v : adj[no])
        if(v != p)
            dfs(v, dep + 1, no);
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 1);

    printf("%.9f\n", sum);
    return 0;
}