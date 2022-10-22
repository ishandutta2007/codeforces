#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> S(N);
        for (int i = 0; i < N; ++i)
            cin >> S[i];
        vector<int64_t> partial(N, 0);

        int64_t answer = 0;
        int64_t now = 0;
        for (int i = 0; i < N; ++i) {
            now += partial[i];

            int aux = now;
            if (aux < S[i] - 1) {
                answer += S[i] - 1 - aux;
                aux = S[i] - 1;
            }
            if (aux == 0)
                continue;
            if (i + 1 < N) {
                partial[i + 1] += aux - (S[i] - 1);
            }
            if (i + 2 < N) {
                partial[i + 2] -= aux - (S[i] - 1);
                partial[i + 2] += 1;
            }

            if (i + S[i] + 1 < N) {
                partial[i + S[i] + 1] -= 1;
            }
        }

        cout << answer << "\n";
    }
}