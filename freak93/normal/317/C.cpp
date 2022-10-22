#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>

using namespace std;

int main() {
    int N, V, E; cin >> N >> V >> E;

    vector<int> A(N + 1), B(N + 1);
    for (int i = 1; i <= N; ++i)
        cin >> A[i];
    for (int j = 1; j <= N; ++j)
        cin >> B[j];

    vector< vector<int> > next(N + 1, vector<int>(N + 1, 0));
    for (int i = 0; i < E; ++i) {
        int x, y; cin >> x >> y;
        next[x][y] = y;
        next[y][x] = x;
    }

    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                if (next[i][k] and next[k][j] and not next[i][j])
                    next[i][j] = next[i][k];

    vector< vector<int> > components;
    vector<int> type(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        if (type[i])
            continue;

        type[i] = components.size() + 1;
        vector<int> now(1, i);
        for (int j = 1; j <= N; ++j)
            if (next[i][j] and i != j) {
                type[j] = type[i];
                now.push_back(j);
            }

        components.push_back(now);
    }

    for (auto &group : components) {
        int64_t sum = 0;
        for (auto &who : group)
            sum += A[who] - B[who];

        if (sum != 0) {
            cout << "NO\n";
            return 0;
        }
    }

    vector< tuple<int, int, int> > answer;
    for (auto &group: components) {
        do {
            int lowest, highest;
            vector<int>::iterator lit, hit;
            tie(lit, hit) = minmax_element(group.begin(), group.end(), [&](int first, int second) {
                return A[first] - B[first] < A[second] - B[second];
            });

            lowest = *lit;
            highest = *hit;

            if (A[lowest] == B[lowest])
                break;

            vector<int> path;
            for (int i = highest; i != lowest; i = next[i][lowest])
                path.push_back(i);
            path.push_back(lowest);

            vector<int> balance(N + 1, 0);
            int need = min(B[lowest] - A[lowest], A[highest] - B[highest]);

            for (int i = 0; i < int(path.size()) - 1; ++i) {
                int adding = min(need, V - A[path[i + 1]]);
                balance[path[i]] -= adding;
                balance[path[i + 1]] += adding;
                A[path[i]] -= adding;
                A[path[i + 1]] += adding;
                if (adding > 0)
                    answer.push_back(make_tuple(path[i], path[i + 1], adding));
            }

           for (int i = path.size() - 2; i > 0; --i) {
 
                int adding = -balance[path[i]];
                assert(balance[path[i]] <= 0);
                A[path[i - 1]] -= adding;
                A[path[i]] += adding;
                balance[path[i - 1]] -= adding;
                if (adding > 0)
                    answer.push_back(make_tuple(path[i - 1], path[i], adding));
            }
        } while (true);
    }

    cout << answer.size() << "\n";

    for (auto &transfer : answer) {
        int x, y, d;
        tie(x, y, d) = transfer;

        cout << x << " " << y << " " << d << "\n";
    }
}