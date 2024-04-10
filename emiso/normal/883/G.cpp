#include <bits/stdc++.h>
#define MN 300300

using namespace std;

int n, m, s, a, b, t, num, visit[MN], quant, q1, q2;
vector<int> adj[MN], ori1, ori2;
vector<pair<int, int> > bidi[MN], bi;

void dfs(int node) {
    if(visit[node]) return;
    visit[node] = true;
    q2++;

    for(int i = 0; i < adj[node].size(); i++)
        dfs(adj[node][i]);
}

void dfs_da_verdade(int node) {
    visit[node] = true;
    q1++;

    for(int i = 0; i < adj[node].size(); i++) {
        int v = adj[node][i];
        if(!visit[v]) dfs_da_verdade(v);
    }

    for(int i = 0; i < bidi[node].size(); i++) {
        int v = bidi[node][i].first;
        int id = bidi[node][i].second;

        if(!visit[v]) {
            if(bi[id].first == node) ori1[id] = 0;
            else ori1[id] = 1;
            dfs_da_verdade(v);
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &s);
    for(int i = 0; i < m ; i++) {
        scanf("%d %d %d", &t, &a, &b);
        if(t == 1) {
            adj[a].push_back(b);
        }

        else {
            bidi[a].push_back({b, num});
            bidi[b].push_back({a, num++});
            bi.push_back({a, b});
        }
    }

    dfs(s);

    for(int i = 0; i < num; i++) {
        a = bi[i].first;
        b = bi[i].second;
        if(!visit[a] && visit[b]) ori2.push_back(0);
        else ori2.push_back(1);
    }

    ori1.resize(num);
    memset(visit, 0, sizeof visit);
    dfs_da_verdade(s);

    printf("%d\n", q1);
    for(int i = 0; i < num; i++) {
        printf("%c", (ori1[i]) ? '-' : '+');
    }

    printf("\n%d\n", q2);
    for(int i = 0; i < num; i++) {
        printf("%c", (ori2[i]) ? '-' : '+');
    } puts("");

    return 0;
}