#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, const vector< vector<int> > &edges, vector<bool> &used) {
    used[node] = true;

    for (auto &x : edges[node]) {
        if (used[x])
            continue;
        dfs(x, edges, used);
    }
}

int main() {
    ios::sync_with_stdio(false);

    int T; cin >> T;

    while (T--) {
        int N, M; cin >> N >> M;

        vector<bool> bad(N, false);

        for (int i = 0; i < M; ++i) {
            int a, b, c; cin >> a >> b >> c;
            bad[b - 1] = true;
        }

        for (int i = 0; i < N; ++i) {
            if (!bad[i]) {
                for (int j = 0; j < N; ++j)
                    if (j != i)
                        cout << i + 1 << " " << j + 1 << "\n";
                break;
            }
        }
    }
}