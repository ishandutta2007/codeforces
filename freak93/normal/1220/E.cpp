#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int64_t dfs(int node, const vector<int> &parent, const vector<int> &score, vector<int64_t> &best) {
    if (best[node] >= 0)
        return best[node];
    if (parent[node] == -1)
        return 0;
    best[node] = score[node] + dfs(parent[node], parent, score, best);
    return best[node];
}

int main() {
    ios::sync_with_stdio(false);

    int N, M; cin >> N >> M;

    vector<set<int>> edges(N);
    vector<int> score(N);
    for (int i = 0; i < N; ++i)
        cin >> score[i];

    for (int i = 0; i < M; ++i) {
        int x, y; cin >> x >> y;
        --x; --y;
        edges[x].emplace(y);
        edges[y].emplace(x);
    }

    int source; cin >> source;
    --source;

    queue<int> leafs;
    for (int i = 0; i < N; ++i) {
        if (edges[i].size() == 1 && i != source)
            leafs.push(i);
    }

    vector<int> parent(N, -1);
    while (!leafs.empty()) {
        int node = leafs.front();
        leafs.pop();

        parent[node] = *edges[node].begin();
        edges[node].clear();
        edges[parent[node]].erase(node);

        if (edges[parent[node]].size() == 1 && parent[node] != source)
            leafs.push(parent[node]);
    }

    vector<int64_t> best(N, -1);
    int64_t answer = 0, component = 0;
    for (int i = 0; i < N; ++i)
        if (parent[i] == -1)
            component += score[i];
        else
            answer = max(answer, dfs(i, parent, score, best));

    cout << answer + component << "\n";
}