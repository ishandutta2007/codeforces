#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    int N, D; cin >> N >> D;

    vector<int> A(N, 0);
    for (int i = 1; i < N - 1; ++i)
        cin >> A[i];

    vector<int> X(N), Y(N);
    for (int i = 0; i < N; ++i)
        cin >> X[i] >> Y[i];

    vector< vector<int> > cost(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) 
            if (i != j)
                cost[i][j] = (max(X[i] - X[j], X[j] - X[i]) + max(Y[i] - Y[j], Y[j] - Y[i])) * D - A[i];

    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);

    cout << cost[0][N - 1] << "\n";
}