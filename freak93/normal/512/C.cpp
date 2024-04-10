#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

void dfs(int node, const vector< vector<int> > &E, vector<bool> &used, vector<int> &aux) {
    aux.push_back(node);
    used[node] = true;
    for (auto &x : E[node])
        if (!used[x])
            dfs(x, E, used, aux);
}

bool go(int node, const vector< vector<int> > &E, vector<bool> &used, vector<int> &mL, vector<int> &mR) {
    if (used[node])
        return false;
    used[node] = true;
    for (auto &x : E[node])
        if (mR[x] == -1) {
            mL[node] = x;
            mR[x] = node;
            return true;
        }
    for (auto &x : E[node])
        if (go(mR[x], E, used, mL, mR)) {
            mL[node] = x;
            mR[x] = node;
            return true;
        }
    return false;
}

int main() {
    int N; cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    vector< vector<int> > E(N + 2);
    vector< vector<int> > C(N + 2, vector<int>(N + 2, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            int number = A[i] + A[j];
            bool prime = true;
            for (int k = 2; k * k <= number; ++k)
                if (number % k == 0)
                    prime = false;
            if (prime && A[i] % 2 == 0 && A[j] % 2 == 1) {
                E[i].push_back(j);
                E[j].push_back(i);
                C[i][j] = 1;
            }
        }

    for (int i = 0; i < N; ++i)
        if (A[i] % 2 == 0) {
            E[N].push_back(i);
            E[i].push_back(N);
            C[N][i] = 2;
        } else {
            E[i].push_back(N + 1);
            E[N + 1].push_back(i);
            C[i][N + 1] = 2;
        }

    int flow = 0;
    vector< vector<int> > F(N + 2, vector<int>(N + 2, 0));
    vector<int> father(N + 2);

    auto bfs = [&]() -> bool {
        for (int i = 0; i < N + 2; ++i)
            father[i] = -1;
        father[N] = N;
        queue<int> Q;
        Q.push(N);
        while (!Q.empty()) {
            int node = Q.front();
            Q.pop();
            for (auto &x : E[node])
                if (father[x] == -1 && F[node][x] < C[node][x]) {
                    father[x] = node;
                    Q.push(x);
                }
        }
        return father[N + 1] != -1;
    };

    while (bfs()) {
        int currentFlow = numeric_limits<int>::max();
        for (int i = N + 1; i != N; i = father[i])
            currentFlow = min(currentFlow, C[father[i]][i] - F[father[i]][i]);

        flow += currentFlow;
        for (int i = N + 1; i != N; i = father[i]) {
            F[father[i]][i] += currentFlow;
            F[i][father[i]] -= currentFlow;
        }
    }

    if (flow != N) {
        cout << "Impossible\n";
        return 0;
    }

    vector< vector<int> > realE(N);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (F[i][j] == 1) {
                realE[i].push_back(j);
                realE[j].push_back(i);
            }


    vector< vector<int> > answer;
    vector<bool> used(A.size(), false);
    for (int i = 0; i < int(A.size()); ++i)
        if (!used[i]) {
            vector<int> aux;
            dfs(i, realE, used, aux);
            answer.push_back(aux);
        }
    cout << answer.size() << "\n";
    for (auto &a : answer) {
        cout << a.size() << " ";
        for (auto &x : a)
            cout << x + 1 << " ";
        cout << "\n";
    }
}