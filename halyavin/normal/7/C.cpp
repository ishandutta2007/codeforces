#include <iostream>
#include <cstdint>
#include <utility>
#include <algorithm>

const std::pair<int64_t, int64_t> bad {1LL << 62, 1LL << 62};

std::pair<int64_t, int64_t> get_point(int64_t a, int64_t b, int64_t c) {
    if (a < 0) {
        auto result = get_point(-a, b, c);
        if (result == bad) return bad;
        result.first = -result.first;
        return result;
    }
    if (b < 0) {
        auto result = get_point(a, -b, c);
        if (result == bad) return bad;
        result.second = -result.second;
        return result;
    }
    if (a == 0) {
        if (c % b == 0) {
            return std::make_pair(0, -c / b);
        }
        return bad;
    }
    if (b == 0) {
        if (c % a == 0) {
            return std::make_pair(-c /a, 0);
        }
        return bad;
    }
    if (b >= a) {
        auto result = get_point(a, b%a, c);
        if (result == bad) return bad;
        result.first -= b / a * result.second;
        return result;
    } else {
        auto result = get_point(b, a, c);
        std::swap(result.first, result.second);
        return result;
    }
}

void run(std::istream& in, std::ostream& out) {
    int a, b, c;
    in >> a >> b >> c;
    auto result = get_point(a, b, c);
    if (result == bad) {
        out << -1 << std::endl;
    } else {
        out << result.first << " " << result.second << std::endl;
    }
}

int main() {
    run(std::cin, std::cout);
    return 0;
}