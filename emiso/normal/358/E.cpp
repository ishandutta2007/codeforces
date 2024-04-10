#include <bits/stdc++.h>

using namespace std;

struct union_find {
    vector<int> parent, rank_;
    union_find(int n) { init(n); }
    void init(int n) {
        parent.resize(n + 1); rank_.resize(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int node) {
        if(node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }
    bool join(int a, int b) {
        a = find(a); b = find(b);
        if(a == b) return false;
        if(rank_[a] < rank_[b]) swap(a, b);
        parent[b] = a;
        rank_[a] += rank_[b];
        return true;
    }
};

int n, m, g[1010][1010], deg[1010][1010], mini = INT_MAX;
vector<pair<int, int>> no;
set<int> ro, co;
vector<int> row[1010], col[1010], adj[1000100];

int id(int i, int j) {
    return (i-1)*m + j-1;
}

int main() {
    int comp = 0;
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf("%d", &g[i][j]);
            comp += g[i][j];
        }
    }

    union_find dsu(1000100);

    int odd = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(!g[i][j]) continue;
            if(g[i-1][j] && dsu.join(id(i, j), id(i-1, j))) comp--;
            if(g[i+1][j] && dsu.join(id(i, j), id(i+1, j))) comp--;
            if(g[i][j-1] && dsu.join(id(i, j), id(i, j-1))) comp--;
            if(g[i][j+1] && dsu.join(id(i, j), id(i, j+1))) comp--;

            deg[i][j] = g[i-1][j] + g[i+1][j] + g[i][j-1] + g[i][j+1];
            odd += (deg[i][j] % 2);
            if(deg[i][j] != 2 || g[i-1][j] + g[i+1][j] == 1) {
                ro.insert(i);
                co.insert(j);
                row[i].push_back(j);
                col[j].push_back(i);
            }
        }
    }

    int last = 0;
    for(int x : ro) {
        if(last) mini = min(mini, x - last);
        last = x;
    }
    last = 0;
    for(int x : co) {
        if(last) mini = min(mini, x - last);
        last = x;
    }

    for(int i = 1; i <= n; i++) {
        for(int k = 0; k < row[i].size(); k++) {
            int j = row[i][k];
            if(g[i][j-1]) adj[id(i, j)].push_back(id(i, row[i][k-1]));
            if(g[i][j+1]) adj[id(i, j)].push_back(id(i, row[i][k+1]));
        }
    }
    for(int i = 1; i <= m; i++) {
        for(int k = 0; k < col[i].size(); k++) {
            int j = col[i][k];
            if(g[j-1][i]) adj[id(j, i)].push_back(id(col[i][k-1], i));
            if(g[j+1][i]) adj[id(j, i)].push_back(id(col[i][k+1], i));
        }
    }

    if(odd != 0 && odd != 2) {
        puts("-1");
        return 0;
    }
    if(comp > 1) {
        puts("-1");
        return 0;
    }
    if(mini == 1 || mini == INT_MAX) {
        puts("-1");
        return 0;
    }

    for(int i = 2; i <= mini; i++) {
        if(mini % i == 0) printf("%d ", i);
    }
    return 0;
}