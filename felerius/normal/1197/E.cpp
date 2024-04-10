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

constexpr static uint32_t MOD = 1e9 + 7;

vector<pair<int, uint32_t>> best;
vector<pair<int, uint32_t>> best_self;
size_t cur_idx = 0;
int cur_out;
int cur_best = 1'000'000'001;
uint32_t cur_count = 0;

void update_best() {
    best_self[cur_idx] = {cur_best, cur_count};
    auto cur_neg = cur_best - cur_out;
    if (cur_idx == 0) {
        best[cur_idx] = {cur_neg, cur_count};
        return;
    }

    best[cur_idx] = best[cur_idx - 1];
    if (cur_neg < best[cur_idx].first) {
        best[cur_idx] = {cur_neg, cur_count};
    } else if (cur_neg == best[cur_idx].first) {
        best[cur_idx].second = (best[cur_idx].second + cur_count) % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);

    size_t n;
    cin >> n;

    vector<pair<int, int>> d(n);
    int max_inner = 0;
    for (size_t i = 0; i < n; ++i) {
        cin >> d[i].first >> d[i].second;
        max_inner = max(max_inner, d[i].second);
    }

    sort(begin(d), end(d));
    vector<int> out(n);
    for (size_t i = 0; i < n; ++i) {
        out[n - 1 - i] = d[i].first;
    }
    auto last = unique(begin(out), end(out));
    out.erase(last, end(out));

    best.resize(out.size());
    best_self.resize(out.size());
    cur_out = d[0].first;
    for (auto [o, i] : d) {
        if (o != cur_out) {
            update_best();
            cur_idx++;
            cur_out = o;
            cur_best = 1'000'000'001;
        }

        int wasted = i;
        uint32_t count = 1;
        auto it = lower_bound(begin(out), end(out), i, greater{});
        if (it != end(out)) {
            size_t inner_out_idx = out.size() - 1 - (it - begin(out));
            auto [neg, c] = best[inner_out_idx];
            wasted = i + neg;
            count = c;
        }

        if (wasted < cur_best) {
            cur_best = wasted;
            cur_count = count;
        } else if (wasted == cur_best) {
            cur_count = (cur_count + count) % MOD;
        }
    }

    update_best();

    uint32_t total_count = 0;
    int least_wasted = 1'000'000'001;
    for (size_t i = 0; out[i] > max_inner; ++i) {
        auto [wasted, count] = best_self[out.size() - 1 - i];
        if (wasted < least_wasted) {
            least_wasted = wasted;
            total_count = count;
        } else if (wasted == least_wasted) {
            total_count = (total_count + count) % MOD;
        }
    }

    cout << total_count << '\n';

    return 0;
}