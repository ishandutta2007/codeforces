#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>
#include <tuple>

using namespace std;

static const int kSpecial = 20;

enum class EdgeChange {
    Deleted,
    Added,
};

void dfs(int node, const vector< vector<int> > &edges, vector<bool> &used, vector<int> &order) {
    if (used[node])
        return;
    used[node] = true;
    for (auto &x : edges[node])
        dfs(x, edges, used, order);
    order.push_back(node);
}

int main() {
    ios::sync_with_stdio(false);

    int N, M, T; cin >> N >> M >> T;

    vector< vector<int> > edges(N);
    set< pair<int, int> > edge_set;
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        edges[a - 1].emplace_back(b - 1);
        edge_set.emplace(a - 1, b - 1);
    }

    vector<bool> used(N, false);
    vector<int> special;
    for (int i = 0; i < N; ++i)
        dfs(i, edges, used, special);

    if (N > kSpecial)
        special.resize(kSpecial);

    int S = special.size();
    vector< tuple<EdgeChange, int, int> > edge_changes;
    vector<bool> is_special(N, false);
    for (int i = 0; i < S; ++i) {
        is_special[special[i]] = true;
        for (int j = 0; j < i; ++j)
            if (!edge_set.count(pair{special[i], special[j]}))
                edge_changes.emplace_back(EdgeChange::Added, special[i], special[j]);
    }

    vector< pair<int, int> > diffs;
    for (int i = 0; i < (1 << S); ++i) {
        int bits = 0;
        for (int j = 0; j < S; ++j)
            if ((1 << j) & i)
                ++bits;
        if (bits <= 3)
            diffs.emplace_back(bits, i);
    }
    sort(diffs.begin(), diffs.end());

    vector<int> taken(1 << S, -1);
    for (int i = 0; i < N; ++i) {
        if (is_special[i])
            continue;
        edge_changes.emplace_back(EdgeChange::Added, i, i);
        int now = 0;
        for (int j = 0; j < S; ++j)
            if (edge_set.count(pair{i, special[j]}))
                now |= (1 << j);

        int change = 0;
        while (taken[now ^ diffs[change].second] != -1) {
            ++change;
        }

        change = diffs[change].second;
        for (int j = 0; j < S; ++j)
            if ((1 << j) & change) {
                if ((1 << j) & now)
                    edge_changes.emplace_back(EdgeChange::Deleted, i, special[j]);
                else 
                    edge_changes.emplace_back(EdgeChange::Added, i, special[j]);
            }
        now ^= change;
        taken[now] = i;
    }

    cout << edge_changes.size() << "\n";
    for (auto t : edge_changes) {
        EdgeChange type; int a, b;
        tie(type, a, b) = t;
        if (type == EdgeChange::Added)
            cout << "+ ";
        else 
            cout << "- ";
        cout << a + 1 << " " << b + 1 << "\n";
    }

    cout.flush();
    for (int test = 0; test < T; ++test) {
        int now = 0;
        int found = -1;

        for (int j = 0; j < S; ++j) {
            cout << "? 1 " << special[j] + 1 << endl;
            string result; cin >> result;
            if (result == "Lose") {
                found = special[j];
                break;
            }
            if (result == "Win")
                now |= (1 << j);
        }
        if (found == -1) {
            found = taken[now];
        }
        assert(found != -1);
        cout << "! " << found + 1 << endl;
        string answer; cin >> answer;
        assert(answer == "Correct");
    }
}