#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static const int kModulo = 1000 * 1000 * 1000 + 7;

int main() {
    ios::sync_with_stdio(false);

    int N, K;
    int64_t L;
    cin >> N >> L >> K;

    if (K == 1) {
        cout << L % kModulo << "\n";
        return 0;
    }

    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    auto B = A;
    sort(B.begin(), B.end());

    vector<int> total(N, 0);
    for (int i = 0; i < N; ++i)
        total[i] = i + 1;

    int64_t parts = L / N;
    if (L % N)
        ++parts;

    int lastCount = L % N;
    if (lastCount == 0)
        lastCount = N;

    int answer = L % kModulo;
    for (int i = 2; i <= K; ++i) {
        if (i > parts)
            break;
        vector<int> now(N, 0);
        for (int j = 0; j < N; ++j) {
            auto where = upper_bound(B.begin(), B.end(), B[j]) - B.begin() - 1;
            now[j] = (now[j] + total[where]) % kModulo;
            if (j > 0)
                now[j] = (now[j] + now[j - 1]) % kModulo;
        }
        int lastPart = 0;
        for (int j = 0; j < lastCount; ++j) {
            auto where = upper_bound(B.begin(), B.end(), A[j]) - B.begin() - 1;
            lastPart = (lastPart + total[where]) % kModulo;
        }

        int currentParts = now.back();
        int aux = (1LL * ((parts - i) % kModulo) * currentParts + lastPart) % kModulo;

        answer = (answer + aux) % kModulo;
        swap(now, total);
    }

    cout << answer << "\n";
}