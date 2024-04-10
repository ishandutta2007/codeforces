#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N; cin >> N;

    vector<int64_t> S(N);
    for (int i = 0; i < N; ++i)
        cin >> S[i];

    S.emplace_back(1LL << 62);
    sort(S.begin(), S.end());
    vector<int64_t> diffs;
    for (int i = 0; i < N; ++i)
        diffs.emplace_back(S[i + 1] - S[i]);
    sort(diffs.begin(), diffs.end());

    vector<int64_t> partial(N);
    for (int i = 0; i < N; ++i) {
        partial[i] = diffs[i];
        if (i > 0)
            partial[i] += partial[i - 1];
    }

    int Q; cin >> Q;
    while (Q--) {
        int64_t L, R; cin >> L >> R;
        int64_t W = R - L + 1;

        int lower = lower_bound(diffs.begin(), diffs.end(), W) - diffs.begin();

        int64_t answer = 0;
        if (lower != 0)
            answer += partial[lower - 1];
        answer += W * (N - lower);
        cout << answer << "\n";
    }
}