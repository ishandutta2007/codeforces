#include <bits/stdc++.h>

#define MN 101000

using namespace std;
typedef long long ll;

int n, ans[MN], p, sz[MN], f[MN];
vector<int> adj[MN];

int dfs(int no, int pai = -1) {
    for(int v : adj[no])
        if(v != pai)
            sz[no] += dfs(v, no);
    if(!sz[no]) sz[no]++;

    f[sz[no]]++;
    return sz[no];
}

int main() {
    scanf("%d", &n);

    for(int i = 2; i <= n; i++) {
        scanf("%d", &p);
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    dfs(1);

    int cont = 1, sum = 0;
    for(int i = 1; i <= n; i++) {
        while(sum < i) sum += f[cont++];
        ans[i] = cont - 1;
    }

    for(int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    return 0;
}