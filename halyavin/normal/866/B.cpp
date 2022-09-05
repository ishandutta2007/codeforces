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

int64_t getDiff(const std::vector<std::pair<int64_t, int64_t>>& diff, int64_t slices) {
    int64_t res = 0;
    for (const auto& diffVariant : diff) {
        int64_t transfer = std::min(slices, diffVariant.second);
        res += transfer * diffVariant.first;
        slices -= transfer;
    }
    return res;
}

void run(std::istream &in, std::ostream &out) {
    int64_t N, S;
    in >> N >> S;
    std::vector<int64_t> s(N), a(N), b(N);
    for (int i = 0; i < N; i++) {
        in >> s[i] >> a[i] >> b[i];
    }
    int64_t total = std::accumulate(s.begin(), s.end(), int64_t(0));
    int64_t slices = (total + S - 1) / S;
    std::vector<std::pair<int64_t, int64_t>> adiff;
    std::vector<std::pair<int64_t, int64_t>> bdiff;
    int64_t sum = 0;
    int64_t sumA = 0;
    int64_t sumB = 0;
    for (int i = 0; i < N; i++) {
        if (a[i] > b[i]) {
            sum += a[i] * s[i];
            sumA += s[i];
            adiff.emplace_back(a[i] - b[i], s[i]);
        } else {
            sum += b[i] * s[i];
            sumB += s[i];
            bdiff.emplace_back(b[i] - a[i], s[i]);
        }
    }
    int64_t slicesA = (sumA + S - 1) / S;
    int64_t slicesB = (sumB + S - 1) / S;
    if (slicesA + slicesB == slices) {
        out << sum << std::endl;
        return;
    }
    std::sort(adiff.begin(), adiff.end());
    std::sort(bdiff.begin(), bdiff.end());
    int64_t diff = std::min(getDiff(adiff, sumA % S), getDiff(bdiff, sumB % S));
    out << sum - diff << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}