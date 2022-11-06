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

struct State {
    int cs_before = 0;
    int count = 0;

    State() {}
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int n, c;
    cin >> n >> c;

    vector<int> nums(n);
    int total_cs = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        total_cs += nums[i] == c;
    }

    vector<State> states(500001);
    int seen_cs = 0;
    int best = total_cs;

    for (int i = 0; i < n; ++i) {
        auto a = nums[i];
        if (a == c) {
            seen_cs++;
        } else {
            states[a].count++;
            if (seen_cs - states[a].cs_before >= states[a].count) {
                states[a].count = 1;
                states[a].cs_before = seen_cs;
            }

            best = max(best, states[a].count + states[a].cs_before + total_cs - seen_cs);
        }
    }

    cout << best << '\n';

    return 0;
}