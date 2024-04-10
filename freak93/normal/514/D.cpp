#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N, M, K; cin >> N >> M >> K;

    vector< vector<int> > A(N, vector<int>(M, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> A[i][j];

    int to = 0;
    vector< deque<int> > D(M);
    auto shots = [&]() {
        int total = 0;
        for (int i = 0; i < M; ++i) {
            if (D[i].size() == 0)
                continue;
            total += A[D[i].front()][i];
        }
        return total;
    };

    int answer = 0;
    vector<int> how(M, 0);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j)
            while (D[j].size() && D[j].front() < i)
                D[j].pop_front();
        while (to <= N && shots() <= K) {
            if (to - i > answer) {
                answer = to - i;
                for (int j = 0; j < M; ++j)
                    if (!D[j].size())
                        how[j] = 0;
                    else
                        how[j] = A[D[j].front()][j];
            }
            if (to == N)
                break;

            for (int j = 0; j < M; ++j) {
                while (D[j].size() && A[D[j].back()][j] <= A[to][j])
                    D[j].pop_back();
                D[j].push_back(to);
            }
            ++to;
        }
    }
    for (int j = 0; j < M; ++j)
        cout << how[j] << " ";
    cout << "\n";
}