#include <iostream>

using namespace std;

int main() {
    int N, K; cin >> N >> K;
    if (N * (N - 1) / 2 <= K) {
        cout << "no solution\n";
        return 0;
    }

    for (int i = 0; i < N; ++i)
        cout << "0 " << i << "\n";
}