#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

void calcSums(const std::vector<int>& as,
              std::vector<int64_t>& sum,
              std::vector<int64_t>& conSum1,
              std::vector<int64_t>& conSum2) {
    int n = as.size();
    sum.resize(n + 1);
    conSum1.resize(n + 1);
    conSum2.resize(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        sum[i] = sum[i + 1] + as[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        conSum2[i] = conSum2[i + 1] + as[i] * int64_t(n - 1 - i);
    }
    for (int i = n - 1; i >= 0; i--) {
        conSum1[i] = conSum1[i + 1] + sum[i + 1];
    }
}

void run(std::istream &in, std::ostream &out) {
    int n;
    in >> n;
    std::vector<int> as(n);
    std::vector<int> bs(n);
    for (int i = 0; i < n; i++) {
        in >> as[i];
    }
    for (int i = 0; i < n; i++) {
        in >> bs[i];
    }
    std::vector<int64_t> sumA, conSumA1, conSumA2;
    std::vector<int64_t> sumB, conSumB1, conSumB2;
    calcSums(as, sumA, conSumA1, conSumA2);
    calcSums(bs, sumB, conSumB1, conSumB2);
    int64_t ans = 0;
    int64_t cur = 0;
    for (int i = 0; i < n; i++) {
        int64_t res = cur;
        res += int64_t(2 * i) * sumA[i];
        res += conSumA1[i];
        res += int64_t(2 * i + n - i) * sumB[i];
        res += conSumB2[i];
        ans = std::max(ans, res);
        cur += int64_t(2 * i) * as[i];
        cur += int64_t(2 * i + 1) * bs[i];
        as.swap(bs);
        sumA.swap(sumB);
        conSumA1.swap(conSumB1);
        conSumA2.swap(conSumB2);
    }
    ans = std::max(ans, cur);
    out << ans << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}