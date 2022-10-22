#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T; cin >> T;
    while (T--) {
        int N, K; cin >> N >> K;
        vector<int> A(N);
        for (int i = 0; i < N; ++i)
            cin >> A[i];

        int64_t total = 0;
        for (auto &x : A)
            total += x;

        for (int i = 0; i < N; ++i)
            A[i] = -A[i] + N - i - 1;
        sort(A.begin(), A.end());
        for (int i = 0; i < K; ++i)
            total += A[i];
        total -= 1LL * K * (K - 1) / 2;
        cout << total << "\n";
    }
}