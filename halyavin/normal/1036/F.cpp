#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <cmath>
#include <array>

std::vector<std::vector<int64_t>> tables;

int64_t root(int64_t x, int deg) {
    if (tables[deg].size() > 0) {
        for (int i = tables[deg].size(); i-- > 0;) {
            if (tables[deg][i] <= x) {
                return i;
            }
        }
    }
    double app = exp(log(x) / deg);
    int64_t y = ceil(app) + 1;
    while (true) {
        int64_t cx = x;
        for (int i = 0; i < deg; i++) {
            cx /= y;
        }
        if (cx == 0) {
            y--;
        } else {
            break;
        }
    }

    return y;
}

std::array<int, 61> flags;

int64_t f(int64_t x) {
    int64_t res = x - 1;
    for (int d = 2; d <= 60; d++) {
        if (flags[d] == 0) continue;
        int64_t v = root(x, d);
        res -= flags[d] * (v - 1);
    }
    return res;
}

void run(std::istream& in, std::ostream& out) {
    for (int d = 2; d <= 60; d++) {
        int coeff = -1;
        for (int i = 2; i * i <= d; i++) {
            if (d % (i * i) == 0) {
                coeff = 0;
            }
        }
        if (coeff == 0) continue;
        int cd = d;
        for (int i = 2; cd > 1; i++) {
            if (cd % i == 0) {
                coeff = -coeff;
                cd /= i;
            }
        }
        flags[d] = coeff;
    }
    tables.resize(61);
    for (int d = 12; d <= 60; d++) {
        int64_t limit = 1000000000;
        limit = limit * limit + 1;
        tables[d].push_back(0);
        for (int i = 1; ; i++) {
            int64_t cl = limit;
            for (int j = 0; j < d; j++) {
                cl /= i;
            }
            if (cl == 0) break;
            int64_t xx = 1;
            for (int j = 0; j < d; j++) {
                xx *= i;
            }
            tables[d].push_back(xx);
        }
    }
    int q;
    in >> q;
    //q = 100000;
    for (int test = 0; test < q; test++) {
        int64_t n;
        in >> n;
        //n = 1000000000000000000LL;
        //f(n);
        out << f(n) << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}