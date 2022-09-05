#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

void run(std::istream &in, std::ostream &out) {
    int n, m;
    in >> n >> m;
    std::vector<int> as(n);
    for (int i = 0; i < n; i++) {
        in >> as[i];
    }
    if (n == 1) {
        out << as[0] % m << std::endl;
        return;
    }
    int n1 = n / 2;
    int n2 = n - n / 2;
    std::vector<int> sums1(1 << n1);
    std::vector<int> sums2(1 << n2);
    for (int i = 1; i < (1 << n1); i++) {
        int j = __builtin_ctz(i);
        sums1[i]  = (sums1[i - (1 << j)] + as[j]) % m;
    }
    for (int i = 1; i < (1 << n2); i++) {
        int j = __builtin_ctz(i);
        sums2[i] = (sums2[i - (1 << j)] + as[j + n1]) % m;
    }
    std::sort(sums1.begin(), sums1.end());
    std::sort(sums2.begin(), sums2.end());
    int ans = 0;
    int i2 = sums2.size() - 1;
    for (int i1 = 0; i1 < sums1.size(); i1++) {
        while (i2 > 0 && sums1[i1] + sums2[i2] >= m) i2--;
        ans = std::max(ans, (sums1[i1] + sums2[i2]) % m);
    }
    out << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}