#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T; cin >> T;

    while (T--) {
        int N, M; cin >> N >> M;

        vector<int> P(N);
        for (int i = 0; i < N; ++i) {
            cin >> P[i];
            --P[i];
        }

        vector<int> good(N, 0);
        for (int i = 0; i < N; ++i)
            good[(i - P[i] + N) % N]++;

        vector<int> answer;
        vector<bool> used(N);
        for (int i = 0; i < N; ++i)
            if (M * 2 + good[i] >= N) {
                rotate(P.begin(), P.begin() + i, P.end());

                fill(used.begin(), used.end(), false);
                int need = 0;
                for (int j = 0; j < N; ++j)
                    if (P[j] != j) {
                        used[j] = true;
                        int k = P[j];
                        while (!used[k]) {
                            used[k] = true;
                            k = P[k];
                            ++need;
                        }
                    }
                if (need <= M) {
                    answer.push_back(i);
                }
                rotate(P.begin(), P.begin() + N - i, P.end());
            }
        cout << answer.size();
        for (auto &x : answer)
            cout << " " << x;
        cout << "\n";
    }
}