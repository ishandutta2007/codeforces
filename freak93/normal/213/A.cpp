#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solve(int s, vector<int> &C, vector< vector<int> > &E) {
    int N = C.size();
    queue<int> Q[3];

    vector<int> left(N);
    vector< vector<int> > A(N);

    for (int i = 0; i < N; ++i) {
        left[i] = E[i].size();
        for (auto it: E[i])
            A[it].push_back(i);

        if (left[i] == 0)
            Q[C[i]].push(i), left[i] = -1;
    }

    int steps = 0;
    while (!Q[0].empty() || !Q[1].empty() || !Q[2].empty()) {
        ++steps;
        if (Q[s].empty()) {
            s = (s + 1) % 3;
            continue;
        }
        int x = Q[s].front();
        Q[s].pop();
        for (auto it: A[x]) {
            if (--left[it] == 0) {
                left[it] = -1;
                Q[C[it]].push(it);
            }
        }
    }
    cerr << "->" << steps << "\n";
    return steps;
}

int main() {
    int N; cin >> N;
    vector<int> C(N);
    for (auto &it: C) {
        cin >> it;
        --it;
    }

    vector< vector<int> > E(N);
    for (auto &it: E) {
        int K; cin >> K;
        it.resize(K);
        for (auto &jt: it) {
            cin >> jt;
            --jt;
        }
    }

    cout << min(solve(1, C, E), min(solve(2, C, E), solve(0, C, E)));
}