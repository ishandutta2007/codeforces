#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

int64_t f1(int all, int64_t x, int64_t d, int digits) {
    if (digits == 0 || x == 0 || all == 0) {
        return 1;
    }
    int sum = 1;
    int res1 = 1;
    for (int i = 0; i < all - 1; i++) {
        res1 *= digits - i - 1;
        res1 /= i + 1;
        res1 *= 9;
        sum += res1;
    }
    int64_t res = x >= d ? ((x / d - 1) * sum) : 0;
    res1 *= digits - all;
    res1 /= all;
    res1 *= 9;
    sum += res1;
    if (x >= d) {
        res += sum;
    }

    return res + f1(x >= d ? (all - 1) : all, x % d, d / 10, digits - 1);
}

int64_t f(int64_t x) {
    int64_t d = 1;
    int64_t c = x;
    int digits = 1;
    while (c >= 10) {
        c /= 10;
        d *= 10;
        digits++;
    }
    return f1(3, x, d, digits);
}

int nndigits(int64_t x) {
    int res = 0;
    while (x > 0) {
        if (x % 10 != 0) {
            res++;
        }
        x /= 10;
    }
    return res;
}

void run(std::istream& in, std::ostream& out) {
    /*int prev = 0;
    for (int i = 0; i < 10000000; i++) {
        int next = f(i);
        if (nndigits(i) <= 3) {
            if (next != prev + 1) {
                out << "Problem1: " <<  i << "\n";
                break;
            }
        } else {
            if (next != prev) {
                out << "Problem2: " << i << "\n";
                break;
            }
        }
        prev = next;
    }
    out << "Finish" << std::endl; */
    int q;
    in >> q;
    for (int test = 0; test < q; test++) {
        int64_t L, R;
        in >> L >> R;
        out << (f(R) - f(L - 1)) << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}