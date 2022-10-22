#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N;
    string S;;
    cin >> N >> S;
    if (S.size() < 6)
        S.resize(6, '0');
    int P = 0;
    for (int i = 0; i < 6; ++i)
        if (i != 1)
            P = P * 10 + S[i] - '0';

    for (int K = 0; K <= N; ++K) {
        int64_t num = 1LL * K * (N - K) * (N - K - 1) / 2 + 2LL * K * (K - 1) * (N - K) / 2 + 1LL * K * (K - 1) * (K - 2) / 3;
        int64_t den = 1LL * N * (N - 1) * (N - 2) / 3;

        // check if num / den > P / 10000
        // num * 10000 > P * den 
        if (num * 10000LL >= 1LL * P * den) {
            cout << K << "\n";
            break;
        }
    }
}