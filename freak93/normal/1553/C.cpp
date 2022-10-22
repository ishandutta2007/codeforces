#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T; cin >> T;

    while (T--) {
        string S; cin >> S;
        int answer = 9;
        for (int i = 0; i < 2; ++i) {
            int score[2] = {0, 0};
            int max_score[2] = {5, 5};

            for (int j = 0; j < 10; ++j) {
                if (S[j] == '1' || (S[j] == '?' && j % 2 == i)) {
                    ++score[j % 2];
                } else {
                    --max_score[j % 2];
                }
                if (score[0] > max_score[1] || score[1] > max_score[0])
                    answer = min(answer, j);
            }
        }
        cout << answer + 1 << "\n";
    }
}