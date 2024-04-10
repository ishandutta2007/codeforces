#include <iostream>
#include <limits>

using namespace std;

const int kModulo = 1000000007;

int pow(int x, int y) {
    if (y == 0)
        return 1;

    if (y % 2)
        return (static_cast<int64_t>(pow(x, y - 1)) * x) % kModulo;

    int64_t answer = pow(x, y / 2);
    return (answer * answer) % kModulo;
}

int main() {
    int N, M, K; cin >> N >> M >> K;

    int left = numeric_limits<int>::max();
    int right = numeric_limits<int>::min();
    int many = 0;

    for (int i = 0; i < M; ++i) {
        int x, y; cin >> x >> y;
        if (y - x != 1 and y - x != K + 1) {
            cout << 0 << "\n";
            return 0;
        }

        if (y - x == K + 1) {
            left = min(left, x);
            right = max(right, x);
            ++many;
        }
    }

    // no special edges
    if (not many) {
        // for every position we have a power of 2
        int64_t answer = 1;
        for (int i = 1; i < N - K; ++i)
            answer += pow(2, min(N - K - i - 1, K));
        cout << answer % kModulo << "\n";
        return 0;
    }

    if (left + K + 1 <= right) {
        cout << 0 << "\n";
        return 0;
    }

    int64_t answer = 0;
    for (int i = 1; i < N - K; ++i)
        if (i + K + 1 > right and i <= left) {
            int total = min(N - K - i, K + 1);
            if (i != left)
                --total;
            answer += pow(2, total - many);
        }

    cout << answer % kModulo << "\n";
}