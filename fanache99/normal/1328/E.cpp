#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 200000;

vector<int> g[1 + MAXN];
int v[1 + MAXN], first[1 + MAXN], last[1 + MAXN], counter = 0, depth[1 + MAXN], dad[1 + MAXN];

void DFS(int node, int father) {
    dad[node] = father;
    depth[node] = depth[father] + 1;
    counter++;
    first[node] = counter;
    for (auto &son : g[node])
        if (son != father)
            DFS(son, node);
    last[node] = counter;
}

bool IsAncestor(int a, int b) {
    return first[a] <= first[b] && last[b] <= last[a];
}

bool Solve(int n, int k) {
    int which = 0;
    for (int i = 1; i <= k; i++)
        if (depth[v[i]] > depth[which])
            which = v[i];
    for (int i = 1; i <= k; i++)
        if (!IsAncestor(v[i], which) && !IsAncestor(dad[v[i]], which))
            return false;
    return true;
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    DFS(1, 0);
    for (int i = 1; i <= q; i++) {
        int k;
        cin >> k;
        for (int i = 1; i <= k; i++)
            cin >> v[i];
        if (Solve(n, k))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}