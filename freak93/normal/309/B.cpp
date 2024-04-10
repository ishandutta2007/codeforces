#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N, R, C; cin >> N >> R >> C;

    vector<string> S(N);
    for (int i = 0; i < N; ++i)
        cin >> S[i];

    int p = -1;
    int total = 0;

    vector< vector<int> > next(32, vector<int>(N + 1, N));

    for (int i = 0; i < N; ++i) {
        if (p <= i) {
            p = i;
            total = 0;
        } else {
            total -= S[i - 1].size() + 1;
        }

        while (p < N and total + int(total > 0) + int(S[p].size()) <= C) {
            total += S[p].size() + int(total > 0);
            ++p;
        }

        next[0][i] = p;
    }

    for (int i = 1; i < 32; ++i)
        for (int j = 0; j < N; ++j)
            next[i][j] = next[i - 1][next[i - 1][j]];

    int answer = -1, where = -1;
    for (int i = 0; i < N; ++i) {
        int k = i;
        for (int j = 0; j < 31; ++j)
            if ((1 << j) & R)
                k = next[j][k];

        if (k - i > answer) {
            answer = k - i;
            where = i;
        }
    }

    total = 0;
    for (int i = where; i < where + answer; ++i) {
        if (total + int(S[i].size()) + int(total > 0) > C) {
            cout << "\n";
            total = 0;
        }

        if (total > 0)
            cout << " ";
        cout << S[i];
        total += S[i].size() + int(total > 0);
    }

    cout << "\n";
}