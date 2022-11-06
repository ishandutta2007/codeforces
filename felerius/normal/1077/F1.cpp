#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <numeric>
#include <string>
#include <type_traits>
#include <unistd.h>
#include <unordered_set>
#include <vector>


using namespace std;

struct Heap {
    vector<pair<uint64_t, size_t>> data;
    vector<size_t> indices;

    Heap(size_t k) : data(k), indices(k) {
        reset();
    }

    void reset() {
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] = {0, i};
            indices[i] = i;
        }
    }

    uint64_t max() {
        return data.front().first;
    }

    void replace(size_t i, uint64_t val) {
        size_t k = indices.size();
        auto idx = indices[i % k];
        auto old_val = data[idx].first;
        data[idx] = pair(val, i % k);
        if (val < old_val) {
            while (idx < k / 2) {
                auto child_idx = 2 * idx + 1;
                if (child_idx + 1 < k && data[child_idx + 1] > data[child_idx]) {
                    child_idx++;
                }

                if (data[idx] < data[child_idx]) {
                    swap(indices[data[idx].second], indices[data[child_idx].second]);
                    swap(data[idx], data[child_idx]);
                    idx = child_idx;
                } else {
                    break;
                }
            }
        } else {
            while (idx != 0) {
                auto parent_idx = (idx - 1) / 2;
                if (data[idx] > data[parent_idx]) {
                    swap(indices[data[idx].second], indices[data[parent_idx].second]);
                    swap(data[idx], data[parent_idx]);
                    idx = parent_idx;
                } else {
                    break;
                }
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);

    size_t n, k, x;
    cin >> n >> k >> x;

    if (n >= (x + 1) * k) {
        cout << "-1\n";
        return 0;
    }

    vector<uint32_t> a(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<uint64_t> cur_dp(n);
    vector<uint64_t> last_dp(n);
    Heap heap(k);
    for (size_t i = 0; i < x; ++i) {
        heap.reset();
        for (size_t j = 0; j < min(n, (i + 1) * k); ++j) {
            cur_dp[j] = a[j] + heap.max();
            heap.replace(j, last_dp[j]);
        }

//        for (auto c : cur_dp) {
//            cout << c << ' ';
//        }
//        cout << '\n';
        swap(cur_dp, last_dp);
    }

    cout << *max_element(last_dp.rbegin(), last_dp.rbegin() + k) << '\n';

    return 0;
}