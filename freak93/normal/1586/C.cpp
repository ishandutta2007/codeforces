#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N, M; cin >> N >> M;

    vector<string> S(N);
    for (int i = 0; i < N; ++i)
        cin >> S[i];

    vector<int> bad(M, 0);
    for (int i = 1; i < N; ++i)
        for (int j = 1; j < M; ++j)
            if (S[i - 1][j] == 'X' && S[i][j - 1] == 'X')
                bad[j]++;

    for (int i = 1; i < M; ++i)
        bad[i] += bad[i - 1];

    int Q; cin >> Q;

    while (Q--) {
        int x1, x2; cin >> x1 >> x2;
        --x1; --x2;

        if (bad[x2] - bad[x1] > 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}