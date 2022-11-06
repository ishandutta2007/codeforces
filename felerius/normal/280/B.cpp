#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <numeric>
#include <optional>
#include <string>
#include <tuple>
#include <vector>

// Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
// Problem: (26) Maximum Xor Secondary (Difficulty: 4) (http://codeforces.com/problemset/problem/280/B)

using namespace std;

template <class It>
uint32_t evaluate(It it, It it_end) {
    vector<uint32_t> stack = {*it++};
    uint32_t best = 0;
    for (; it != it_end; ++it) {
        auto val = *it;
        while (!stack.empty() && stack.back() <= val) {
            stack.pop_back();
        }

        auto bit_width = sizeof(unsigned long long) * 8 - __builtin_clzll(val);
        auto inverse = ~val & ((1u << bit_width) - 1);
        auto stack_it = lower_bound(begin(stack), end(stack), inverse, greater{});
        if (stack_it != end(stack)) {
            best = max(best, *stack_it ^ val);
        }
        if (stack_it != begin(stack)) {
            best = max(best, *(stack_it - 1) ^ val);
        }

        stack.emplace_back(val);
    }

    return best;
}

int main() {
    ios::sync_with_stdio(false);

    size_t n; cin >> n;
    vector<uint32_t> a(n);
    for (auto& ai : a) cin >> ai;

    cout << max(evaluate(begin(a), end(a)), evaluate(rbegin(a), rend(a))) << '\n';

    return 0;
}