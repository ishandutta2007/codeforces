#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <string>
#include <type_traits>
#include <unistd.h>
#include <vector>


using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);

    size_t n;
    cin >> n;

    std::vector<size_t> parents(n);
    std::vector<std::vector<size_t>> children(n);
    for (size_t i = 1; i < n; i++) {
        cin >> parents[i];
        parents[i]--;
        children[parents[i]].emplace_back(i);
    }

    std::vector<int32_t> path_weights(n);
    for (size_t i = 0; i < n; i++) {
        cin >> path_weights[i];
    }

    std::vector<int32_t> weights(n);
    weights[0] = path_weights[0];
    for (size_t i = 0; i < n; i++) {
        if (path_weights[i] != -1) {
            continue;
        }

        if (children[i].empty()) {
            weights[i] = 0;
        } else {
            auto child_min = numeric_limits<int32_t>::max();
            for (auto ci : children[i]) {
                child_min = min(child_min, path_weights[ci]);
            }

            auto parent_weight = path_weights[parents[i]];
            if (child_min < parent_weight) {
                cout << "-1\n";
                return 0;
            }

            weights[i] = child_min - parent_weight;
            for (auto ci : children[i]) {
                weights[ci] = path_weights[ci] - weights[i] - parent_weight;
            }
        }
    }

    auto sum = accumulate(weights.begin(), weights.end(), (int64_t)0);
    cout << sum << '\n';

    return 0;
}