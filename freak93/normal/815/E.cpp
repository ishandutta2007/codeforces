#include <iostream>
#include <map>

using namespace std;

int64_t many(int64_t diff, int64_t limit) {
    map<int64_t, int64_t> have;
    have[diff] = 1;

    int64_t total = 0;
    while (!have.empty()) {
        auto [x, y] = *have.rbegin();
        have.erase(x);

        if ((x + 1) / 2 < limit) {
            return total;
        }
        total += y;
        if (x / 2 > 0)
            have[x / 2] += y;
        if (x - x / 2 - 1 > 0)
            have[x -x / 2 - 1] += y;
    }

    return total;
}

int main() {
    int64_t N, K; cin >> N >> K;

    if (K == 1) {
        cout << 1 << "\n";
        return 0;
    }
    if (K == 2) {
        cout << N << "\n";
        return 0;
    }

    K -= 2;

    int64_t step;
    for (step = 1; step < N; step <<= 1);
    int64_t diff = N;
    for (; step; step >>= 1)
        if (many(N - 2, diff - step) < K)
            diff -= step;

    diff--;

    int64_t begin = 1;
    int64_t end = N;
    while (end - begin > 1) {
        int64_t mid = (begin + end) / 2;
        if (K == 1) {
            cout << mid << "\n";
            return 0;
        }

        --K;
        auto right = many(end - mid - 1, diff + 1);
        auto left = many(mid - begin - 1, diff);
        if (left + right < K) {
            K -= left;
            begin = mid;
        } else {
            K -= right;
            end = mid;
        }
    }

    cout << (begin + end) / 2 << "\n";
}