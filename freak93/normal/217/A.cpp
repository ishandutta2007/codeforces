#include <iostream>
#include <vector>

using namespace std;

void bfs(int x, vector<int> &X, vector<int> &Y, vector<int> &passed) {
    passed[x] = 1;
    for (int i = 0; i < int(X.size()); ++i)
        if (X[i] == X[x] || Y[i] == Y[x])
            if (passed[i] == 0)
                bfs(i, X, Y, passed);
}

int main() {
    int N; cin >> N;
    vector<int> X(N), Y(N);

    for (int i = 0; i < N; ++i)
        cin >> X[i] >> Y[i];

    vector<int> passed(N, 0);
    int teams = 0;
    for (int i = 0; i < N; ++i)
        if (passed[i] == 0) {
            ++teams;
            bfs(i, X, Y, passed);
        }
    
    cout << teams - 1 << "\n";
}