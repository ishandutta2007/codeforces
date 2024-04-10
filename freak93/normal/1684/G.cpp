#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Matching {
    Matching(int n, int m): edges(n), left(n, -1), right(m, -1), used(n, false) {}

    void add_edge(int x, int y) {
        edges[x].emplace_back(y);
    }

    bool match() {
        if (left.empty())
            return true;
        bool matched;
        do {
            matched = false;
            fill(used.begin(), used.end(), false);
            for (int i = 0; i < int(left.size()); ++i)
                if (left[i] == -1)
                    matched |= go(i);
        } while (matched);

        return *min_element(left.begin(), left.end()) != -1;
    }

    bool go(int node) {
        if (used[node])
            return false;
        used[node] = true;

        for (auto &x : edges[node])
            if (right[x] == -1) {
                right[x] = node;
                left[node] = x;
                return true;;
            }

        for (auto &x : edges[node])
            if (go(right[x])) {
                right[x] = node;
                left[node] = x;
                return true;
            }
        return false;
    }

    vector< vector<int> > edges;
    vector<int> left, right;
    vector<bool> used;
};

int main() {
    ios::sync_with_stdio(false);

    int N, M; cin >> N >> M;

    vector<int> T(N);
    for (int i = 0; i < N; ++i)
        cin >> T[i];

    vector<int> left, right;
    for (auto &x : T)
        if (3LL * x <= M)
            right.push_back(x);
        else
            left.push_back(x);

    Matching Match(left.size(), right.size());
    for (int i = 0; i < int(left.size()); ++i)
        for (int j = 0; j < int(right.size()); ++j)
            if (left[i] % right[j] == 0 && 2LL * left[i] + 1LL * right[j] <= M)
                Match.add_edge(i, j);

    if (!Match.match()) {
        cout << "-1\n";
        return 0;
    }

    vector< pair<int, int> > answer;
    for (int i = 0; i < int(left.size()); ++i)
        answer.emplace_back(2 * left[i] + right[Match.left[i]], left[i] + right[Match.left[i]]);

    for (int i = 0; i < int(right.size()); ++i)
        if (Match.right[i] == -1)
            answer.emplace_back(3 * right[i], 2 * right[i]);

    cout << answer.size() << "\n";
    for (auto &p : answer)
        cout << p.first << " " << p.second << "\n";
}