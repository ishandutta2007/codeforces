#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N, K; cin >> N >> K;

    int answer = 1, rank = 0;
    while (answer < N) {
        answer *= K;
        ++rank;
    }

    vector< vector<int> > list(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0, x = i; j < rank; ++j, x /= K)
            list[i].push_back(x % K);
    }

    vector< vector<int> > colors(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = i + 1; j < N; ++j)
            for (int k = 0; k < rank; ++k)
                if (list[i][k] < list[j][k]) {
                    colors[i][j] = k;
                    break;
                }

    cout << rank << "\n";
    for (int i = 0; i < N; ++i)
        for (int j = i + 1; j < N; ++j)
            cout << colors[i][j] + 1 << " ";
    cout << "\n";
}