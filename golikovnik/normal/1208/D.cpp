#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::size_t n;
    std::cin >> n;
    std::vector<std::uint64_t> s(n);
    for (auto& x : s) {
        std::cin >> x;
    }
    std::vector<std::uint64_t> fenw(n);
    auto add = [&fenw, n](auto at, auto x) {
        while (at < n) {
            fenw[at] += x;
            at |= at + 1;
        }
    };
    auto pref = [&fenw, n](auto r) -> std::uint64_t {
        if (!r) {
            return 0;
        }
        std::uint64_t result = 0;
        --r;
        while (true) {
            result += fenw[r];
            r &= r + 1;
            if (!r) {
                break;
            }
            --r;
        }
        return result;
    };
    for (std::size_t i = 0; i != n; ++i) {
        add(i, i + 1);
    }
    std::reverse(s.begin(), s.end());
    std::vector<std::size_t> result;
    result.reserve(n);
    for (auto x : s) {
        std::size_t left = 0;
        std::size_t right = n;
        while (left + 1 != right) {
            auto middle = (left + right) / 2;
            if (pref(middle) <= x) {
                left = middle;
            } else {
                right = middle;
            }
        }
        assert(pref(left) == x);
        result.push_back(left + 1);
        add(left, -static_cast<int>(left) - 1);
    }
    std::reverse(result.begin(), result.end());
    for (auto x : result) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
    return 0;
}