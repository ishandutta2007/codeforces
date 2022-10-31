#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>

#define MOD 1000000007
#define MN 100101

using namespace std;

int dfs_idx=1, scc_count, n, m, c[MN],u,v;

vector<int> dfs_low(MN), dfs_num(MN,-1), visit(MN),adj[MN],scc[MN];
stack<int> S;

void tarjan_scc(int node) {
    dfs_low[node] = dfs_num[node] = dfs_idx++;
    S.push(node);
    visit[node] = 1;

    for(int i=0; i<adj[node].size();i++) {
        int v = adj[node][i];

        if(dfs_num[v] == -1)
            tarjan_scc(v);

        if(visit[v])
            dfs_low[node] = min(dfs_low[node], dfs_low[v]);
    }
    if(dfs_low[node] == dfs_num[node]) {
        while(1) {
            int v = S.top();
            S.pop();
            visit[v] = 0;

            dfs_low[v] = min(dfs_low[v], dfs_low[node]);
            scc[scc_count].push_back(c[v]);

            if(node == v) break;
        }
        scc_count++;
    }
}

int main() {

    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&c[i]);
    }

    scanf("%d",&m);
    for(int i=0;i<m;i++) {
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
    }

    for(int i=1;i<=n;i++)
        if(dfs_num[i] == -1)
            tarjan_scc(i);

    long long ans = 0, num = 1;

    for(int i=0;i<scc_count;i++) {
        sort(scc[i].begin(),scc[i].end());

        long long aux = 1;

        ans += scc[i][0];
        for(int j=1;j<scc[i].size();j++) {
            if(scc[i][j] == scc[i][j-1]) aux++;
            else break;
        }
        num = (num * aux%MOD)%MOD;
    }

    printf("%lld %lld\n",ans,num);

    return 0;
}