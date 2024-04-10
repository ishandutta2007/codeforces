#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N; cin >> N;

    vector<int> V(N);
    for (int i = 0; i < N; ++i)
        cin >> V[i];

    vector<int> P(N);
    for (int i = 0; i < N; ++i)
        P[i] = i;
    sort(P.begin(), P.end(), [&](int x, int y) {
        return V[x] < V[y];
    });

    // first third
    vector<int> A(N), B(N);
    for (int i = 0; i < (N + 2) / 3; ++i) {
        A[P[i]] = i;
        B[P[i]] = V[P[i]] - A[P[i]];
    }

    for (int i = (N + 2) / 3; i < (N * 2 + 2) / 3; ++i) {
        B[P[i]] = i;
        A[P[i]] = V[P[i]] - B[P[i]];
    }

    for (int i = (N * 2 + 2) / 3, value = (N + 2) / 3 - 1; i < N; ++i, --value) {
        B[P[i]] = value;
        A[P[i]] = V[P[i]] - B[P[i]];
    }

    cout << "YES\n";
    for (int i = 0; i < N; ++i)
        cout << A[i] << " ";
    cout << "\n";
    for (int j = 0; j < N; ++j)
        cout << B[j] << " ";
    cout << "\n";
}