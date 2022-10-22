#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N, M, K; cin >> N >> M >> K;
    vector<string> S(N);
    for (int i = 0; i < N; ++i)
        cin >> S[i];

    vector<int> answer(M, 0);

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (S[i][j] == 'U') {
                if (i % 2 == 0)
                    ++answer[j];
            } else if (S[i][j] == 'L') {
                int newj = j - i;
                if (newj >= 0)
                    ++answer[newj];
            } else if (S[i][j] == 'R') {
                int newj = j + i;
                if (newj < M)
                    ++answer[newj];
            }

    for (int i = 0; i < M; ++i)
        cout << answer[i] << " ";
    cout << "\n";
}