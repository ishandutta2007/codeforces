#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N; cin >> N;
    vector<int> V(N);
    for (int i = 0; i < N; ++i)
        cin >> V[i];

    int best = 1;
    for (int i = 0; i < N; ++i)
        for (int j = 1; i + j <= N; j *= 2) {
            bool is_sorted = true;
            for (int k = i + 1; k < i + j; ++k)
                if (V[k - 1] > V[k])
                    is_sorted = false;
            if (is_sorted)
                best = max(best, j);
            if (j & i)
                break;
        }

    cout << best << "\n";
}