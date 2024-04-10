#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N, M; cin >> N >> M;

    vector<int> row(N, 0), col(M, 0);
    for (int mat = 0; mat < 2; ++mat)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j) {
                int x; cin >> x;
                row[i] ^= x;
                col[j] ^= x;
            }
    if (row == vector<int>(N, 0) && col == vector<int>(M, 0))
        cout << "Yes\n";
    else
        cout << "No\n";
}