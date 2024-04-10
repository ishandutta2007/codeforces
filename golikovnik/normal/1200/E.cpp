#include <bits/stdc++.h>

std::vector<std::size_t> prefix_function(std::string const& s) {
    auto n = s.size();
    std::vector<std::size_t> p(n);
    for (std::size_t i = 1; i < n; ++i) {
        auto cur = p[i - 1];
        while (cur && s[i] != s[cur]) {
            cur = p[cur - 1];
        }
        p[i] = cur + (s[i] == s[cur]);
    }
    return p;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::size_t n;
    std::cin >> n;
    std::string answer{};
    while (n--) {
        std::string s;
        std::cin >> s;
        auto suff_len = std::min(s.size(), answer.size());
        std::string to_test = s + "#" + answer.substr(answer.size() - suff_len);
        auto p = prefix_function(to_test);
        auto odd = p.back();
        std::copy(s.begin() + odd, s.end(), std::back_inserter(answer));
    }
    std::cout << answer << '\n';
    return 0;
}