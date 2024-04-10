#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N; cin >> N;
    vector< vector<int> > edges(N);
    for (int i = 1; i < N; ++i) {
        int x, y; cin >> x >> y;
        --x; --y;
        edges[x].emplace_back(y);
        edges[y].emplace_back(x);
    }

    int answer = 0;
    for (auto &x : edges)
        answer = max(answer, int(x.size()) + 1);

    queue<int> Q;
    vector<int> color(N, 0);
    for (int i = 0; i < N; ++i)
        if (edges[i].size() > 1) {
            Q.push(i);
            color[i] = 1;
            break;
        }


    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();

        set<int> have;
        have.insert(color[x]);
        for (auto &y : edges[x])
            have.insert(color[y]);
        int start = 1;
        for (auto &y : edges[x])
            if (color[y] == 0) {
                Q.push(y);
                while (have.count(start))
                    ++start;
                color[y] = start++;
            }
    }

    cout << answer << "\n";
    for (auto &x : color)
        cout << x << " ";
    cout << "\n";
}