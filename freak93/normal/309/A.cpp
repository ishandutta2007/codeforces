#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, L, T; cin >> N >> L >> T;
    L *= 2;
    T *= 2;

    vector<long long> A(N * 2);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        A[i] *= 2;
        A[i + N] = A[i] + L;
    }
    int p = 0;
    long long answer = 0;

    int all = T / (L / 2);
    T %= (L / 2);

    for (int i = 0; i < N; ++i) {
        answer += 1LL * all * (N - 1);
        while (p < i + N and A[p] <= A[i] + 2 * T)
            ++p;
        answer += (p - i - 1);
    }

    cout << answer / 4 << "." << (answer % 4) * 25;
}