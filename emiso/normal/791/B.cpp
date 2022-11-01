#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, m, a, b, flag = 1, visit[MN][2], count_;
vector<int> adj[MN];

void dfs(int node, int check, int t) {
    if(visit[node][t]) return;
    visit[node][t] = 1;
    count_++;
    int sz = adj[node].size();

    if(check != -1 && sz != check) {
        flag = 0;
        return;
    }

    for(int i=0;i<sz;i++) {
        int u = adj[node][i];
        dfs(u, sz, t);
    }
}

int main() {
    scanf("%d %d",&n, &m);

    for(int i=0; i<m; i++) {
        scanf("%d %d",&a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1;i<=n;i++) {
        if(!visit[i][0]) {
            int co = count_;
            dfs(i, -1, 0);
            int comp = count_ - co;
            dfs(i, comp - 1, 1);
        }
    }

    printf("%s\n", flag ? "YES" : "NO");
    return 0;
}