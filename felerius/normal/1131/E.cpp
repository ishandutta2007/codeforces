#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <optional>
#include <string>
#include <type_traits>
#include <unistd.h>
#include <vector>

using namespace std;

struct BeautifulRange {
    char c;
    uint32_t len;
};

struct BeautyInfo {
    BeautifulRange prefix;
    BeautifulRange suffix;
    bool full = false;
    array<uint32_t, 26> char_ranges = {0};
};


template <class Iter>
pair<Iter, BeautifulRange> scan_range(Iter begin, Iter end) {
    char c = *begin;
    uint32_t len = 0;
    while (begin != end && *begin == c) {
        len++;
        begin++;
    }

    return {begin, BeautifulRange{c, len}};
}

BeautyInfo string_beauty(const string_view& s) {
    BeautyInfo info;
    auto [prefix_it, prefix_range] = scan_range(s.begin(), s.end());
    info.prefix = prefix_range;
    if (prefix_it == s.end()) {
        info.suffix = info.prefix;
        info.full = true;
        info.char_ranges[info.prefix.c - 'a'] = info.prefix.len;
        return info;
    }

    info.suffix = scan_range(s.rbegin(), s.rend()).second;
    auto it = s.begin();
    while (it != s.end()) {
        auto [new_it, range] = scan_range(it, s.end());
        info.char_ranges[range.c - 'a'] = max(info.char_ranges[range.c - 'a'], range.len);
        it = new_it;
    }

    return info;
}

BeautyInfo multiply_beauty(const BeautyInfo& left, const BeautyInfo& right) {
    BeautyInfo info;
    if (left.full && right.full) {
        if (left.prefix.c == right.prefix.c) {
            info.full = true;
            info.prefix = info.suffix = BeautifulRange{left.prefix.c, left.prefix.len + (left.prefix.len + 1) * right.prefix.len};
            info.char_ranges[left.prefix.c - 'a'] = info.prefix.len;
            return info;
        }

        info.prefix = info.suffix = right.prefix;
        info.char_ranges[left.prefix.c - 'a'] = 1;
        info.char_ranges[right.prefix.c - 'a'] = right.prefix.len;
        return info;
    }

    if (right.full) {
        info.prefix = right.prefix;
        if (left.prefix.c == right.prefix.c) {
            info.prefix.len = (left.prefix.len + 1) * right.prefix.len + left.prefix.len;
        }
        info.suffix = right.prefix;
        if (left.suffix.c == right.prefix.c) {
            info.suffix.len = (left.suffix.len + 1) * right.prefix.len + left.suffix.len;
        }
    } else {
        info.prefix = right.prefix;
        info.suffix = right.suffix;
    }

    for (auto c = 'a'; c <= 'z'; ++c) {
        uint32_t len = 0;
        if (right.full && c == right.prefix.c) {
            auto left_len = left.char_ranges[c - 'a'];
            len = (left_len + 1) * right.prefix.len + left_len;
        } else {
            if (left.char_ranges[c - 'a'] > 0) {
                len = 1;
                if (right.prefix.c == c) {
                    len += right.prefix.len;
                }
                if (right.suffix.c == c) {
                    len += right.suffix.len;
                }
            }

            len = max(len, right.char_ranges[c - 'a']);
        }

        info.char_ranges[c - 'a'] = len;
    }

    return info;
}

int main() {
    ios_base::sync_with_stdio(false);

    size_t n;
    cin >> n;

    string s;
    cin >> s;
    BeautyInfo left = string_beauty(s);
    for (size_t i = 1; i < n; ++i) {
        cin >> s;
        left = multiply_beauty(left, string_beauty(s));
    }

    cout << *max_element(left.char_ranges.begin(), left.char_ranges.end()) << '\n';

    return 0;
}