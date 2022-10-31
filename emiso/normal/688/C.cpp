#include <bits/stdc++.h>

#define N 100100

using namespace std;

int visit[N], color[N];
vector<int> adj[N],group[2];

int dfs(int node, int c = 0) {
    if(visit[node]) return 1;

    visit[node] = 1;
    color[node] = c;

    for(int i=0;i<adj[node].size();i++) {
        int v = adj[node][i];

        if(!visit[v]) {
            if (dfs(v,c^1) == 0) return 0;
        }

        else if(color[v] == color[node])
            return 0;
    }

    return 1;
}

int main() {
    int n,m, flag = 1,u,v;

    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++) {
        scanf("%d %d",&u,&v);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1;i<=n;i++) {
        if(!visit[i] && dfs(i) == 0){
            flag = 0;
            break;
        }
    }

    if(!flag) printf("-1\n");

    else {
        for(int i=1;i<=n;i++)
            group[color[i]].push_back(i);

        printf("%d\n",group[0].size());
        for(int i=0;i<group[0].size();i++) {
            printf("%d%c",group[0][i],(i+1 == group[0].size())?'\n':' ');
        }

        printf("%d\n",group[1].size());
        for(int i=0;i<group[1].size();i++) {
            printf("%d%c",group[1][i],(i+1 == group[1].size())?'\n':' ');
        }
    }

    return 0;
}