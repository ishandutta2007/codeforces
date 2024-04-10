#ifdef __GNUC__
#pragma GCC target("sse4,avx")
#endif
#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

void split(int p, std::vector<int>& pos, std::vector<int>& neg) {
    std::vector<int> ps;
    for (int i = 2; i * i <= p; i++) {
        if (p % i == 0) {
            ps.push_back(i);
            do {
                p /= i;
            } while (p % i == 0);
        }
    }
    if (p > 1) ps.push_back(p);
    for (int i = 0; i < 1 << ps.size(); i++) {
        int m = 1;
        bool flag = true;
        for (int j = 0; j < ps.size(); j++) {
            if (((i >> j) & 1) != 0) {
                m *= ps[j];
                flag = !flag;
            }
        }
        if (flag) {
            pos.push_back(m);
        } else {
            neg.push_back(m);
        }
    }
}

int coprime(int x, int middle, const std::vector<int>& pos, const std::vector<int>& neg) {
    int res = 0;
    for (int d : pos) {
        res += (middle / d) - (x / d);
    }
    for (int d : neg) {
        res -= (middle / d) - (x / d);
    }
    return res;
}

void run(std::istream &in, std::ostream &out) {
    int t;
    in >> t;
    for (int test = 0; test < t; test++) {
        int x, p, k;
        in >> x >> p >> k;
        int left = x;
        int right = x + 100 * k;
        std::vector<int> pos;
        std::vector<int> neg;
        split(p, pos, neg);
        while (right - left > 1) {
            int middle = (left + right) / 2;
            if (coprime(x, middle, pos, neg) < k) {
                left = middle;
            } else {
                right = middle;
            }
        }
        out << right << "\n";
    }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}