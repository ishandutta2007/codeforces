#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T; cin >> T;
    queue<int> Q[3];

    while (T--) {
        int N; cin >> N;
        vector<int> color(N);
        for (int i = 0; i < N; ++i)
            cin >> color[i];

        vector< vector<int> > edges(N);
        for (int i = 1; i < N; ++i) {
            int x, y; cin >> x >> y;
            --x; --y;
            edges[x].emplace_back(y);
            edges[y].emplace_back(x);
        }

        if (N == 1) {
            cout << 1 << "\n";
            continue;
        }

        int answer = N;
        vector<int> degree(N);
        for (int start = 1; start < 3; ++start) {
            for (int i = 0; i < N; ++i) {
                degree[i] = edges[i].size();
                if (degree[i] == 1)
                    Q[color[i]].push(i);
            }

            int aux = 0;
            for (int i = start; !Q[0].empty() || !Q[1].empty() || !Q[2].empty(); i ^= 3) {
                aux++;
                while (!Q[i].empty() || !Q[0].empty()) {
                    int node;
                    if (Q[i].empty()) {
                        node = Q[0].front();
                        Q[0].pop();
                    } else {
                        node = Q[i].front();
                        Q[i].pop();
                    }
                    for (auto &x : edges[node]) 
                        if (--degree[x] == 1)
                            Q[color[x]].push(x);
                }
            }
            answer = min(answer, aux);
        }

        cout << answer << "\n";
    }
}