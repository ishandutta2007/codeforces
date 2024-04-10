#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

struct Solution {
    int sy;
    int a, b;
    int n;
    std::vector<int> ls;
    std::vector<int> rs;
    std::vector<int> sums;

    int64_t getValue(int64_t value, int q) {
        if (value <= int64_t(ls[0]) * q) {
            return 0;
        }
        std::ptrdiff_t pos = std::upper_bound(ls.begin(), ls.end(), value, [q](const int64_t& value, const int& x) {
            return value < int64_t(x) * q;
        }) - ls.begin() - 1;
        if (value <= int64_t(rs[pos]) * q) {
            return int64_t(sums[pos]) * q + (value - int64_t(ls[pos]) * q);
        }
        return int64_t(sums[pos] + rs[pos] - ls[pos]) * q;
    }

    void run(std::istream& in, std::ostream& out) {
        in >> sy >> a >> b;
        in >> n;
        ls.resize(n);
        rs.resize(n);
        sums.resize(n);
        for (int i = 0; i < n; i++) {
            in >> ls[i] >> rs[i];
        }
        sums[0] = 0;
        for (int i = 1; i < n; i++) {
            sums[i] = sums[i - 1] + (rs[i - 1] - ls[i - 1]);
        }
        int q;
        in >> q;
        out.precision(10);
        for (int i = 0; i < q; i++) {
            int x, y;
            in >> x >> y;
            int qq = y - sy;
            int64_t left = int64_t(a) * y - int64_t(sy) * x;
            int64_t right = int64_t(b) * y - int64_t(sy) * x;

            int64_t leftValue = getValue(left, qq);
            int64_t rightValue = getValue(right, qq);
            double result = (rightValue - leftValue) / (double) y;
            out << result << "\n";
        }
    }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}