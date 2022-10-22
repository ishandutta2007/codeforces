#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int next;
    int skip;
    int depth = 0;
    int cost_next = 0;
    int cost_skip = 0;
};

int main() {
    ios::sync_with_stdio(false);

    int N; cin >> N;
    vector<int> L(N);
    vector<int> P(N);
    for (int i = 0; i < N; ++i)
        cin >> P[i] >> L[i];

    vector<int> stack;
    vector<Node> data(N + 1, Node{N, N});
    vector<int> reach(N);
    for (int i = N - 1; i >= 0; --i) {
        reach[i] = P[i] + L[i];
        while (!stack.empty() && reach[i] >= P[stack.back()]) {
            reach[i] = max(reach[i], reach[stack.back()]);
            stack.pop_back();
        }
        int next = N;
        int cost = 0;
        if (!stack.empty()) {
            next = stack.back();
            cost = P[stack.back()] - reach[i];
        }
        stack.push_back(i);
        data[i] = Node{
            next,
            next,
            data[next].depth + 1,
            cost,
            cost, 
        };
        int mid = data[next].skip;
        if (data[next].depth + data[data[mid].skip].depth == 2 * data[mid].depth) {
            data[i].skip = data[mid].skip;
            data[i].cost_skip = cost + data[next].cost_skip + data[mid].cost_skip;
        }
    }

    int Q; cin >> Q;
    while (Q--) {
        int from, to; cin >> from >> to;
        --from; --to;

        int answer = 0;
        while (from < to) {
            if (data[from].skip <= to) {
                answer += data[from].cost_skip;
                from = data[from].skip;
            } else if (data[from].next <= to) {
                answer += data[from].cost_next;
                from = data[from].next;
            } else {
                break;
            }
        }

        cout << answer << "\n";
    }
}